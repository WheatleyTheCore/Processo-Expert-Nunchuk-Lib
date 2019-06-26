

/* Include Prototypes for your library, if applicable */
/* #include "mylibrary.h" */


/*-----------------------------------------------------------------------*

	Place your 'C' library code here.
	
 *-----------------------------------------------------------------------*/

//https://github.com/GabrielBianconi/arduino-nunchuk/blob/master/ArduinoNunchuk
//This library was referenced when figuring out how to do this with NXP microprocessors

#include "EI2C1.h"
#include "DataPin1.h"
#include "ClockPin1.h"
#include "Cpu.h"
#include "NunchukLib.h"

int AccelX;      //our variable declarations
int AccelY;
int AccelZ;
int AnalogX;
int AnalogY;
int Z;
int C;
int servoPos;
word numbytes;

/*----------------------------------------
  
  init() only needs to be called once, so I 
  would use it outside of your for(;;){} loop.
  I'd put it where it says "Write your local 
  variable definition here." 
  
----------------------------------------*/

void init() {        
	byte I2C_data[6];
	I2C_data[0] = 0xF0;      //data to init first register
	I2C_data[1] = 0x55;
	
	EI2C1_SendBlock(I2C_data, 2, &numbytes); //send data
	EI2C1_SendStop();
	Cpu_Delay100US(100); //wait for a bit
	  
	I2C_data[0] = 0xFB;      //data to init second register
	I2C_data[1] = 0x00;
	
	EI2C1_SendBlock(I2C_data, 2, &numbytes); //send data
	EI2C1_SendStop();
	Cpu_Delay100US(100); //wait for a bit
}

/*---------------------------------------------------------
	   
     getNewData() stuff:
     
	   The data returned from Analog will range from 0-255
	   Which means they are nice 8 bit bytes, and are easy to
	   work with.
	   
	   HOWEVER
	   
	   The accelerometer data is weird and has weird ranges.
	   
	   The data from Accelerometer X ranges from:
	   ~300 - ~800
	   
	   The data from Accelerometer Y ranges from:
	   
	   ~150 - ~600
	   *it is 150 when pointed up, and 600 when pointing down
	    
	   If you want to scale this data for specific ranges like
	   1 - 100, that is totally doable. I would suggest enabling
	   floating point data types in your build settings though(if using CodeWarrior),
	   because it is way easier to do (your value/max possible value)*100.
	   
	   If you are low on space though, it is still possible to finagle
	   it.
	   
	 *--------------------------------------------------------*/

void getNewData(byte NunchukData[6]) {
	EI2C1_RecvBlock(NunchukData, 6, &numbytes); //recieve data from the nunchuk
	EI2C1_SendStop();
	
	//next few lines translates what we got into actual values
	AnalogX = NunchukData[0];
	AnalogY = NunchukData[1];
	AccelX = (NunchukData[2] << 2) | ((NunchukData[5] >> 2) & 3);
	AccelY = (NunchukData[3] << 2) | ((NunchukData[5] >> 4) & 3);
	AccelZ = (NunchukData[4] << 2) | ((NunchukData[5] >> 6) & 3);
	Z = !((NunchukData[5] >> 0) & 1);
	C = !((NunchukData[5] >> 1) & 1);
	
	NunchukData[0] = 0x00;  //prepare to send ACK(which in this case is [0x00, 0x00]
	NunchukData[1] = 0x00;
	
	EI2C1_SendBlock(NunchukData, 2, &numbytes); //send ACK
	EI2C1_SendStop();
	
	Cpu_Delay100US(100); //wait a bit
}
