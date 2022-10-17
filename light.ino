#include <Adafruit_NeoPixel.h>

#define LED_COUNT 92
#define LED_PIN 13
#define BUTTON_PIN 4

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);\
bool status = false;
bool lightsCanChange = true;
bool lightsAreChanging = false;
unsigned long holdMillis = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  strip.begin();
  strip.show();
}

void loop() {
  
  int buttonValue = digitalRead(BUTTON_PIN);
  if (buttonValue == HIGH)
  {
    holdMillis = -1;
    lightsCanChange = true;
  }
  else if (lightsCanChange)
  {
    if (holdMillis == -1)
    {
      holdMillis = millis();
    }
    else if (!lightsAreChanging && millis() - holdMillis > 100)
    {
      lightsCanChange = false;
      lightsAreChanging = true;
      changeLight();
      lightsAreChanging = false;
    }
  }
}

void changeLight()
{
  long rand = random(4);

  if (status) // TURN OFF
  {
    status = false;

    if (rand == 0)
    {
      for (int i = 0; i < LED_COUNT; i++)
      {
        strip.setPixelColor(i, 0, 0, 0, 0);
        strip.show();
      }
    }
    else if (rand == 1)
    {
      for (int i = 84; i >= 0; i--)
      {
        for (int k = 0; k < LED_COUNT; k++)
        {
          strip.setPixelColor(k, 0, 0, round(i * 0.588), i * 3);
        }
        strip.show();
        delay(1);
      }
    }
    else if (rand == 2)
    {
      for (int i = LED_COUNT - 1; i >= 0; i--)
      {
        strip.setPixelColor(i, 0, 0, 0, 0);
        strip.show();
      }
    }
    else if (rand == 3)
    {
      int arr[LED_COUNT];
      for (int i = 0; i < LED_COUNT; i++)
      {
        arr[i] = i;
      }
      for (int i = 0; i < LED_COUNT; i++)
      {
        int n = random(0, LED_COUNT);
        int temp = arr[n];
        arr[n] =  arr[i];
        arr[i] = temp;
      }

      for (int i = 0; i < LED_COUNT; i++)
      {
        strip.setPixelColor(arr[i], 0, 0, 0, 0);
        strip.show();
      }
    }
  }
  else // TURN ON
  {
    status = true;

    if (rand == 0)
    {
      for (int i = 0; i < LED_COUNT; i++)
      {
        strip.setPixelColor(i, 0, 0, 50, 255);
        strip.show();
      }
    }
    else if (rand == 1)
    {
      for (int i = 1; i <= 85; i++)
      {
        for (int k = 0; k < LED_COUNT; k++)
        {
          strip.setPixelColor(k, 0, 0, round(i * 0.588), i * 3);
        }
        strip.show();
        delay(1);
      }
    }
    else if (rand == 2)
    {
      for (int i = LED_COUNT - 1; i >= 0; i--)
      {
        strip.setPixelColor(i, 0, 0, 50, 255);
        strip.show();
      }
    }
    else if (rand == 3)
    {
      int arr[LED_COUNT];
      for (int i = 0; i < LED_COUNT; i++)
      {
        arr[i] = i;
      }
      for (int i = 0; i < LED_COUNT; i++)
      {
        int n = random(0, LED_COUNT);
        int temp = arr[n];
        arr[n] =  arr[i];
        arr[i] = temp;
      }

      for (int i = 0; i < LED_COUNT; i++)
      {
        strip.setPixelColor(arr[i], 0, 0, 50, 255);
        strip.show();
      }
    }
  }
}
