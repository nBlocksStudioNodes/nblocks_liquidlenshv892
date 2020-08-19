#ifndef __NB_LIQUIDLENS
#define __NB_LIQUIDLENS

#include "nworkbench.h"

class nBlock_LiquidLensHV892: public nBlockSimpleNode<1> {
public:

    nBlock_LiquidLensHV892(PinName pinSDA, PinName pinSCL, uint8_t address, uint8_t initial_value);
    void triggerInput(nBlocks_Message message);
	void endFrame();
	
   
private:
	
	// Liquid lens are I2C-compatible
    I2C _i2c;
	
	// Temporary values to store data received from input
	uint32_t received_value;
	uint32_t must_update;
	
	// I2C address
	uint8_t _address;
};

#endif