//REVISION LOG:
//24/2/2018- First Created.
//26/2/2018- If loops replaced with switch statements, refinement.
//27/2/2018- Program simplification and writeDebugStream/ displayText functions added for debugging.
//2/3/2018- More commands added.
//4/3/2018- Rerun added.
//*/
int threshold = 40;//This threshold can set the top speeds of the controller and robot.
int armspeed = 25;//Speed of the arm
int joystickValueSpacing = 2;//Overall robot speed
#define   DATALOG_SERIES_0    0
#define   DATALOG_SERIES_1    1
#define   DATALOG_SERIES_2    2
#define   DATALOG_SERIES_3    3

task leftDrive()
{
	//Each task is set simultaneously, this stops the need for long programs for every single combination.
	while(true)
	{
		//Reads the joy value and compares it to the threshold.
		if(abs(getJoystickValue(ChA)) > threshold && getJoystickValue(ChA) > 0)
		{
			setMotorSpeed(motor1, threshold);
		}else if(abs(getJoystickValue(ChA)) > threshold && getJoystickValue(ChD) > 0)
		{
			setMotorSpeed(motor1, -threshold);
		}
	}
}
task arm()
{
		if(getJoystickValue(BtnRUp) == 1)
		{
			setMotorSpeed(motor2, armspeed);
			setMotorSpeed(motor3, armspeed);
    }

}
task rightDrive()
{
	while(true)
	{
		if(abs(getJoystickValue(ChA)) > threshold && getJoystickValue(ChA) > 0)
		{
			setMotorSpeed(motor1, threshold);
		}else if(abs(getJoystickValue(ChA)) > threshold && getJoystickValue(ChD) > 0)
		{
			setMotorSpeed(motor1, -threshold);
		}
	}
}
int   globalDatalog_1 = 0;
int   globalDatalog_2 = 0;
int   globalDatalog_3 = 0;
   task datalog()
   {
     int loops = 0;
     while(true)
        {
        // datalogAddValue adds one row to the datalog but does not time stamp the value
        datalogAddValue( DATALOG_SERIES_0, loops );

        // Get data and set to series
        globalDatalog_1 = getMotorSpeed(motor1);
        globalDatalog_2 = getMotorSpeed(motor2);
        globalDatalog_3 = getMotorSpeed(motor4);


        datalogDataGroupStart();
        datalogAddValue( DATALOG_SERIES_1, globalDatalog_1 );
        datalogAddValue( DATALOG_SERIES_2, globalDatalog_2 );
        datalogAddValue( DATALOG_SERIES_3, globalDatalog_3 );
        datalogDataGroupEnd();



        if(loops++ == 360)
          loops = 0;
        wait1Msec(10);
        }
}

task main()
{
  startTask(leftDrive);
  startTask(rightDrive);
  startTask(arm);
  startTask(datalog);


}
