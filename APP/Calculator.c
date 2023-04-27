/**
 * main.c
 *
 *  Created on: 28 Mar 2023
 *      Author: Youssef
 */


#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"



void Calculator();

void main(void){

	LCD_VoidInit();
	KEYPAD_VoidInit();


//	LCD_VoidSendNumber(-2);
	while(1){
		Calculator();

	}

}

void Calculator(){
	u8  key_value=0;
	static s64 Num[4]={0,0,0,0};
	static u8 i=0;
	static u8 Iterator2=0;
	static u8 operation[2]={0,0};
	key_value=KEYPAD_u8GetPressedButton();
	if(key_value!=NO_KEY_PRESSED){
		switch(key_value){
			default:
				/*Store the values*/
				LCD_VoidSendCharactar(key_value);
				key_value-='0';
				Num[i]=(Num[i])*10+(key_value);
				break;
			case '*':
			/*Store Operation and increcment variable iterator */
				if(operation[Iterator2]==0){
					operation[Iterator2]='*';
					i++;

					LCD_VoidSendCharactar(key_value);
				}
				else{
				}
				break;
			case '/':
				if(operation[Iterator2]==0){
					operation[Iterator2]='/';
					i++;

					LCD_VoidSendCharactar(key_value);
				}
				else{

				}
				break;
			case '-':
				if(operation[Iterator2]==0){
					operation[Iterator2]='-';
					i++;
					LCD_VoidSendCharactar(key_value);
				}
				else{

				}
				break;
			case '+':
				if(operation[Iterator2]==0){
					operation[Iterator2]='+';
					i++;
					LCD_VoidSendCharactar(key_value);
				}
				else{

				}
				break;
			case 'C':
				/*Clear all values and operations*/
				LCD_VoidClearDisplay();
				Num[0]=0;
				Num[1]=0;
				Num[2]=0;
				Num[3]=0;
				i=0;
				Iterator2=0;
				operation[0]=0;
				operation[1]=0;
				break;
			case '=':
				LCD_VoidSendString("=");
				if(Iterator2==0){
					switch(operation[Iterator2])
					{
						case '*':
							Num[2]=Num[0]*Num[1];
							LCD_VoidSendNumber(Num[2]);
							break;
						case '-':
							Num[2]=Num[0]-Num[1];
							LCD_VoidSendNumber(Num[2]);
							break;
						case '+':
							Num[2]=Num[0]+Num[1];
							LCD_VoidSendNumber(Num[2]);
							break;
						case '/':
							Num[2]=Num[0]/Num[1];
							LCD_VoidSendNumber(Num[2]);
							break;
						default:
							Num[0]=0;
							Num[1]=0;
							i=0;
							break;
					}
					/*Increment Operation to do a second one and Increment the variable to do operation on the previous result*/
					Iterator2++;
					LCD_VoidSetCursorPos(LCD_ROW_TWO,LCD_COL_ONE);
					LCD_VoidSendNumber(Num[2]);
					i++;
			}
			else if (Iterator2==1){

				switch(operation[Iterator2])
				{
				case '*':
					Num[0]=Num[2]*Num[3];
					LCD_VoidSendNumber(Num[0]);
					break;
				case '-':
					Num[0]=Num[2]-Num[3];
					LCD_VoidSendNumber(Num[0]);
					break;
				case '+':
					Num[0]=Num[2]+Num[3];
					LCD_VoidSendNumber(Num[0]);
					break;
				case '/':
					Num[0]=Num[2]/Num[3];
					LCD_VoidSendNumber(Num[0]);
					break;
				default:
					break;
				}
				/*Store last result as the first variable , and flush all other iterators and variables */
				Iterator2=0;
				Num[1]=0;
				Num[2]=0;
				Num[3]=0;
				operation[0]=0;
				operation[1]=0;
				i=0;
				LCD_VoidClearDisplay();
				LCD_VoidSendCharactar('=');
				LCD_VoidSendNumber(Num[0]);
			}
		}
	}
	else{
		/*Do nothing if Key is not pressed*/
	}

}


