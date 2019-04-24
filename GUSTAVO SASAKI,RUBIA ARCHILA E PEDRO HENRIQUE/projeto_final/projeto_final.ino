#define trig  7  //pd7
#define echo  6  //pd6
#define led1  8  //branco pb0 
#define led2  9  //azul pb1 
#define led3  10 //verde pb2
#define led4  11 //amarelo pb3
#define led5  12 //vermelho pb4
long duracao;
float distancia;

#define BAUD 9600
#include <avr/io.h>
#include <stdio.h>
#include "minhasMacros.h"
#include "minhaCom.h"
#include "minhaAdc.h"
#include <util/setbaud.h>


void setup() {
  initUSART();
  setBit(DDRD,PD7);
  setBit(DDRB,PB0);
  setBit(DDRB,PB1);
  setBit(DDRB,PB2);
  setBit(DDRB,PB3);
  setBit(DDRB,PB4);
  clearBit(DDRD,PD6);
  Serial.begin(9600);
}

void loop() {
  clearBit(PORTD, PD7);
  delayMicroseconds(5);
  setBit(PORTD, PD7);            
  delayMicroseconds(10);      
  clearBit(PORTD,PD7);


  duracao = pulseIn (PD6, HIGH);

  distancia = duracao * 0.017;

  Serial.print("Distancia em cm: ");
  Serial.println(distancia); 
  delay (1000);

  leddistancia();

}

void leddistancia(){
  clearBit(DDRB,PB0);
  clearBit(DDRB,PB1);
  clearBit(DDRB,PB2);
  clearBit(DDRB,PB3);
  clearBit(DDRB,PB4);
 
  if (distancia > 40) //acende led braco
  {
  setBit(PORTB,PB0);
  clearBit(PORTB,PB1);
  clearBit(PORTB,PB2);
  clearBit(PORTB,PB3);
  clearBit(PORTB,PB4);
  }
  else if (distancia < 40 and distancia >=30) //acende led azul
 {
  setBit(PORTB,PB1);
  clearBit(PORTB,PB0);
  clearBit(PORTB,PB2);
  clearBit(PORTB,PB3);
  clearBit(PORTB,PB4);
 }
 else if (distancia < 30 and distancia >=20) //acende led verde
 {
  setBit(PORTB,PB2);
  clearBit(PORTB,PB0);
  clearBit(PORTB,PB1);
  clearBit(PORTB,PB3);
  clearBit(PORTB,PB4);
}
else if (distancia < 20 and distancia >=10)//acende led amarelo
 {
  setBit(PORTB,PB3);
  clearBit(PORTB,PB0);
  clearBit(PORTB,PB1);
  clearBit(PORTB,PB2);
  clearBit(PORTB,PB4);
 }
 else if (distancia < 10) //acende led vermelho
 {
  setBit(PORTB,PB4);
  clearBit(PORTB,PB0);
  clearBit(PORTB,PB1);
  clearBit(PORTB,PB2);
  clearBit(PORTB,PB3);
 }}
