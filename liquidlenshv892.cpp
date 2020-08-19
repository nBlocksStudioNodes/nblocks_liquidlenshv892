#include "liquidlenshv892.h"

nBlock_LiquidLensHV892::nBlock_LiquidLensHV892(PinName pinSDA, PinName pinSCL, uint8_t address, uint8_t initial_value):
	_i2c(pinSDA, pinSCL) {
	
	// Store the I2C address
	_address = address;
	
	// Reset values
	received_value = initial_value;
	must_update = 1;
	
}


void nBlock_LiquidLensHV892::triggerInput(nBlocks_Message message){
	// input 0 receives an intensity value in range 0-255
	if (message.inputNumber == 0) {
		// Store value
		received_value = message.intValue;
		// Set flag so we update the lens at the end of frame
		must_update =  1;
	}
}

void nBlock_LiquidLensHV892::endFrame(void){

	if (must_update) {
		must_update = 0;
		
		// HV892 takes a single byte as value
		char buf[1];
		buf[0] = received_value;
		_i2c.write( _address, buf, 1 );
	}
	
	
}


