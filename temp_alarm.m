a = arduino('COM3','uno')

stop=false;

while (~stop)

v = readVoltage(a,'A0')

stop = readDigitalPin(a,'D6')

R0=100000;

B= 4275;

NTC= ((5/v)-1)*R0;

T= 1/((1/289.15)+(1/B)*log(NTC/R0));

Temperature = T-273.15

if Temperature > 53

    writePWMDutyCycle(a,'D5',0.33);pause(3)

    writeDigitalPin(a,'D5',0)

end

end
