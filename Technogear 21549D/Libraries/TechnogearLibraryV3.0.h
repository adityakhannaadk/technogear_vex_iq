/*
TECHNOGEAR MAIN LIBRARY:
*-These are pre-defined behaviors for our robot to carry out.
*-These include functions that return values or carry out tasks.
*-These have been built to be dynamic and for extensive software maintenance.

INCLUDES:
*-Functions that make use of the quadrature encoders for accurate distances.
*-Functions that make use of the colour sensor for line tracking and alignment.
*-Functions that make use of the gyro sensor for turning and straightening.
*-Functions that make use of our controller for rerun.

EXTRA INFO:
AUTHOR: Aditya Khanna, Team Technogear 21549D
VERSION: version 3.0
DATE OF CREATION: 24/2/2018
REVISION LOG:
24/2/2018- First Created.
26/2/2018- If loops replaced with switch statements, refinement.
27/2/2018- Program simplification and writeDebugStream/ displayText functions added for debugging.
2/3/2018- More commands added.
4/3/2018- Rerun added.
*/

//Defined constants.
const int moveForward_Const = 100;
const int moveBackward_Const = 200;
const int moveRight_Const = 300;
const int moveLeft_Const = 400;
const int motorSpeed = 20;
const int grayScaleBlackValue = 101;
const int grayScalePort  = port12;

int grayScale = -1;
int counter = 0;
int blackPassedCounter = 0 ;
bool trackingBlack = false;

int setGrayScaleValue()
{
    grayScale = getColorGrayscale(grayScalePort);
    return grayScale;
}

void Move_Forward_b(int d)
{
    resetMotorEncoder(leftMotor);
    resetMotorEncoder(rightMotor);
    setGrayScaleValue();
    while ((setGrayScaleValue() > grayScaleBlackValue) && (getMotorEncoder(leftMotor) > -d) && (getMotorEncoder(rightMotor) > -d))
    {

        setMotorSpeed(motor1, -motorSpeed);
        setMotorSpeed(motor6, -motorSpeed);
        waitUntilMotorMoveComplete(motor1);
        waitUntilMotorMoveComplete(motor6);

    }
    setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}

void resetMotorEncoders(){
    resetMotorEncoder(leftMotor);
    resetMotorEncoder(rightMotor);
    resetMotorEncoder(HDrive);
}

void HaltMotors(){
    setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
    setMotor(HDrive, 0);
}

void Move_Backward_b(int d)
{
    resetMotorEncoder(leftMotor);
    resetMotorEncoder(rightMotor);
    setGrayScaleValue();
    while ((setGrayScaleValue() > grayScaleBlackValue) && (getMotorEncoder(leftMotor) < d) && (getMotorEncoder(rightMotor) < d))
    {
        setMultipleMotors(motorSpeed, leftMotor, rightMotor, noMotor, noMotor);
    }
    setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}


void resetBlackCounter(){
    blackPassedCounter  = 0 ;
}


void stopBlackTracking(){
    trackingBlack = false;
}
void trackBlackPassed(){
    trackingBlack = true;
    while (trackingBlack){
            displayVariableValues(line3, grayScale);
            if(setGrayScaleValue()< grayScaleBlackValue){
                    //while exiting add to counter
                    if(setGrayScaleValue() > grayScaleBlackValue){
                        blackPassedCounter ++;
                    }
            }
            sleep(1000);
    }
}

void Move_Right_b(int d)
{
    resetMotorEncoder(HDrive);
    while ((setGrayScaleValue() > grayScaleBlackValue) && (getMotorEncoder(HDrive)) < d)
    {
        setMotorSpeed(motor4, motorSpeed);
        waitUntilMotorMoveComplete(motor1);
        waitUntilMotorMoveComplete(motor6);

    }
    setMotorSpeed(motor4, 0);
}

void Move_Left_b(int d)
{
    resetMotorEncoder(HDrive);
    while ((setGrayScaleValue() > grayScaleBlackValue) && (getMotorEncoder(HDrive)) > -d)
    {
        setMotor(HDrive, -motorSpeed);
    }
    setMotor(HDrive, 0);


}

void doActionTillBlackFound(int const direction, int rev)
{

    string label;

    if (rev < 0){
        rev = 1000;
    }

    displayVariableValues(line3, direction);

    switch (direction)
    {

    case moveForward_Const:
        Move_Forward_b(rev);
        break;
    case moveBackward_Const:
        Move_Backward_b(rev);
        break;

    case moveRight_Const:
        Move_Right_b(rev);
        break;

    case moveLeft_Const:
        Move_Left_b(rev);
        break;
    }
}
//
int fieldGripCalibration()
{
 resetMotorEncoder(motor1);
 resetMotorEncoder(motor6);
 doActionTillDistance(moveForward_Const, 150);
 doActionUntilBlackFound(moveForward_Const, -1);
 //Find the average for the most accurate
 int oneBlockEncoderAverage = (getMotorEncoder(motor1) + getMotorEncoder(motor6))/2
 //Absolute value of the average.
 int oneBlockEncoder = abs(oneBlockEncoderAverage);
 //Finally returns.
 return oneBlockEncoder;



}

