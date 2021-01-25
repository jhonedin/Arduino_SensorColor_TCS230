/*
 * Autor: Jhon Edinson Blandon
 * anio: 2021
 * Descripción:
 * Manejo basico de prueba del sensor de color referencia TCS230
 * 
Pines en el
Sensor de Color  Pines en el Arduino
-----------      --------
 VCC               5V
 GND               GND
 s0                8
 s1                9
 s2                12
 s3                11
 OUT               10
 OE                GND
*/
//Declaro las constantes de los pines donde iran conectados los pines del sensor con los pines del arduino
const int s0 = 8;  
const int s1 = 9;  
const int s2 = 12;  
const int s3 = 11;  
const int out = 10;   

// Variables globales donde se guarda el valor de la intensidad del color detectado
int red = 0;  
int green = 0;  
int blue = 0; 


    
void setup()   
{  
  Serial.begin(9600); 
  pinMode(s0, OUTPUT);  
  pinMode(s1, OUTPUT);  
  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);  
  digitalWrite(s0, HIGH);  
  digitalWrite(s1, HIGH);  
  
}  
    
void loop() 
{  
  color(); 
  Serial.print("R Intensity:");  
  Serial.print(red, DEC);  
  Serial.print(" G Intensity: ");  
  Serial.print(green, DEC);  
  Serial.print(" B Intensity : ");  
  Serial.print(blue, DEC);
  Serial.print(" Suma Total : ");
  Serial.print(red+blue+green,DEC);  
  Serial.println();
  delay(1000);
  
  Serial.println();  

  // Se van comparando las intensitades obtenidas para determinar el color que se esta sensando
  // Luego se muestra en la consola del IDE de arduino el color que se esta detectando con el sensor.
  if ((green > red) && (green > blue) && ((green > 20) && (green < 50)))
  {  
   Serial.println("Detectando color: ROJO");  
   
  } 
  
  if ((green > red) && (green > blue) && ((green < 20) && (blue < 20) && (green < 20)))
  {
    Serial.println("Detectando color: AMARILLO"); 
  }
 
  if ((red > green) && (red > blue) && ((red > 19) && (red < 50)))
  {  
   Serial.println("Detectando color: AZUL");   
  }  

}

// Procedimiento que calcula las intensidades de los colores basicos el rojo el azul y el verde
void color()  
{    
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
   
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s3, HIGH);  
   
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
  digitalWrite(s2, HIGH);  
  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  
}
