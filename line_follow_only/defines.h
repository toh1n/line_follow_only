//replace the pins with motor driver pin 

#define rightMotor1 PA8 // right Motor Forward
#define rightMotor2 PB15 // right Motor Backward
#define rightMotorPWM PA9 // right Motor PWM 
#define leftMotor1 PB13 // left Motor Backward
#define leftMotor2 PB12 // left Motor Forward 
#define leftMotorPWM PB1 // left Motor PWM

#define N_SENS 8
#define p 10  // 7.8V
#define d 120

uint16_t bitSensor = 0;
int16_t error = 0;
int lastError = 0;

int line = 1; // 0 means black line and 1 means white line
int maxSpeed = 120;

int sensor_values[N_SENS];
int sens_max[N_SENS] = { 3850, 3850, 3850, 3850, 3850, 3850, 3850, 3850 }; // replace with  value on black surface - 50
int sens_min[N_SENS] = { 2700, 2900, 2900, 2500, 2400, 2900, 2900, 2950 }; // replace with the value on whit surface - 50

int sensor[N_SENS] = { 7, 6, 5, 4, 3, 2, 1, 0 };
