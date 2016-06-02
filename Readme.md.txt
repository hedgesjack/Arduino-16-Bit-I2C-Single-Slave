Master Slave I2C Example

Master is mega2560
Slave is UNO

The slave reads a 16bit value from the ADC for pin A0. The 16bit data is formatted into two bytes to be transmitted to the master on request.
The master then re-formats the data back to a single 16bit number on reciept of the data.
A no response case is included in the master code to be able to return a -1 in the data variable (not expected) to be handled as an error.