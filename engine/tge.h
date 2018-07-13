#pragma once
#define SCREEN_BUF_SIZE 2000
#define SCREEN_WIDTH 80
#define MAX_TOKEN_SIZE 64

namespace TGE {


	void setCursor(HANDLE handle, int x, int y);
	//void clearScreenBuffer(CHAR_INFO *pBuf);
	void clearScreenBuffer( WCHAR _wCode, WORD _wAttr);
	void updateBuffer(HANDLE handle, CHAR_INFO *pBuf);
	void setCharacter(CHAR_INFO *pBuf, int x, int y, WCHAR code, WORD attr);
	CHAR_INFO *getCharacter(CHAR_INFO *pBuf, int x, int y);

	void drawLineH(int _x, int _y, int _nLength, WCHAR code, WORD attr);
	void drawLineV(int _x, int _y, int _nLength, WCHAR code, WORD attr);

	extern CHAR_INFO g_chiBuffer[];
	


	//유틸리티
	int doTokenize(char *szBuf, char szBufToken[8][MAX_TOKEN_SIZE]);

	//파일처리 
	int loadBufferBinary(CHAR_INFO *pBuf, const char *szFileName);
	int saveBufferBinary(CHAR_INFO *pBuf, const char *szFileName);

	CHAR_INFO *CreateScreenBuffer();

	//스프라이트
	void putSprite(int posx, int posy, int destw, int desth, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc);
	void putSprite(int posx, int posy, int srcw, int srch, CHAR_INFO *pDest, CHAR_INFO *pSrc);

	namespace input {
		extern char g_KeyTable[1024];
	}
	void startTGE();
	void endTGE();

}

