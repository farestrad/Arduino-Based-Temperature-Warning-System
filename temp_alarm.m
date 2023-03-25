% Initialize Arduino board
a = arduino('COM3','uno')

% Set stop condition to false
stop=false;

% Loop until stop condition is true
while (~stop)

% Read voltage from analog pin A0
v = readVoltage(a,'A0')

% Read digital pin D6 to check stop condition
stop = readDigitalPin(a,'D6')

% Set values for thermistor resistance and B constant
R0=100000;

B= 4275;

 % Calculate resistance and temperature from voltage reading
NTC= ((5/v)-1)*R0;

T= 1/((1/289.15)+(1/B)*log(NTC/R0));

Temperature = T-273.15

% If temperature is greater than 53°C, activate cooling fan
if Temperature > 53

    writePWMDutyCycle(a,'D5',0.33);pause(3)

    writeDigitalPin(a,'D5',0)

end

end
