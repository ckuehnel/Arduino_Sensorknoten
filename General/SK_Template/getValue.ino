/* Reads the used sensor(s)

   You can add a conncetion table or other hints here.
   For example:

   Sensor xyz  | Vs  | Vout | GND |
   --------------------------------
   Arduino Uno | 5 V |  A0  | GND |

*/

float getValue()
{
  value = (float) random(10000); // Random value simulates sensor value here
  return value/100;   
}
