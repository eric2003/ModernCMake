#include <tcl.h>
#include "mycgio.h"
#include <string.h>

static int cgioNum = 0;
static double RootID = 0.0;

static int CGIOversion (ClientData data, Tcl_Interp *interp,
    int argc, char **argv)
{
    char version[CGIO_MAX_VERSION_LENGTH+1];

    Tcl_ResetResult (interp);
    if (argc != 1) {
        Tcl_AppendResult (interp, "wrong # args: should be \"",
            argv[0], "\"", NULL);
        return TCL_ERROR;
    }

    if (cgioNum > 0) {
        strcpy ( version, "1.0" ) ;
        int lversion = (int)strlen ( version ) ;
        version[lversion-1] = '\0' ; /** remove trailing "what" delimiter ('>') **/		
        //if (cgio_library_version (cgioNum, version))
          //  return (get_error (interp, "cgio_library_version"));
        Tcl_AppendResult (interp, version, NULL);
    }
    return TCL_OK;
}

/*---------- CGNSfile --------------------------------------------------
 * detect file type
 *----------------------------------------------------------------------*/

static int CGNSfile(ClientData data, Tcl_Interp* interp,
    int argc, char** argv)
{
    int file_type;

    Tcl_ResetResult(interp);
    {
        Tcl_AppendResult(interp, "static int CGNSfile\n", TCL_STATIC);
        char buf[100];
        sprintf(buf, "argc = %d\n", argc);
        Tcl_AppendResult(interp, buf, TCL_STATIC);
        for (int i = 0; i < argc; ++i)
        {
            sprintf(buf, "i = %d\n", i);
            Tcl_AppendResult(interp, buf, TCL_STATIC);
            Tcl_AppendResult(interp, argv[i], TCL_STATIC);
            sprintf(buf, "\n");
            Tcl_AppendResult(interp, buf, TCL_STATIC);
        }

        //MessageBox(NULL, Tcl_GetStringResult(interp), "Error in Wish",
        //    MB_ICONSTOP | MB_OK | MB_TASKMODAL | MB_SETFOREGROUND);
    }

    if (argc != 2) {
        Tcl_AppendResult(interp, "wrong # args: should be \"",
            argv[0], " filename\"", NULL);
        return TCL_ERROR;
    }
    int flag = cgio_check_file(argv[1], &file_type);
    {
        char buf[100];
        sprintf(buf, "flag = %d\n", flag);
        Tcl_AppendResult(interp, buf, TCL_STATIC);
        sprintf(buf, "file_type = %d\n", file_type);
        Tcl_AppendResult(interp, buf, TCL_STATIC);

        MessageBox(NULL, Tcl_GetStringResult(interp), "Error in Wish",
            MB_ICONSTOP | MB_OK | MB_TASKMODAL | MB_SETFOREGROUND);
    }
    if (flag)
        return (get_error(interp, "cgio_check_file"));
    if (file_type == CGIO_FILE_ADF)
        Tcl_SetResult(interp, "adf", TCL_STATIC);
    else if (file_type == CGIO_FILE_HDF5)
        Tcl_SetResult(interp, "hdf5", TCL_STATIC);
    else {
        //Tcl_SetResult (interp, "unknown file type", TCL_STATIC);
        /*
        FILE* pFile;
        pFile = fopen("myfile.txt", "w");
        if (pFile != NULL)
        {
            fputs("fopen example", pFile);
            //fprintf(pFile, "file_type = %d\n", file_type);
            fclose(pFile);
        }
        */
        //char buf[100];
        //sprintf(buf, "argc = %d\n", argc);
        //Tcl_AppendResult(interp, buf, TCL_STATIC);
        //for (int i = 0; i < argc; ++i)
        //{
        //    sprintf(buf, "i = %d\n", i);
        //    Tcl_AppendResult(interp, buf, TCL_STATIC);
        //    Tcl_AppendResult(interp, argv[i], TCL_STATIC);
        //    sprintf(buf, "\n");
        //    Tcl_AppendResult(interp, buf, TCL_STATIC);
        //}
        //
        //sprintf(buf, "file_type = %d\n", file_type);
        //Tcl_AppendResult(interp, buf, TCL_STATIC);

        Tcl_AppendResult(interp, "unknown file type 123456", TCL_STATIC);
        Tcl_AppendResult(interp, "unknown file type 7890", TCL_STATIC);

        return TCL_ERROR;
    }
    return TCL_OK;
}


int CGIOtcl_Init(Tcl_Interp *interp)
{
    char cgio_version[CGIO_MAX_VERSION_LENGTH+1];
	strcpy ( cgio_version, "CGIOversion" ) ;
    int lversion = (int)strlen ( cgio_version ) ;
    cgio_version[lversion-1] = '\0' ; /** remove trailing "what" delimiter ('>') **/		
	
    Tcl_CreateCommand (interp, "CGIOversion", (Tcl_CmdProc *)CGIOversion,
        (ClientData)0, (Tcl_CmdDeleteProc *)0);
    //Tcl_CreateCommand (interp, "CGNSversion", (Tcl_CmdProc *)CGNSversion,
    //    (ClientData)0, (Tcl_CmdDeleteProc *)0);
    //Tcl_CreateCommand (interp, "CGNSfile", (Tcl_CmdProc *)CGNSfile,
        //(ClientData)0, (Tcl_CmdDeleteProc *)0);
    return TCL_OK;
}
