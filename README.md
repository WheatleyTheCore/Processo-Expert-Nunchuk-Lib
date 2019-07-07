# Processor-Expert-Nunchuk-Lib
A library for communicating with Wii Nunchuks in the CodeWarrior IDE

## Setting it up

### Adding the component

The project must be created using processor expert.

This project uses the SW_I2C component. To add the SW_I2C component to the project, go to the component manager. Then, 
right click on the SW_I2C component. 

### Configuring the components

Go to the component inspector.

All Wii Nunchuks have the id 0x52.
So go to the Slave address init row, make the value box says H, and put 52 into the it.

For the I2C bus mode, change it to standard.

Now go into the components tab, and open the EI2C1:SWI2C element, and go into the DataPin1 or ClockPin1. Select whatever pins you want to use for both. Now, you should be done.

## A note on including c libraries.

In your sources folder where your main.c file is, that is where you want to put your library files. Put both the NunchuckLib.c 
and NunchukLib.h files in the sources folder, right next to your main.c. You want to include the .h file in your main.c, so in 
this case you would say #include NunchukLib.h at the top of your main.c. See the example c code to see what it should look 
like.
