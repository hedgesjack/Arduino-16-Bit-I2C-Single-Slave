//                                    //
//  Title:   I2C_Master_ReadRequest   //
//  Author:  J Hedges                 //
//  Date:    29/05/2016               //
//  Board:   2560                     //
//                                    //

//  Library Declarations  //
#include <Wire.h>

//  Global Variable Declarations  //
int c;

//  Startup Code - executes once  //
void setup()
{
  Wire.begin();   //  Join I2C bus as master (no address)
  Serial.begin(9600);   //  Start serial communiation
}

//  Main Program Loop   //
void loop() 
{
  //  Requet Data from slave writer
  Wire.requestFrom(3, 2);    // Address 3, Two BYTES
  //  Read everything that is at the port
  if (Wire.available()==0)
  {
    c = -1;
  }
  else
  {
    while (Wire.available()) 
    {
      byte a = Wire.read();   //  Receive first byte
      byte b = Wire.read();   //  Recieve second byte
      c = a;    //  Set first byte as integer in variable c
      c = (a << 8) | b;   //  shift c by 8 BITS to correct transmission formatting and OR it with the second BYTE B
     }
  }
  Serial.print("Data Recieved ");    //  Print the result to the serial com port for debug
  Serial.print(c);    //  Print the result to the serial com port for debug
  Serial.print("\n");   //  Add carriage return to each line to allow for easy reading in com port
  delay(500);   // Stop software running too quick and stressing CPU, can be used as sofware timing
}

//                //
//  END OF FILE   //
//                //
