#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S3,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S4,     angle_sensor,   sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     right_motor,   tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     left_motor,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     lift1,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C2_2,     lift2,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     brush,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     shoulder,      tmotorTetrix, openLoop, encoder)
#pragma config(Servo,  srvo_S1_C4_1,    impellar1,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_2,    impellar2,            tServoContinuousRotation)
#pragma config(Servo,  srvo_S1_C4_3,    goal_claw,            tServoStandard)
#pragma config(Servo,  srvo_S1_C4_4,    shutter,              tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
*
*  @file auto.c
*
*  @brief The automatic program for the robot.
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

/*Includes*/

//-----------------------
// sensor/mux/joystick includes
//-----------------------

#include "joystickdriver.c"
#include "lib/xander/hitechnic-sensormux.h"
#include "lib/xander/lego-light.h"
#include "lib/xander/hitechnic-irseeker-v2.h"
#include "lib/xander/hitechnic-gyro.h"
#include "lib/xander/hitechnic-angle.h"
#include "lib/xander/hitechnic-accelerometer.h"
#include "lib/xander/hitechnic-eopd.h"

//-----------------------
// Custom include
//-----------------------

#include "lib/compile_flags.h"
#include "lib/global_variables.h"
#include "lib/abs_initialize.h"
#include "abs_move_utils.h"
#include "abs_gyro_drive.h"
#include "lib/abs_drive.h"
task main()
{
	//int gyro_readings[200];
	//int time_stamps[200];
	//LogData=false;

	disableDiagnosticsDisplay();
	abs_cscreen("Gyros   ","Calbrtng","        ");
	HTGYROstartCal(HTGYRO);
	g_drift = 0;
	if(g_gyro_noise>10)
	{
		g_error = ERR_GYRO_CAL;
		g_error = ERROR_LETHAL;
	}
	if(HTSMUXreadPowerStatus(GYRO_MUX))
	{
		g_error = ERR_GYRO_MUX;
		g_error = ERROR_LETHAL;
	}
	abs_cscreen("Program ","Ready   ","        ");
	wait1Msec(200);
	StartTask(abs_sensors);
	PlayTone(700, 10);

	abs_drive(BACKWARD, E_ANGLE, 500, 100, true, GYRO, SLOW_DOWN);
	while(true){}
}
