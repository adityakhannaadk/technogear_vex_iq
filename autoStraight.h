task straighten()
{
	while(true)
	{
		bool straightenNeeded = abs(getMotorEncoder(motor1)) != abs(getMotorEncoder(motor6)) && abs(getJoystickValue(ChA) > 0) && getJoystickValue(ChD) > 0) ? true : false;

		if(straightenNeeded == true)
		{
			char direction = abs(getMotorEncoder(motor1)) > abs(getMotorEncoder(motor6)) ? 'L' : 'R'
			if(direction = 'R')
			{
				while(getGyroDegrees(port5) != 0)
				{
					setMotorSpeed(motor1, 100);
					setMotorSpeed(motor6, -100);
				}
			}else
			{
				while(getGyroDegrees(port5) != 0)
				{
					setMotorSpeed(motor1, -100);
					setMotorSpeed(motor6, 100);
				}
			}
		}
	}
}
