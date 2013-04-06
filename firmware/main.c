/* 
 * This file will turn your UV-3R into a fox
 * Any questions contact me at mjs7769@rit.edu
 * 
 * Created by Matt Smicinski (KC2TNR) Copyright (C) 2013 <mjs7769 AT rit DOT edu> 
 *
 * Specially created for the RIT Amateur Radio Club, K2GXT 
 *
 * This program is free software; you can redistribute it and/or modify 
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version. 
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program; if not, write to the Free Software 
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA 
 */ 

#include "UV3R/uv3r.h"

unsigned char selfBias;
unsigned char	i;
unsigned short isOn;

int main()
{
  //Pin 31 is R10
  initIOPorts();

  msDelay(100);
  getSelfBias();
  lcdInit(42); //Adjust this for LCD contrast

  initRadioSettings();

  LCD_BACKLIGHT = 0;
  lcdClear();
  lcdShowStr("K2GXT",6);
  lcdShowStr("FOX",0);
  
  msDelay(1000); //Show startup screen for 1 second

  //Initial RDA settings
  rda1846Init();
  rda1846RX(1); //Go into rx mode

  lcdClear();

  uartInit();

  isOn = 0;

  while(1)
  {
    WDTR	= 0x9F; 

    radioSettings.rxFreqM = 146;
    radioSettings.rxFreqK = 565;
      
    updateRDA1846Freq(radioSettings.rxFreqM, radioSettings.rxFreqK);

    if(isOn) {
      lcdClear();
      lcdShowStr("FOX",6);
      lcdShowStr("ON",0);
      rda1846CW("K2GXT", 5);

      int x = 0;
      for(x=0; x<256;x++) { //repeat twice
        msDelay(78);
        unsigned char keys = getKeys();
        if (keys)
        {
          switch(keys)
          {
            case VOL_KEY:
              if(isOn) {
                  lcdClear();
                  lcdShowStr("FOX", 6);
                  lcdShowStr("OFF", 0);
    
                isOn = 0;
              } else {
                lcdClear();
                lcdShowStr("FOX", 6);
                lcdShowStr("ON", 0);
                isOn = 1;
              }
              break;
          } 
        }

          }
    } else {
      lcdClear();
      lcdShowStr("FOX", 6);
      lcdShowStr("OFF", 0);
    }

    

   unsigned char keys = getKeys();
    if (keys)
    {
      switch(keys)
      {
        case VOL_KEY:
          if(isOn) {
            isOn = 0;
          } else {
            isOn = 1;
          }
          break;
      } 
    }

  
    //unsigned char val = readADC(ADC_1); //Read the battery level
  }

  return 0;
}



