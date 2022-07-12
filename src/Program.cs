using System;
using System.Runtime.InteropServices;

namespace BSOD
{

    class Program
    {

        [DllImport("ntdll.dll")]
        public static extern IntPtr RtlAdjustPrivilege(int Privilege, bool bEnablePrivilege, bool IsThreadPrivilege, out bool PreviousValue);

        [DllImport("ntdll.dll")]
        public static extern uint NtRaiseHardError(uint ErrorStatus, uint NumberOfParameters, uint UnicodeStringParameterMask, IntPtr Parameters, uint ValidResponseOption, out uint Response);

        static void Main()
        {
            bool previous;
            uint response;
            RtlAdjustPrivilege(19, true, false, out previous);
            NtRaiseHardError(0xc000022A, 0, 0, IntPtr.Zero, 6, out response);
        }

    }

}