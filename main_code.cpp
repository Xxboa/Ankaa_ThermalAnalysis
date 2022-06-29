// Ankaa Project - LASC 2022
// Thermal Analysis Mission - Payload
// Thais Schmidt
// —---------------------------------------
 
 
#include <SdFat.h>
 
SdFat sdCard;
SdFile meuArquivo;
const int chipSelect = 28;
 
#include "max6675.h"
int SO = 19;
int CS1 = 5;
int CS2 = 22;
int CS3 = 1;
int SCK = 23;
MAX6675 sensor1(SCK, CS1, SO);
MAX6675 sensor2(SCK, CS2, SO);
MAX6675 sensor3(SCK, CS3, SO);
 
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
}
 
 
  void setup()
{
 Serial.begin(9600);
 delay(500);
}
void loop()
{ 
  Serial.print("Graus C = ");
  Serial.print("Bulkhead = ",sensor1.readCelsius());
  Serial.print("Fuselage = ",sensor2.readCelsius());
  Serial.print("Boattail = ",sensor3.readCelsius());
  delay(500);
}
