#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>
#include <wiiuse/wpad.h>

static u32 *xfb;
static GXRModeObj *rmode;


void Initialise() {
  
	VIDEO_Init();
	WPAD_Init();
 
	rmode = VIDEO_GetPreferredMode(NULL);

	xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
	console_init(xfb,20,20,rmode->fbWidth,rmode->xfbHeight,rmode->fbWidth*VI_DISPLAY_PIX_SZ);
 
	VIDEO_Configure(rmode);
	VIDEO_SetNextFramebuffer(xfb);
	VIDEO_SetBlack(FALSE);
	VIDEO_Flush();
	VIDEO_WaitVSync();
	if(rmode->viTVMode&VI_NON_INTERLACE) VIDEO_WaitVSync();
}


int main() {
 
	Initialise();
 
	printf("Hello World\n");
	
	while(1) {

		WPAD_ScanPads();
		
		u16 buttonsDown = WPAD_ButtonsDown(0);
		
		if( buttonsDown & WPAD_BUTTON_A ) {
			printf("Button A pressed.\n");
		}	
		if( buttonsDown & WPAD_BUTTON_B ) {
			printf("Button B pressed.\n");
		}
		if( buttonsDown & WPAD_BUTTON_1 ) {
			printf("Button 1 pressed.\n");
		}
		if( buttonsDown & WPAD_BUTTON_2 ) {
			printf("Button 2 pressed.\n");
		}
        u16 buttonsHeld = WPAD_ButtonsHeld(0);	
		
		if( buttonsHeld & WPAD_BUTTON_1 ) {
			printf("Button 1 held.\n");
		}
		if( buttonsHeld & WPAD_BUTTON_2 ) {
			printf("Button 2 held.\n");
			
		}if( buttonsHeld & WPAD_BUTTON_B ) {
			printf("Button B held.\n");
		}
		if( buttonsHeld & WPAD_BUTTON_A ) {
			printf("Button A held.\n");
		}
		u16 buttonsUp = WPAD_ButtonsUp(0);
		
		if( buttonsUp & WPAD_BUTTON_A ) {
			printf("Button A up.\n");
		}
		if( buttonsUp & WPAD_BUTTON_2 ) {
			printf("Button 2 up.\n");
		}
		if( buttonsUp & WPAD_BUTTON_B ) {
			printf("Button B up.\n");
		}
		if( buttonsUp & WPAD_BUTTON_1 ) {
			printf("Button 1 up.\n");
		}

		

	}
 
	return 0;
}