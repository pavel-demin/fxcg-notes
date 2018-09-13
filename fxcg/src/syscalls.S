.macro SYSCALL CODE, NAME
  .section .text.\NAME, "ax", @progbits
  .global _\NAME
  .type _\NAME, @function
_\NAME:
  mov.l 0f, r0
  mov.l 1f, r2
  jmp @r2
  nop
0: .long \CODE
1: .long 0x80020070
.endm

SYSCALL 0x0272, Bdisp_AllClr_VRAM
SYSCALL 0x0921, Bdisp_EnableColor
SYSCALL 0x0D09, Bdisp_MMPrint
SYSCALL 0x025F, Bdisp_PutDisp_DD
SYSCALL 0x0263, Bdisp_SetPoint_VRAM
SYSCALL 0x1DA4, Bfile_CloseFile_OS
SYSCALL 0x1DAE, Bfile_CreateEntry_OS
SYSCALL 0x1DB4, Bfile_DeleteEntry
SYSCALL 0x1DBA, Bfile_FindClose
SYSCALL 0x1DB6, Bfile_FindFirst_NON_SMEM
SYSCALL 0x1DB8, Bfile_FindNext_NON_SMEM
SYSCALL 0x1DA6, Bfile_GetFileSize_OS
SYSCALL 0x1DA5, Bfile_GetMediaFree_OS
SYSCALL 0x1DDA, Bfile_Name_MatchMask
SYSCALL 0x1DDB, Bfile_NameToStr_ncpy
SYSCALL 0x1DA3, Bfile_OpenFile_OS
SYSCALL 0x1DAC, Bfile_ReadFile_OS
SYSCALL 0x1DA9, Bfile_SeekFile_OS
SYSCALL 0x1DDC, Bfile_StrToName_ncpy
SYSCALL 0x1DAB, Bfile_TellFile_OS
SYSCALL 0x1DAF, Bfile_WriteFile_OS
SYSCALL 0x0111, Bkey_ClrAllFlags
SYSCALL 0x0EA1, Bkey_SetAllFlags
SYSCALL 0x07A2, CharacterSelectDialog
SYSCALL 0x08C8, Cursor_SetFlashOff
SYSCALL 0x08C7, Cursor_SetFlashOn
SYSCALL 0x02B8, DefineStatusAreaFlags
SYSCALL 0x1D77, DefineStatusMessage
SYSCALL 0x02AA, DirectDrawRectangle
SYSCALL 0x0C01, DisplayErrorMessage
SYSCALL 0x1218, DisplayMBString2
SYSCALL 0x1D81, DisplayStatusArea
SYSCALL 0x1224, EditMBStringChar
SYSCALL 0x120A, EditMBStringCtrl2
SYSCALL 0x02B7, EnableStatusArea
SYSCALL 0x0131, FKey_Display
SYSCALL 0x1F42, free
SYSCALL 0x12f3, GetFKeyPtr
SYSCALL 0x0EAB, GetKey
SYSCALL 0x01E9, GetMiniGlyphPtr
SYSCALL 0x0031, GetSetupSetting
SYSCALL 0x01E6, GetVRAMAddress
SYSCALL 0x02C7, HourGlass
SYSCALL 0x1170, itoa
SYSCALL 0x12FC, LocalizeMessage
SYSCALL 0x1841, LongToAscHex
SYSCALL 0x1F44, malloc
SYSCALL 0x0C2C, MapIconToExt
SYSCALL 0x1163, MB_ElementCount
SYSCALL 0x154B, MCS_CreateDirectory
SYSCALL 0x1558, MCSDelVar2
SYSCALL 0x1562, MCSGetDlen2
SYSCALL 0x154D, MCSPutVar2
SYSCALL 0x0938, MsgBoxMoveWB
SYSCALL 0x17F9, MsgBoxPop
SYSCALL 0x17F7, MsgBoxPush
SYSCALL 0x1BB4, OS_InnerWait_ms
SYSCALL 0x0D39, PRGM_GetKey_OS
SYSCALL 0x0239, PrintCXY
SYSCALL 0x023c, PrintMini
SYSCALL 0x023B, PrintMiniGlyph
SYSCALL 0x021B, PrintMiniMini
SYSCALL 0x18F9, PrintXY
SYSCALL 0x1F46, realloc
SYSCALL 0x02C1, RTC_GetTicks
SYSCALL 0x1A0A, Scrollbar
SYSCALL 0x012B, Set_FKeys1
SYSCALL 0x0129, Set_FKeys2
SYSCALL 0x1E6E, SetQuitHandler
SYSCALL 0x0032, SetSetupSetting
SYSCALL 0x08DA, Timer_Deinstall
SYSCALL 0x08D9, Timer_Install
SYSCALL 0x08DB, Timer_Start
SYSCALL 0x08DC, Timer_Stop
