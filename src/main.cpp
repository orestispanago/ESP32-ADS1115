#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);
float voltage = 0.0;

void setup(void)
{
    Serial.begin(115200);
    ads.begin();
}

void loop(void)
{
    int16_t adc0;

    adc0 = ads.readADC_SingleEnded(0);
    voltage = adc0 * 0.1875; // millivolts

    Serial.print("AIN0: ");
    Serial.print(adc0);
    Serial.print("\tVoltage: ");
    Serial.print(voltage, 7);
    Serial.print(" mV");
    Serial.println();

    delay(1000);
}