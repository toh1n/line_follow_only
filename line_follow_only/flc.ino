void flc(uint16_t SPEED, int8_t kp,int8_t kd) {
  bitSensor = readSensor();
    int8_t errorSensor[8] = { -14, -10, -5, -1, 1, 5, 10, 14 };
    int8_t onSensor[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    int8_t sumOnSensor = 0;
    for (int8_t i = 0; i < 8; i++) {
      onSensor[i] = bitRead(bitSensor, i);
      sumOnSensor += onSensor[i];
      errorSensor[i] = errorSensor[i] * onSensor[i];
      error += errorSensor[i];
    }
    error = error / sumOnSensor;

    int16_t rateError = error - lastError;
    lastError = error;

    int16_t moveVal = int((error * kp) + (rateError * kd));
    int16_t moveLeft = SPEED - moveVal;
    int16_t moveRight = SPEED + moveVal;

    set_motors(moveLeft, moveRight);

}
