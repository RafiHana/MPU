
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>


#define RXD2 16
#define TXD2 17

Adafruit_MPU6050 mpu;
Adafruit_Sensor *mpu_temp, *mpu_accel, *mpu_gyro;

//float yaw=0, pitch=0, roll=0;

void setup(void) {
 Serial.begin(115200);
 Serial2.begin(115200, SERIAL_8N1, RXD2, TXD2);
 
 if (!mpu.begin()) {
   Serial.println("Failed");
   while (1) {
     delay(10);
   }
 }
 
//    mpu_accel = mpu.getAccelerometerSensor();
//  mpu_accel->printSensorDetails();
//  Serial.println("");
}

void loop() {

 sensors_event_t a, g, temp;
 mpu.getEvent(&a, &g, &temp);

//sensors_event_t accel;
//mpu_accel->getEvent(&accel);

//  float acx = a.acceleration.x;
 float acy = a.acceleration.y;
 float acz = a.acceleration.z;

//  float acx = (a.acceleration.x * 180/M_PI);
//  float acy = (a.acceleration.y * 360/M_PI);
//  float acz = (a.acceleration.z * 360/M_PI);
 
////  acx = map(acx, -10.00, 10.00, -2047.00, 2047.00);
//  acy = map(acy, -10.00, 10.00, -2047.00, 2047.00);
//  acz = map(acz, -10.00, 10.00, -2047.00, 2047.00);

 if (acx > 1.00) {
   acx *= 360/M_PI; 
 }

 if (acy > 1.00) {
   acy *=  360/M_PI;
 }

 if (acz > 1.00) {
   acz *= 360/M_PI;
 }
 
//  Serial.print((int)acx);
//  Serial.print("  ");
 Serial.print((int)acy);
 Serial.print("  ");
 Serial.print((int)acz);
 Serial.println("  ");

 Serial2.println("#"+String(acy)+"#"+String(acz)+"#$");

 delay(150);
}
