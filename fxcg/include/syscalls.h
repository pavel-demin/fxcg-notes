#ifndef fxcg_syscalls_h
#define fxcg_syscalls_h

#ifdef __cplusplus
extern "C" {
#endif

struct scrollbar
{
  int I1; // unknown changes indicator height, set to 0
  int indicatormaximum; // max logical indicator range
  int indicatorheight; // height of the indicator in units
  int indicatorpos; // indicator position in units of max
  int I5; // unknown, set to 0
  short barleft; // x position of bar
  short bartop; // y position of bar
  short barheight; // height of bar
  short barwidth; // width of bar
};

void Bdisp_AllClr_VRAM();
void Bdisp_EnableColor(int);
void Bdisp_MMPrint(int, int, const char *, int, int, int, int, int, int, int, int);
void Bdisp_PutDisp_DD();
void Bdisp_SetPoint_VRAM(int, int, int);
int Bfile_CloseFile_OS(int);
int Bfile_CreateEntry_OS(const short *, int, int *);
int Bfile_DeleteEntry(const short *);
int Bfile_FindClose(int);
int Bfile_FindFirst_NON_SMEM(const short *, int *, short *, void *);
int Bfile_FindNext_NON_SMEM(int, short *, void *);
int Bfile_GetFileSize_OS(int);
int Bfile_GetMediaFree_OS(short *, int *);
int Bfile_Name_MatchMask(short *, short *);
void Bfile_NameToStr_ncpy(char *, const short *, int);
int Bfile_OpenFile_OS(const short *, int);
int Bfile_ReadFile_OS(int, void *, int, int);
int Bfile_SeekFile_OS(int, int);
void Bfile_StrToName_ncpy(short *, const char *, int);
int Bfile_TellFile_OS(int);
int Bfile_WriteFile_OS(int, const void *, int size);
void Bkey_ClrAllFlags();
void Bkey_SetAllFlags(short);
short CharacterSelectDialog();
void Cursor_SetFlashOff();
void Cursor_SetFlashOn(char);
int DefineStatusAreaFlags(int, int, void *, void *);
void DefineStatusMessage(const char *, short, char, char);
void DirectDrawRectangle(int, int, int, int, short);
void DisplayErrorMessage(int);
void DisplayMBString2(int, char *, int, int, int, int, int, int, int);
void DisplayStatusArea();
int EditMBStringChar(char *, int, int, int);
void EditMBStringCtrl2(char *, int, void *, void *, void *, int, int, int, int);
void EnableStatusArea(int);
void FKey_Display(int, void *);
void GetFKeyPtr(int, void *);
int GetKey(int *);
void *GetMiniGlyphPtr(short, short *);
char GetSetupSetting(int);
void *GetVRAMAddress();
void HourGlass();
void itoa(int, char *);
void LoadVRAM_1();
int LocalizeMessage(int, char *);
void LongToAscHex(int, char *, int);
int MapIconToExt(char *, short *, int*, short *);
int MB_ElementCount(char *);
int MCS_CreateDirectory(char *);
int MCSDelVar2(char *, char *);
int MCSGetDlen2(char *, char *, int *);
int MCSPutVar2(char *, char *, int, void *);
void MsgBoxMoveWB(void *, int, int, int, int, int);
void MsgBoxPop();
void MsgBoxPush(int);
void OS_InnerWait_ms(int);
void PRGM_GetKey_OS(char *);
void PrintCXY(int, int, const char *, int, int, int, int, int, int);
void PrintMini(int *, int *, const char *, int, int, int, int, int, int, int, int);
void PrintMiniGlyph(int, int, void *, int, int, int, int, int, int, int, int, int);
void PrintMiniMini(int *, int *, const char *, int, char, int);
void PrintXY(int, int, const char *, int, int);
int RTC_GetTicks();
void SaveVRAM_1();
void Scrollbar(struct scrollbar *);
void Set_FKeys1(int, int *);
void Set_FKeys2(int);
void SetBackGround(int);
void SetQuitHandler(void (*)());
void SetSetupSetting(int, char);
int Timer_Install(int, void (*)(), int);
int Timer_Deinstall(int);
int Timer_Start(int);
int Timer_Stop(int);

#ifdef __cplusplus
}
#endif

#endif /* fxcg_syscalls_h */
