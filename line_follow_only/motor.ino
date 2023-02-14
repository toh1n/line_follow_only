void set_motors(int left, int right) {

  if (left >= 0) {
    if (left > maxSpeed) left = maxSpeed;

    digitalWrite(leftMotor2, 1);
    digitalWrite(leftMotor1, 0);
  }

  if (left < 0) {
    if (abs(left) > maxSpeed) left = maxSpeed;

    left = abs(left);
    digitalWrite(leftMotor1, 1);
    digitalWrite(leftMotor2, 0);
  }

  if (right >= 0) {
    if (right > maxSpeed) right = maxSpeed;

    digitalWrite(rightMotor1, 1);
    digitalWrite(rightMotor2, 0);
  }
  if (right < 0) {
    if (abs(right) > maxSpeed) right = maxSpeed;

    right = abs(right);
    digitalWrite(rightMotor1, 0);
    digitalWrite(rightMotor2, 1);
  }

  analogWrite(leftMotorPWM, left);
  analogWrite(rightMotorPWM, right);
}
