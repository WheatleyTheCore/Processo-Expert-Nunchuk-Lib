/*
 * NunchukLib.h
 *
 *  Created on: Jun 24, 2019
 *      Author: Alex
 */

#ifndef NUNCHUKLIB_H_
#define NUNCHUKLIB_H_

extern int AccelX;
extern int AccelY;
extern int AccelZ;
extern int AnalogX;
extern int AnalogY;
extern int Z;
extern int C;
extern int servoPos;
extern word numbytes;

void init();

void getNewData(byte NunchukData[6]);

#endif /* NUNCHUKLIB_H_ */
