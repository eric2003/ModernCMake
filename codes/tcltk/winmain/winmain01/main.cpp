#include <windows.h>
#include <tk.h>
#include <tkInt.h>
#include "mycgio.h"

static HINSTANCE myInstance;

typedef struct TkWmInfo {
    TkWindow* winPtr;
    HWND hwnd;
} WmInfo;

static int Proc_LoadIcon(ClientData data, Tcl_Interp *interp,
    int argc, char **argv)
{
    TkWindow *winPtr;
    HANDLE hIcon;
    HWND hwnd = NULL;

    if (2 != argc) {
	Tcl_AppendResult(interp, "wrong # args: should be \"",
	    argv[0], " iconname\"", (char *) NULL);
        return TCL_ERROR;
    }

    winPtr = (TkWindow *) Tk_MainWindow (interp);
    if (NULL != winPtr && NULL != winPtr->wmInfoPtr)
        hwnd = winPtr->wmInfoPtr->hwnd;
    if (!hwnd) {
        Tcl_SetResult (interp,
            "toplevel window has not been created/mapped", TCL_STATIC);
        return TCL_ERROR;
    }
    if (argv[1][0] == '@')
        hIcon = LoadImage (NULL, &argv[1][1], IMAGE_ICON, 0, 0,
            LR_DEFAULTSIZE | LR_LOADFROMFILE);
    else
        hIcon = (HANDLE) LoadIcon (myInstance, argv[1]);
    if (!hIcon) {
        //Tcl_SetResult (interp, "icon not found", TCL_STATIC);
		Tcl_SetResult (interp, (char *)("icon not found"), TCL_STATIC);
        return TCL_ERROR;
    }
    SetClassLongPtr (hwnd, GCLP_HICON, (LONG_PTR)hIcon);
    Tcl_ResetResult (interp);
    return TCL_OK;
}

int
Tcl_AppInit(Tcl_Interp *interp)
{
    if (Tcl_Init(interp) == TCL_ERROR) {
	goto error;
    }
    if (Tk_Init(interp) == TCL_ERROR) {
	goto error;
    }
    Tcl_StaticPackage(interp, "Tk", Tk_Init, Tk_SafeInit);

    if (CGIOtcl_Init(interp) == TCL_ERROR)
        goto error;
#ifdef USE_HTMLHELP
    if (WinHtml_Init(interp) == TCL_ERROR)
        goto error;
#endif
    Tcl_CreateCommand (interp, "LoadIcon", (Tcl_CmdProc *)Proc_LoadIcon,
        (ClientData)0, (Tcl_CmdDeleteProc *)0);

    Tcl_SetVar(interp, "tcl_rcFileName", "~/wishrc.tcl", TCL_GLOBAL_ONLY);
    return TCL_OK;

error:
    MessageBeep(MB_ICONEXCLAMATION);
    MessageBox(NULL, Tcl_GetStringResult(interp), "Error in Wish",
	    MB_ICONSTOP | MB_OK | MB_TASKMODAL | MB_SETFOREGROUND);
    ExitProcess(1);
    /* we won't reach this, but we need the return */
    return TCL_ERROR;
}


int APIENTRY
WinMain(HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpszCmdLine,
        int nCmdShow)
{
    char **argv;
    int argc;
    char buffer[MAX_PATH+1];
    char *p;
    GetModuleFileName(NULL, buffer, sizeof(buffer));
    argv[0] = buffer;
    for (p = buffer; *p != '\0'; p++) {
    if (*p == '\\') {
        *p = '/';
    }
    }
    Tk_Main(argc, argv, Tcl_AppInit);
    //return MessageBox(NULL, "Hello, OneFLOW CFD!", "Computation", 0);
}