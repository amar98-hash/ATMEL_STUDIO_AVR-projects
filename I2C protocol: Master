/*7
 * main.c
 *
 * Created: 7/17/2021 1:48:51 AM
 *  Author: Amar Dadel
 */ 		

#include <xc.h>
#include <avr/io.h>
#define F_CPU 8000000UL //defining 8Mhz clock for delay function.

#include <util/delay.h>


void TWI_Init(){
	TWBR = 0x00; //clears status reg.
	TWBR= 0x0C; // sets bit rate.
}


void TWI_Start(){
	TWCR =(1<<TWINT)|(1<<TWEN)|(1<<TWSTA);
	while((TWCR&(1<<TWINT))==0);
	while((TWSR& 0xF8)!= 0x08);
}


void TWI_Write_Addr(unsigned char Addr)
{
	TWDR=Addr;
	
	TWCR= (1<<TWINT)|(1<<TWEN);
	
	while ((TWCR& (1<<TWINT))==0);
	
	while ((TWSR& (0xF8))!=0x18);
	
}


void TWI_Write_Data(unsigned char Data){
	
	TWDR= Data;
	
	TWCR= (1<<TWINT)|(1<<TWEN);
	
	while ((TWCR& (1<<TWINT))==0);
	
	while ((TWSR& (0xF8))!=0x28);
	
	
}


void TWI_Stop(){
	
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	
	
}
int main(){
	TWI_Init();
	
	while(1){
		TWI_Start();
		_delay_ms(1000);
		TWI_Write_Addr(0x20);
		_delay_ms(1000);
		TWI_Write_Data('A');
		_delay_ms(1000);
		TWI_Stop();
		_delay_ms(1000);
		
		
	}
	
	return 0;
}
