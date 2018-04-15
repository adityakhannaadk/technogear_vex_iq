void rerun(int mtr1, int mtr2, int mtr3, int mtr4, int mtr6)
{
 setMotorSpeed(motor1, mtr1);
 setMotorSpeed(motor2, mtr2);
 setMotorSpeed(motor3, mtr3);
 setMotorSpeed(motor4, mtr4);
 setMotorSpeed(motor6, mtr6);
 wait1Msec(1);
 setMultipleMotors(0, motor1, motor2, motor3, motor4, motor6);

}
