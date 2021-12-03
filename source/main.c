#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <ogcsys.h>
#include <gccore.h>

static u32 *xfb;
static GXRModeObj *rmode;


void Initialise() {
  
	VIDEO_Init();
	PAD_Init();
 
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
 
	printf("Hello World!\n");
	
	while(1) {

		PAD_ScanPads();
		u16 buttonsDown = PAD_ButtonsDown(0);
	
		if(buttonsDown & PAD_BUTTON_A) {
			printf("Button A pressed.\n");
		}

		u16 buttonsHeld = PAD_ButtonsHeld(0);

		if(buttonsHeld & PAD_BUTTON_A) {
			printf("Button A held down");
		}
		
		u16 buttonsUp = PAD_ButtonsUp(0);
		
		if(buttonsUp & PAD_BUTTON_A) {
			printf("Button A released.\n");
		}
		
		if(PAD_StickY(0) > 18) {
			printf("Joystick moved up.\n");
		}
		
		if(PAD_StickY(0) < -18) {
			printf("Joystick moved down.\n");
		}
		
		//Exits emulation when start is pressed
		if(buttonsDown & PAD_BUTTON_START) {
			exit(0);
		}
	}
	
	return 0;
}
