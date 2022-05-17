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