const int turnRight_Const = 600 ;
const int turnLeft_Const = 700 ;

bool motorConditionFlag = true;
//Boolean function, this can be turned off, stopping all motors from moving.

void resetMotorEncoders(){
    resetMotorEncoder(leftMotor);
    resetMotorEncoder(rightMotor);
    resetMotorEncoder(HDrive);
}

void moveForward_t(int forwardtime)
{
	setMotorSpeed(leftMotor, -120);
	setMotorSpeed(rightMotor, -120);
  wait1Msec(forwardtime);

	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
  //sleep(1000);
}

void moveRight_t(int t){

	setMotorSpeed(HDrive	, -50);
  sleep(t);
	setMotorSpeed(HDrive, 0);
  //sleep(1000);
}

void moveLeft_t(int t){

	setMotorSpeed(HDrive	, 100);
  sleep(t);
	setMotorSpeed(HDrive, 0);
  sleep(1000);
}


void moveBackward_t(int forwardTime)
{
	setMotorSpeed(leftMotor, 127);
	setMotorSpeed(rightMotor, 127);
  sleep(forwardTime);

	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
  //sleep(1000);
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

void HaltMotors(){
    setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
    setMotor(HDrive, 0);
}


void Move_Forward(int d)
{
    resetMotorEncoder(leftMotor);
    resetMotorEncoder(rightMotor);
    setGrayScaleValue();
    while ((motorConditionFlag) && (getMotorEncoder(leftMotor) > -d) && (getMotorEncoder(rightMotor) > -d))
    {
        setMultipleMotors(-motorSpeed, leftMotor, rightMotor, noMotor, noMotor);
    }
    setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}


void Move_Backward(int d)
{
    resetMotorEncoder(leftMotor);
    resetMotorEncoder(rightMotor);
    setGrayScaleValue();
    while (motorConditionFlag && (getMotorEncoder(leftMotor) < d) && (getMotorEncoder(rightMotor) < d))
    {
        setMultipleMotors(motorSpeed, leftMotor, rightMotor, noMotor, noMotor);
    }
    setMultipleMotors(0, leftMotor, rightMotor, noMotor, noMotor);
}


void Move_Right(int d)
{
    resetMotorEncoder(HDrive);
    while (motorConditionFlag && (getMotorEncoder(HDrive)) < d)
    {
        setMotor(HDrive, motorSpeed);
    }
    setMotor(HDrive, 0);
}

void Move_Left(int d)
{
    resetMotorEncoder(HDrive);
    while (motorConditionFlag && (getMotorEncoder(HDrive)) > -d)
    {
        setMotor(HDrive, -motorSpeed);
    }
    setMotor(HDrive, 0);

}

void liftArm()
{

	setMotorSpeed(liftMotor, 127);
	setMotorSpeed(liftMotor2, 127);
	wait1Msec(1000);
	setMotorSpeed(liftMotor, 0);
	setMotorSpeed(liftMotor2, 0);

//	Raise_Arm_Slow(210);
}



void lowerArm()
{
	displayText(line1,"lowerArm");
	setMotorSpeed(liftMotor, -75);
	setMotorSpeed(liftMotor2, -75);
	wait1Msec(1000);
	setMotorSpeed(liftMotor, 0);
	setMotorSpeed(liftMotor2, 0);
	displayText(line1,"lowerArm done");
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


void Lower_Arm(int d)
{
	resetMotorEncoder(liftMotor);
	while ((getMotorEncoder(liftMotor)) > -d)
	{
		setMultipleMotors(-115, liftMotor, liftMotor2, noMotor, noMotor);
	}
	setMotor(liftMotor, 0);
}

void moveUntilDistance(int distanceInDegrees)
{
  resetMotorEncoder(rightMotor); // Reset the right motor encoder
  resetMotorEncoder(leftMotor);  // Reset the left motor encoder
  moveMotorTarget(rightMotor, distanceInDegrees, 120); //Move the motors to the "distanceInDegree" value.
  moveMotorTarget(leftMotor, distanceInDegrees, 120);
  waitUntilMotorStop(rightMotor);  //Wait until the motor has come to a stop before moving on.
  waitUntilMotorStop(leftMotor);
}

void pointTurnRight(int turnDistanceRight)
{
  resetMotorEncoder(rightMotor); // Reset the right motor encoder
  resetMotorEncoder(leftMotor);  // Reset the left motor encoder
  moveMotorTarget(rightMotor, turnDistanceRight, 75);//Move the motors to the "distanceInDegree" value.
  moveMotorTarget(leftMotor, -turnDistanceRight, -75);
  waitUntilMotorStop(rightMotor);//Wait until the motor has come to a stop before moving on.
  waitUntilMotorStop(leftMotor);
}

void pointTurnLeft(int turnDistanceLeft)
{
  resetMotorEncoder(rightMotor); // Reset the right motor encoder
  resetMotorEncoder(leftMotor);  // Reset the left motor encoder
  moveMotorTarget(rightMotor, -turnDistanceLeft, -75);//Move the motors to the "distanceInDegree" value.
  moveMotorTarget(leftMotor, turnDistanceLeft, 75);
  waitUntilMotorStop(rightMotor);//Wait until the motor has come to a stop before moving on.
  waitUntilMotorStop(leftMotor);
}

void Turn_Left_90(int d)
	//----------------------Turn left
{
   resetGyro(gyroSensor);
   setMotorSpeed(leftMotor, 50);
   setMotorSpeed(rightMotor, -50);
   waitUntil(getGyroDegrees(gyroSensor)>=90);
}

 void Turn_Right_90(int d)

{
   resetGyro(gyroSensor);
   setMotorSpeed(leftMotor, -50);
   setMotorSpeed(rightMotor, 50);
   waitUntil(getGyroDegrees(gyroSensor)>=90);
}


void moveviaEncoder(int const direction, int rev)
{

    string label;

    if (rev < 0){
        rev = 1000;
    }

    displayVariableValues(line3, direction);

    switch (direction)
    {

    case moveForward_Const:
        Move_Forward(rev);
        break;
    case moveBackward_Const:
        Move_Backward(rev);
        break;

    case moveRight_Const:
        Move_Right(rev);
        break;

    case moveLeft_Const:
        Move_Left(rev);
        break;
    }
}


void doActionUntilDistance(int const direction, int rev)
{

    string label;

    displayVariableValues(line3, direction);

    switch (direction)//Runs switch for the action inputted.
    {

    case moveForward_Const:
        moveUntilDistance(-rev);
        break;
    case moveBackward_Const:
        moveUntilDistance(rev);
        break;

    case moveLeft_Const:
        Move_Left(rev);
        break;

    case moveRight_Const:
        Move_Right(rev);
        break;
    case turnRight_Const:
         pointTurnRight(rev);
        //Turn_Right_90(rev);
        break;

    case turnLeft_Const:
         pointTurnLeft(rev);
        //Turn_Left_90(rev);
        break;
    }
}

void doActionUntilBlackForNumberOfTimes(const int direction int numtimes)
{
	repeat(numtimes)
	{
		switch (direction)
    {

    case moveForward_Const:
        doActionTillBlack(moveForward_Const, -1);
        break;
    case moveBackward_Const:
        doActionTillBlack(moveBackward_Const, -1);
        break;

    case moveLeft_Const:
        doActionTillBlack(moveLeft_Const, -1);
        break;

    case moveRight_Const:
       doActionTillBlack(moveLeft_Const, -1);
        break;
    }
	}
}

void MbNum_l(int numtimes)
{
	repeat(numtimes)
	{
		doActionTillBlackFound(MoveRight_Const, -1);
		doActionUntilDistance(moveRight_Const, 50);

	}
}

void MbNum_2(int numtimes)
{
	repeat(numtimes -1)
	{
		doActionTillBlackFound(MoveRight_Const, -1);
		doActionUntilDistance(moveRight_Const, 50);

	}
	  doActionUntilDistance(moveRight_Const, 50);
}

void turn90(){
//Reset the gyro sensor to remove any previous data
	resetGyro(gyroSensor);

	//Loop while the gyro sees a value less than 90 degrees.
	while(getGyroDegrees(gyroSensor) < 85)
	{
		//Set the motors to turn to the left at 25% speed.
		setMotorSpeed(leftMotor, 25);
		setMotorSpeed(rightMotor,-25);
	}

	//Specifically stop the motor at the end to force the robot to come to a "Holding" stop.
	setMotorSpeed(leftMotor, 0);
	setMotorSpeed(rightMotor, 0);
	sleep(1000);  //wait 1 second for the robot to come to a complete stop.
}

void moveToCoordinate(int currentx, int currenty, int nextx, int nexty)
{
 //First use the pythagoras theorem to find the shortest distance to move to.
 if(nextx > currentx && nexty > currenty)
{
 	shortDist == sqrt((nextx-currentx)^(2)+(nexty -currenty)^(2));
 	//Now uses inverse sine function to find the degree between the distance and the y value.
 	angleDegrees == asin(shortDist/nexty-currenty);
 	//Now carries it out using the field encoder calibration.
 	fieldGripCalibration();
 	int encoderCountsNeeded == oneBlockEncoder * shortDist;
 	turn_Right(angleDegrees);
 	resetGyro(port5);

}

}


task main()
{



}
