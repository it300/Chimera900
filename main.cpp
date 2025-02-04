#include <vector>
#include <Windows.h>
#include "code_injection/signature.h"
#include "client/command/command.h"
#include "client/client.h"

extern "C" BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    const short dsig[] = { 0x75, 0x2D, 0x68, -1, -1, -1, -1, 0xE8, -1, -1, -1, -1, 0x68, -1, -1, -1, -1, 0x68, -1, -1, -1, -1, 0xE8, -1, -1, -1, -1, 0x68, -1, -1, -1, -1, 0x68, -1, -1, -1, -1, 0x33, 0xC0, 0xE8, -1, -1, -1, -1, 0x83, 0xC4, 0x14, 0x8B, 0x44, 0x24, 0x04, 0x68, -1, -1, -1, -1, 0x68, -1, -1, -1, -1, 0x50 };
    static bool dedicated = reinterpret_cast<const char *>(sig_scan_s(dsig)) != NULL;
    static bool loaded = false;

	//MessageBox(NULL, "Hello World!", "My Message Box", MB_OK);

    if(fdwReason == DLL_PROCESS_ATTACH && !loaded) {
        loaded = true;
        if(dedicated) {

        }
        else {
            initialize_client();
        }
    }
    else if(fdwReason == DLL_PROCESS_DETACH && loaded) {
        loaded = false;
        if(dedicated) {

        }
        else {
            uninitialize_client();
        }
    }
    return true;
}
