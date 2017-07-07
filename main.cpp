#include "mbed.h"
#include "stm32f769i_discovery.h"
#include "stm32f769i_discovery_ts.h"
#include "stm32f769i_discovery_lcd.h"
/* #include "rtos.h" */

void mainscreen(); 
void clearscreen();
TS_StateTypeDef  TS_State = {0};


int main(){
        uint16_t x1, y1;
         mainscreen();
         while(1){
              BSP_TS_GetState(&TS_State);
              if(TS_State.touchDetected) {                              /* One or dual touch have been detected          */
              x1 = TS_State.touchX[0];                                  /* Get X and Y position of the first touch post calibrated */
              y1 = TS_State.touchY[0];
              printf("Touch Detected x=%d y=%d\n\r", x1, y1);
              if ((x1 > 0 & x1 < 88) & (y1 > 392 & y1 < 480)) {
                      clearscreen();
                     }
              BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
              BSP_LCD_FillRect(x1, y1, 20, 20);
           /*   BSP_LCD_FillRect(0, 380, 100, 100);       */
        }
    }
}

void mainscreen() {
    printf("\n\n TOUCHSCREEN EXAMPLE FOR DISCO-F769NI START:\n");
        BSP_LCD_Init();
    BSP_LCD_LayerDefaultInit(0, LCD_FB_START_ADDRESS);

    /* Touchscreen initialization */
    if (BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize()) == TS_ERROR) {
        printf("BSP_TS_Init error\n");
    }
  
    BSP_LCD_Clear(LCD_COLOR_WHITE);                                /* Clear the LCD */   
    BSP_LCD_SetTextColor(LCD_COLOR_BLUE);                           /* Set Touchscreen Demo1 description */
    BSP_LCD_FillRect(0, 0, BSP_LCD_GetXSize(), 40);
    BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
    BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
    BSP_LCD_SetFont(&Font24);
    BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"Touchscreen basic example", CENTER_MODE);
      BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    BSP_LCD_FillRect(0, 392, 88, 88);
      BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
    BSP_LCD_FillRect(0, 304, 88, 88);
        BSP_LCD_SetTextColor(LCD_COLOR_RED);
    BSP_LCD_FillRect(0, 216, 88, 88);
     BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    BSP_LCD_FillRect(0, 128, 88, 88);
     BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
    BSP_LCD_FillRect(0, 40, 88, 88);
    }
    
void clearscreen() {
     
     BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
     BSP_LCD_FillRect(0, 40, 800, 480);
      BSP_LCD_SetTextColor(LCD_COLOR_BLUE);
    BSP_LCD_FillRect(0, 392, 88, 88);
      BSP_LCD_SetTextColor(LCD_COLOR_MAGENTA);
    BSP_LCD_FillRect(0, 304, 88, 88);
        BSP_LCD_SetTextColor(LCD_COLOR_RED);
    BSP_LCD_FillRect(0, 216, 88, 88);
     BSP_LCD_SetTextColor(LCD_COLOR_GREEN);
    BSP_LCD_FillRect(0, 128, 88, 88);
     BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
    BSP_LCD_FillRect(0, 40, 88, 88);
     BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
     BSP_LCD_DisplayStringAt(0, 10, (uint8_t *)"Touchscreen basic example", CENTER_MODE);
   
    }