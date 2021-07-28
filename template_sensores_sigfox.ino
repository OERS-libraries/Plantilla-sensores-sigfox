//Include Libraries
#include "Modulos.h"


//const int pinA1 = A1;
int contador = 1;

ModuloSigfox sensores = ModuloSigfox();
void setup() {
  Serial.begin(9600);
  //Testeo del modem Wisol
  //Comprueba si existe o no cobertura en su zona
  sensores.TesteoCobertura();
}

void loop() {
  Serial.println();
  Serial.print("PRUEBA ");
  Serial.println(contador++);
  //Serial.print("Voltaje de bateria = ");
  //Serial.println(medicionBateria.leerVoltajeBateria(), 5);
  //int bateria = medicionBateria.leerPorcentajeBateria();
  int bateria = 100;
  //Imprime el porcentaje de la batería
  Serial.print("Porcentaje de bateria = ");
  Serial.print(bateria);
  Serial.println("%");
  //float axeX = 0.312;
  float axeX = sensores.getAxeX(); //Obtenemos la acelearion en el eje x del thinxtra
  Serial.print("Check Axe X: ");
  Serial.println(axeX);
  float temp = sensores.ObtenerTemperatura(); //Se obtiene la temperatura del thinxtra que da un tipo de dato float
  Serial.print("Temperatura: ");
  Serial.println(temp);
  if (axeX <= -0.2 or axeX >= 0.2) {
    //hacemos un arreglo de bytes para poder enviar byte por byte mas adelante
    //indicamos el tamano de nuestro mensaje sabiendo que el mÃ¡ximo tamaÃ±o es de 12 bytes​
    const uint8_t payloadSize = 11;
    sensores.Buffer_Pload(temp, axeX, bateria);//Se agregan datos al buffer. Función sobrecargada, se pueden enviar datos de distintos tipos.
  }
  delay(1000);
}
