void resetAll()
{
 resetMotorEncoder(motor1);
 resetMotorEncoder(motor2);
 resetMotorEncoder(motor3);
 resetMotorEncoder(motor4);
 resetMotorEncoder(motor6);
}
void motorMoveComplete()
{
 waitUntilMotorMoveComplete(motor1);
 waitUntilMotorMoveComplete(motor2);
 waitUntilMotorMoveComplete(motor3);
 waitUntilMotorMoveComplete(motor4);
 waitUntilMotorMoveComplete(motor6);
}
void rerun(int mtr1, int mtr2, int mtr3, int mtr4, int mtr6)
{
	resetAll();
 	moveMotorTarget(motor1, mtr1, 75);
	moveMotorTarget(motor2, mtr2, 75);
	moveMotorTarget(motor3, mtr3, 75);
	moveMotorTarget(motor4, mtr4, 75);
	moveMotorTarget(motor6, mtr6, 75);
	moveMotorComplete();


}
</SourceCode>
