/*
TECHNOGEAR MAIN LIBRARY:
*-These are pre-defined behaviors for our robot to carry out.
*-These include functions that return values or carry out tasks.
*-These have been built to be dynamic and for extensive software maintenance.

INCLUDES:
*-Functions that make use of the quadrature encoders for accurate distances.
*-Functions that make use of the colour sensor for line tracking and alignment.
*-Functions that make use of the gyro sensor for turning and straightening.


EXTRA INFO:
AUTHOR: Aditya Khanna, Team Technogear 21549D
VERSION: version 1.0 [OLDER VERSION]
DATE OF CREATION: 24/2/2018
REVISION LOG:
24/2/2018- First Created.
*/
void Move_Backward(int d)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	while ((getMotorEncoder(leftMotor) < d) && (getMotorEncoder(rightMotor) < d))
	{
		setMultipleMotors(80, leftMotor, rightMotor, noMotor, noMotor);
	}
	setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}
void Move_Backward_Slow(int d)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	while ((getMotorEncoder(leftMotor) < d) && (getMotorEncoder(rightMotor) < d))
	{
		setMultipleMotors(35, leftMotor, rightMotor, noMotor, noMotor);
	}
	setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}


void Move_Forward(int d)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	while ((getMotorEncoder(leftMotor) > -d) && (getMotorEncoder(rightMotor) > -d))
	{
		setMultipleMotors(-80, leftMotor, rightMotor, noMotor, noMotor);
	}
	setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}//yeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee;j

void Move_Forward_Fast(int d)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	while ((getMotorEncoder(leftMotor) > -d) && (getMotorEncoder(rightMotor) > -d))
	{
		setMultipleMotors(-120, leftMotor, rightMotor, noMotor, noMotor);
	}
	setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}

void Move_Forward_Slow(int d)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	while ((getMotorEncoder(leftMotor) > -d) && (getMotorEncoder(rightMotor) > -d))
	{
		setMultipleMotors(-50, leftMotor, rightMotor, noMotor, noMotor);
	}
	setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}


void Turn_Left_90(int d)
	//----------------------Turn left
{
   resetGyro(gyroSensor);
   setMotorSpeed(leftMotor, 50);
   setMotorSpeed(rightMotor, -50);
   waitUntil(getGyroDegrees(gyroSensor)>=90);
}
  //Turn left---------------------
void Turn_Left_60(int d)
	//----------------------Turn left
{
   resetGyro(gyroSensor);
   setMotorSpeed(leftMotor, 50);
   setMotorSpeed(rightMotor, -50);
   waitUntil(getGyroDegrees(gyroSensor)>=60);
}
  //Turn left---------------------


void Turn_Right (int d)
{
	resetGyro(gyroSensor);
	while(getGyroDegrees(gyroSensor) > -d)
	{
		turnLeft(90, degrees, 50);
  }
	setMotor(leftMotor, 0);
	setMotor(rightMotor, 0);
}

void Turn_Right_SS (int d, int s)
{
	resetGyro(gyroSensor);
	while(getGyroDegrees(gyroSensor) > -d)
	{
		turnLeft(90, degrees, s);
  }
	setMotor(leftMotor, 0);
	setMotor(rightMotor, 0);
}

	void Move_Right(int d)
{
	resetMotorEncoder(HDrive);
	while ((getMotorEncoder(HDrive)) < d)
	{

	setMotor(HDrive, 80);

	}
	setMotor(HDrive, 0);

}

void Move_Left(int d)
{
	resetMotorEncoder(HDrive);
	while ((getMotorEncoder(HDrive)) > -d)
	{

	setMotor(HDrive, -80);

	}
	setMotor(HDrive, 0);

}
void Move_Left_slow(int d)
{
	resetMotorEncoder(HDrive);
	while ((getMotorEncoder(HDrive)) > -d)
	{

	setMotor(HDrive, -10);

	}
	setMotor(HDrive, 0);

}
void Move_Right_slow(int d)
{
	resetMotorEncoder(HDrive);
	while ((getMotorEncoder(HDrive)) < d)
	{
		setMotor(HDrive, 20);
	}
	setMotor(HDrive, 0);
}

void Raise_Arm(int d)
{
	resetMotorEncoder(liftMotor);
	while ((getMotorEncoder(liftMotor)) < d)
	{
		setMultipleMotors(127, liftMotor, liftMotor2, noMotor, noMotor);
	}
	setMotor(liftMotor, 0);

}
void Raise_Arm_Slow(int d)
{
	resetMotorEncoder(liftMotor);
	while ((getMotorEncoder(liftMotor)) < d)
	{
		setMultipleMotors(60, liftMotor, liftMotor2, noMotor, noMotor);
	}
	setMotor(liftMotor, 0);

}
void Lower_Arm(int d)
{
	resetMotorEncoder(liftMotor);
	while ((getMotorEncoder(liftMotor)) > -d)
	{
		setMultipleMotors(-115, liftMotor, liftMotor2, noMotor, noMotor);
	}
	setMotor(liftMotor, 0);
}
void Lower_Arm_SS(int d, int s)
{
	resetMotorEncoder(liftMotor);
	while ((getMotorEncoder(liftMotor)) > -d)
	{
		setMultipleMotors(-s, liftMotor, liftMotor2, noMotor, noMotor);
	}
	setMotor(liftMotor, 0);
}
void Move_Forward_Slow_RDeacreased(int d)
{
	resetMotorEncoder(leftMotor);
	resetMotorEncoder(rightMotor);
	while ((getMotorEncoder(leftMotor) > -d) && (getMotorEncoder(rightMotor) > -d))
	{
		setMotor(leftMotor, -60);
	}
	{
		setMotor(rightMotor, -58);
	}
	{
		setMotor(leftMotor, 0);
	}
	{
		setMotor(rightMotor, 0);
	}

}
void linetrackfwd()
{
  	int threshold = 600;      /* found by taking a reading on both DARK and LIGHT    */
														/* surfaces, adding them together, then dividing by 2. */

	clearTimer(T1);						// Resets timer T1 to start counting at 0

	while(time1[T1] < 3400)  // Loops code while timer T1 has counted less than 10 seconds
	{
		if(getColorValue(colourSensor) < threshold)
		{
			setMotorSpeed(leftMotor, -50);
			setMotorSpeed(rightMotor, -50);
		}
		else
		{
			setMotorSpeed(leftMotor, 0);
			setMotorSpeed(rightMotor, 0);
		}
	}
}


	int grayScale ;





	int setGrayScaleValue(){

		grayScale  =getColorGrayscale(port12);
		return grayScale  ;
	}



	void doAction(string *action){
		int rev= 2 ;
		// int 1 is left

		displayString(line3,*action);

		if(*action== "left")
		{
	    Move_Right_slow(rev);
		}

		if(*action== "right")
		{
	    Move_Left_slow(rev);
		}



	}



	bool  moveTillBlackFound(string *myAction){

		if(setGrayScaleValue() > 101){
			doAction(myAction);
			return false;
		}else
			return true;
	}





	void findNextBlack(string *myAction){

		bool carryOn = true;
		string action = *myAction;
		while(carryOn){
			//Move_Right_slow(200);
			//wait1Msec(200);
			grayScale = getColorGrayscale(port12);
			displayVariableValues(line1,grayScale);
			if (moveTillBlackFound(action)){
				carryOn = false;
			}
			displayString(line3," Exiting Black") ;
		}
	}
