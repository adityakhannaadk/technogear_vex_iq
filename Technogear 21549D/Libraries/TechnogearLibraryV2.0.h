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
DATE OF CREATION: 24/2/2018
*/
int xvalue =0;
int yvalue =0;
const string moveForward_Const ="Forward";
const string moveBackward_Const ="Backward";
const string moveRight_Const ="Right";
const string moveLeft_Const ="Left";

const int motorSpeed = 100;
const int grayScaleBlackValue = 101;
const int  waitMilSec =10;

int grayScale ;
task coordinateFind()
{
 while(true)
 {

 }
}
void moveForward(int rev)
{
 resetMotorEncoder(motor1);
 resetMotorEncoder(motor6);
 while(getMotorEncoder(motor1) < rev && getMotorEncoder(motor6) < rev)
 {
  setMotorSpeed(motor1, motorSpeed);
  setMotorSpeed(motor6, motorSpeed);
  wait1Msec(waitMilSec);
 }
  setMotorSpeed(motor1, 0);
  setMotorSpeed(motor6, 0);
}

void moveBackward(int rev)
{
 resetMotorEncoder(motor1);
 resetMotorEncoder(motor6);
 while(getMotorEncoder(motor1) < rev && getMotorEncoder(motor6) < rev)
 {
  setMotorSpeed(motor1, (-1 * motorSpeed));
  setMotorSpeed(motor6, (-1 * motorSpeed));
  wait1Msec(waitMilSec);
 }
  setMotorSpeed(motor1, 0);
  setMotorSpeed(motor6, 0);
}

void turnRight(int deg)
{
   resetGyro(gyroSensor);
   setMotorSpeed(leftMotor, 100);
   setMotorSpeed(rightMotor, -100);
   waitUntil(getGyroDegreesFloat(gyroSensor)>=360 - deg);
}

void turnLeft(int deg)
{
   resetGyro(gyroSensor);
   setMotorSpeed(leftMotor, -100);
   setMotorSpeed(rightMotor,100);
   waitUntil(getGyroDegrees(gyroSensor)>=deg);
}



void moveRight(int rev)
{
 resetMotorEncoder(motor4);
 //resetMotorEncoder(motor6);
 while(getMotorEncoder(motor4) < rev )
 {
  setMotorSpeed(motor4, (motorSpeed));
  wait1Msec(waitMilSec);
 }
  setMotorSpeed(motor4, 0);

}


void moveLeft(int rev)
{
 resetMotorEncoder(motor4);
 //resetMotorEncoder(motor6);
 while(getMotorEncoder(motor4) < rev )
 {
  setMotorSpeed(motor4, (-1 * motorSpeed));
  wait1Msec(waitMilSec);
 }
  setMotorSpeed(motor4, 0);

}


void doAction(const string direction ,int rev)
{

	rev = 2 ;

	switch(direction){

	case moveForward_Const:
		//Move_Forward_slow(rev);
	  moveForward(rev);

		break;
	case moveBackward_Const:
	  moveBackward(rev);
	 	break;

	case moveRight_Const:
    moveRight(rev);
		break;


  }
}


int calibrateGrayscale()
{
 setTouchLEDColor(port4, colorRed);
 waitUntil(getTouchLEDValue);
 grayScaleBlackValue = getColorGrayScale(port12);
 setTouchLEDColor(port4, colorGreen);

}
bool isBlackSensed(){
	grayScale = getColorGrayscale(port12);
	if(grayScale < grayScaleBlackValue){
		return true;
	}else
		return false;
}


void moveUntilDarkFound(const string direction,int rev){
	//Do until black is found
	while(!isBlackSensed()){
		//displayVariableValues(line1,grayScale);
		doAction(direction,rev);
	}
}

void moveUntilDarkRepeat(const string direction,int rev, int repeatHowManyTimes){
	//Do until black is found
 repeat(repeatHowManyTimes)
 {
  moveUntilDarkFound(direction, rev);
  wait1Msec(1);
  doAction(direction,rev);

 }
}
void moveToCoordinateFunctY(int x, int y, int p, int nx, int ny, int np)
{
   if(ny - y < 0)
  {
   	moveUntilDarkRepeat(moveBackward_Const, 3, y - ny);
  }else
  {
  	moveUntilDarkRepeat(moveForward_Const, 3, ny - y);
}

void moveToCoordinateFunctX(int x, int y, int p, int nx, int ny, int np)
{
	   if(nx - x < 0)
  {
   	moveUntilDarkRepeat(moveBackward_Const, 3, y - ny);
  }else
  {
  	moveUntilDarkRepeat(moveForward_Const, 3, ny - y);
}

void moveToCoordinate(int x, int y, int p, int nx, int ny, int np)
{

 if(p = np)
 {
  moveToCoordinateFunctY( x,  y,  p,  nx,  ny,  np);
 }else
 {

}
