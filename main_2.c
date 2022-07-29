/* corrigindo o programa anterior
by Lusca Netto */ 
 // lucas legal postastes
 
#include <SdFat.h>
#include "max6675.h"
 
SdFat sdCard;
SdFile meuArquivo;
const int chipSelect = 28;
 
int SO = 19;
int CS1 = 5;
int CS2 = 22;
int CS3 = 1;
int CK = 23;
float bulkhead ;
float Fuselage ;
float Boattail ;

MAX6675 sensor1(CK, CS1, SO);
MAX6675 sensor2(CK, CS2, SO);
MAX6675 sensor3(CK, CS3, SO);

 
  void setup()
{
  pinMode(A5, INPUT);
 
  // Inicializa o modulo SD
  if(!sdCard.begin(chipSelect,SPI_HALF_SPEED))sdCard.initErrorHalt();
 
  // Abre o arquivo LER_POT.TXT
  if (!meuArquivo.open("ler_pot.txt", O_RDWR | O_CREAT | O_AT_END))
  {
    sdCard.errorHalt("Erro na abertura do arquivo LER_POT.TXT!");
  }

 Serial.begin(9600);
 delay(500);
}


void loop()
{
  bulkhead =  sensor1.readCelsius();
  Fuselage =  sensor2.readCelsius();
  Boattail =  sensor3.readCelsius();
  
  meuArquivo.print("Bulkhead: ");
  meuArquivo.println(bulkhead);
  
  meuArquivo.print("\nFuselage: ");
  meuArquivo.println(Fuselage);
  
  meuArquivo.print("\nBoattail: ");
  meuArquivo.println(Boattail);
 
 
  delay(50);
}
