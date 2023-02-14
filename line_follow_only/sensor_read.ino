
void readCalibrated() {

  for (int i = 0; i < N_SENS; i++) {
    sensor_values[i] = analogRead(sensor[i]);
    int x = mapa(sensor_values[i], sens_min[i], sens_max[i], 0, 1000);
    if (x < 0)
      x = 0;
    else if (x > 1000)
      x = 1000;
    sensor_values[i] = x;
  }
}

long mapa(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint16_t readSensor() {
  for (int8_t i = 0; i < 8; i++) {
    readCalibrated();
    
    if (sensor_values[i] > 500) {
      bitSet(bitSensor, i); //bitSensor = bitSensor | (0b00000000000001 << i);
    }
    else {
      bitClear(bitSensor, i);
    }
  }

   if (line == 1) {
     bitSensor = ~bitSensor;
   }
  return bitSensor;
}
