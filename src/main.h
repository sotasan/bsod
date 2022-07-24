#ifndef MAIN_H
#define MAIN_H

#include <winternl.h>

typedef enum _HARDERROR_RESPONSE_OPTION {
    OptionAbortRetryIgnore,
    OptionOk,
    OptionOkCancel,
    OptionRetryCancel,
    OptionYesNo,
    OptionYesNoCancel,
    OptionShutdownSystem
} HARDERROR_RESPONSE_OPTION, *PHARDERROR_RESPONSE_OPTION;

typedef enum _HARDERROR_RESPONSE {
    ResponseReturnToCaller,
    ResponseNotHandled,
    ResponseAbort,
    ResponseCancel,
    ResponseIgnore,
    ResponseNo,
    ResponseOk,
    ResponseRetry,
    ResponseYes
} HARDERROR_RESPONSE, *PHARDERROR_RESPONSE;

extern NTSYSAPI NTSTATUS NTAPI RtlAdjustPrivilege(
    ULONG Privilege,
    BOOLEAN Enable,
    BOOLEAN CurrentThread,
    PBOOLEAN Enabled
);

extern NTSYSAPI NTSTATUS NTAPI NtRaiseHardError(
    NTSTATUS ErrorStatus,
    ULONG NumberOfParameters,
    ULONG UnicodeStringParameterMask,
    PULONG_PTR Parameters,
    HARDERROR_RESPONSE_OPTION ResponseOption,
    PHARDERROR_RESPONSE Response
);

#endif