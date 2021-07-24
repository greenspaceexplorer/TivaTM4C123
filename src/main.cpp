#include <Arduino.h>

void blinkLED(uint8_t LED, uint period);

void setup(){
    pinMode(GREEN_LED, OUTPUT);
    digitalWrite(GREEN_LED,LOW);

    Serial.begin(9600);
}

uint timer = 0, period = 1000;

void loop(){
    blinkLED(GREEN_LED,1000);
    
    // do something periodically
    if(millis() % period < timer){
        Serial.println("Hello, world!");
        
    }
    timer = millis()%period;

}

// blinks an LED with given period
void blinkLED(uint8_t LED, uint period)
{
    static uint BlinkUpdateTime = 0;
    static bool state = true;

    if (millis() % period < BlinkUpdateTime)
    {
        if (state)
        {
            state = !state;
            digitalWrite(LED, LOW);
        }
        else
        {
            state = !state;
            digitalWrite(LED, HIGH);
        }
    }
    BlinkUpdateTime = millis() % period;
}
