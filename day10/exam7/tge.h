#pragma once

void setCursor(HANDLE handle, int x, int y);
void clearScreenBuffer(CHAR_INFO *pBuf);
void updateBuffer(HANDLE handle, CHAR_INFO *pBuf);
void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);

extern CHAR_INFO g_chiBuffer[];

