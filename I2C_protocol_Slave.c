/*
 * CFile1.c
 *
 * Created: 7/17/2021 3:10:10 AM
 *  Author: Amar Dadel
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL // 8 mhz clock

#include <until/delay.h>

void TWI_Init(unsigned char Slave_Addr){
	TWAR = Slave_Addr;
	
}

unsigned char TWI_Read_Data(){
	TWCR=TWCR =(1<<TWINT)|(1<<TWEA)|(1<<TWEN);
	while((TWCR&(1<<TWINT))==0);
	while((TWSR &(0xF8))!= 0x80);
	
	
}

int main(){
	
	DDRB= 0xFF;
	TWI_Init(0x20);
	
	while(1){
		PORTB= TWI_Read_Data();
		_delay_ms(1000);
	}
	
	
	return 0;
}
