#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    zC,             sensorAccelerometer)
#pragma config(Sensor, in2,    xC,             sensorAccelerometer)
#pragma config(Sensor, in3,    yC,             sensorAccelerometer)
#pragma config(Sensor, I2C_1,  backLeftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  frontLeftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  frontRightEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  backRightEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           backLeftControl, tmotorVex393_HBridge, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port3,           backLeftDrive, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           frontLeftControl, tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port5,           frontLeftDrive, tmotorVex393_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           frontRightControl, tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port7,           frontRightDrive, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port9,           backRightDrive, tmotorVex393_MC29, openLoop, reversed, driveRight)
#pragma config(Motor,  port10,          backRightControl, tmotorVex393_HBridge, openLoop, encoderPort, I2C_4)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

void init(){
	resetMotorEncoder(motor[frontLeftControl]);
	resetMotorEncoder(motor[frontRightControl]);
	resetMotorEncoder(motor[backLeftControl]);
	resetMotorEncoder(motor[backRightControl]);
}
void initValues(){
	if(vexRT[Btn7U] == 1){
		motor[frontLeftControl] = vexRT[Ch1];
		resetMotorEncoder(motor[frontLeftControl]);
	}
	if(vexRT[Btn7R] == 1){
		motor[frontRightControl] = vexRT[Ch1];
		resetMotorEncoder(motor[frontRightControl]);
	}
	if(vexRT[Btn7L] == 1){
		motor[backLeftControl] = vexRT[Ch1];
		resetMotorEncoder(motor[backLeftControl]);
	}
	if(vexRT[Btn7D] == 1){
		motor[backRightControl] = vexRT[Ch1];
		resetMotorEncoder(motor[backRightControl]);
	}
}

void tankDrive(){
	if(vexRT[Btn5U] == 1){
		motor[frontLeftDrive] = 127;
		motor[backLeftDrive] = 127;
	}
	if(vexRT[Btn5D] == 1){
		motor[frontLeftDrive] = -127;
		motor[backLeftDrive] = -127;
	}
	if(vexRT[Btn6U] == 1){
		motor[frontRightDrive] = 127;
		motor[backRightDrive] = 127;
	}
	if(vexRT[Btn6D] == 1){
		motor[frontRightDrive] = -127;
		motor[backRightDrive] = -127;
	}
}

void normalDrive(){
	if(vexRT[Ch4] != 0){
		if(nMotorEncoder[frontRightControl] > nMotorEncoder[frontLeftControl]){
			motor[frontLeftControl] = vexRT[Ch4] - 20;
			motor[frontRightControl] = vexRT[Ch4];
		}
		else if(nMotorEncoder[frontRightControl] < nMotorEncoder[frontLeftControl]){
			motor[frontLeftControl] = vexRT[Ch4];
			motor[frontRightControl] = vexRT[Ch4] - 20;
		}
		else{
			motor[frontLeftControl] = vexRT[Ch4];
			motor[frontRightControl] = vexRT[Ch4];
			motor[backRightControl] = vexRT[Ch4];
			motor[backLeftControl] = vexRT[Ch4];
		}
		if(nMotorEncoder[backRightControl] > nMotorEncoder[backLeftControl]){
			motor[backRightControl] = vexRT[Ch4] - 20;
			motor[backLeftControl] = vexRT[Ch4];
		}
		else if(nMotorEncoder[backRightControl] < nMotorEncoder[backLeftControl]){
			motor[backRightControl] = vexRT[Ch4];
			motor[backLeftControl] = vexRT[Ch4] - 20;
		}
		else{
			motor[frontLeftControl] = vexRT[Ch4];
			motor[frontRightControl] = vexRT[Ch4];
			motor[backRightControl] = vexRT[Ch4];
			motor[backLeftControl] = vexRT[Ch4];
		}
	}
	else{
		motor[frontLeftControl] = vexRT[Ch4];
		motor[frontRightControl] = vexRT[Ch4];
		motor[backRightControl] = vexRT[Ch4];
		motor[backLeftControl] = vexRT[Ch4];
	}
	motor[backRightDrive] = vexRT[Ch2];
	motor[backLeftDrive] = vexRT[Ch2];
	motor[frontRightDrive] = vexRT[Ch2];
	motor[frontLeftDrive] = vexRT[Ch2];
}

//moveMotorTarget(nMotor, nEncoderCountTarget, nMaxSpeedToUse, bHoldAtEnd);
task main(){
	init();
	while(true){
		tankDrive();
		initValues();
		normalDrive();
	}
}
