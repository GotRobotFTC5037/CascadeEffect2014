#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S2,     SENSOR_MUX,     sensorI2CCustom)
#pragma config(Sensor, S3,     GYRO_MUX,       sensorI2CCustom)
#pragma config(Sensor, S4,     SENSOR_MUX2,    sensorI2CCustom)
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
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    intake_shutter,       tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/**
*
*  @file tele_op.c
*
*  @brief The tele_op program for the robot
*
*  @param None n/a
*
*  @return Returns nothing
*
*  @copyright Copyright 2013, Got Robot? FTC Team 5037
*
*/

//-----------------------
// sensor/mux/joystick includes
//-----------------------

#include "JoystickDriver.c"
#include "lib/xander/hitechnic-sensormux.h"
#include "lib/xander/hitechnic-accelerometer.h"
#include "lib/xander/hitechnic-irseeker-v2.h"
#include "lib/xander/hitechnic-gyro.h"
#include "lib/xander/hitechnic-angle.h"
#include "lib/xander/lego-touch.h"
#include "lib/xander/lego-ultrasound.h"

//-----------------------
// custom functions includes
//-----------------------

#include "lib/global_variables.h"
#include "lib/abs_joystick_drive.h"
#include "lib/abs_joystick_gunner.h"
#include "lib/abs_tele_op_initialize.h"

//========================================
// Main program
//========================================

task main ()
{
	abs_tele_op_initialize();
	StartTask(abs_joystick_gunner);
	while(g_program_done==false)
	{
		abs_joystick_drive();//(LINEAR);
	}
}
