#pragma once

void initMapTool();
int parseCmd(char *szCmdBuf);

extern COORD g_cdCurrentCursorPos;
extern COORD _oldPos;

extern WCHAR g_wcCurrentBrushCode;
extern WORD g_wCurrentBrushAttr;