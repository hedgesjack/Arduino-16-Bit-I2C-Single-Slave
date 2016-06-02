//                                      //
//  Title:   I2C_Slave_WriteOnRequest   //
//  Author:  J Hedges                   //
//  Date:    29/05/2016                 //
//  Board:   Uno                        //
//                                      //

//  Library Declarations  //
#include <Wire.h>

//  Global Variable Declarations  //
int Data = 0;
byte myArray[2];

//  Startup Code - executes once  //
void setup() 
{
  Wire.begin(3);    //  Join I2C bus as slave with address 3
  Wire.onRequest(requestEvent);   //  Register event for data request
  Serial.begin(9600);   //  Start serial communication
}

//   Main Program Loop  //
void loop() 
{
  Data = analogRead(A0);  //  Read Analogue pin A0
  myArray[0] = (Data >> 8) & 0xFF;    //  Shift number down by 8BITS and mask with 0xFF to remove other bits, place in array 0
  myArray[1] = Data & 0xFF;   //  Format lower part by masking with 0xFF 8BIT to remove any other bits, place in array 1
  delay(500);   // Stop software running too quick and stressing CPU, can be used as sofware timing
}

//  
// this function is registered as an event, see setup()
void requestEvent() 
{
  Wire.write(myArray, 2);   //  Send array of data that is 2 BYTES in sizeSerial.print("Data Sent ");    //  Print the result to the serial com port for debug
  Serial.print("Data Sent ");   //  Add carriage return to com port so data is 
  Serial.print(Data);   //  Print the result to the serial com port for debug
  Serial.print("\n");   //  Add carriage return to com port so data is readable
} 

//                //
//  END OF FILE   //
//                //
