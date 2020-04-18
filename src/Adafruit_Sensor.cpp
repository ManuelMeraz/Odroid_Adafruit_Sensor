#include "Adafruit_Sensor.h"

#include <iostream>

/**************************************************************************/
/*!
    @brief  Prints sensor information to serial console
*/
/**************************************************************************/
void Adafruit_Sensor::printSensorDetails()
{
   sensor_t sensor;
   getSensor(&sensor);
   std::cout << "------------------------------------" << std::endl;
   std::cout << "Sensor:       " << sensor.name << std::endl;
   std::cout << "Type:         ";
   switch (static_cast<sensors_type_t>(sensor.type)) {
   case SENSOR_TYPE_ACCELEROMETER:
      std::cout << "Acceleration (m/s2)";
      break;
   case SENSOR_TYPE_MAGNETIC_FIELD:
      std::cout << "Magnetic (uT)";
      break;
   case SENSOR_TYPE_ORIENTATION:
      std::cout << "Orientation (degrees)";
      break;
   case SENSOR_TYPE_GYROSCOPE:
      std::cout << "Gyroscopic (rad/s)";
      break;
   case SENSOR_TYPE_LIGHT:
      std::cout << "Light (lux)";
      break;
   case SENSOR_TYPE_PRESSURE:
      std::cout << "Pressure (hPa)";
      break;
   case SENSOR_TYPE_PROXIMITY:
      std::cout << "Distance (cm)";
      break;
   case SENSOR_TYPE_GRAVITY:
      std::cout << "Gravity (m/s2)";
      break;
   case SENSOR_TYPE_LINEAR_ACCELERATION:
      std::cout << "Linear Acceleration (m/s2)";
      break;
   case SENSOR_TYPE_ROTATION_VECTOR:
      std::cout << "Rotation vector";
      break;
   case SENSOR_TYPE_RELATIVE_HUMIDITY:
      std::cout << "Relative Humidity (%)";
      break;
   case SENSOR_TYPE_AMBIENT_TEMPERATURE:
      std::cout << "Ambient Temp (C)";
      break;
   case SENSOR_TYPE_OBJECT_TEMPERATURE:
      std::cout << "Object Temp (C)";
      break;
   case SENSOR_TYPE_VOLTAGE:
      std::cout << "Voltage (V)";
      break;
   case SENSOR_TYPE_CURRENT:
      std::cout << "Current (mA)";
      break;
   case SENSOR_TYPE_COLOR:
      std::cout << "Color (RGBA)";
      break;
   }

   std::cout << std::endl;
   std::cout << "Driver Ver:   " << sensor.version << std::endl;
   std::cout << "Unique ID:    " << sensor.sensor_id << std::endl;
   std::cout << "Min Value:    " << sensor.min_value << std::endl;
   std::cout << "Max Value:    " << sensor.max_value << std::endl;
   std::cout << "Resolution:   " << sensor.resolution << std::endl;
   std::cout << "------------------------------------" << std::endl;
}
