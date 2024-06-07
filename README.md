
# Digital Tachometer Using Arduino Nano

## Project Overview

This project involves designing and constructing a digital tachometer using an Arduino Nano. The tachometer measures the rotational speed of a motor or any rotating object and displays the RPM (Revolutions Per Minute) on an LCD screen. The project utilizes an IR (Infrared) sensor to detect the rotational motion and an Arduino Nano to process the sensor data and calculate the RPM.

## Components Required

- Arduino Nano
- IR Sensor
- Liquid Crystal Display (LCD)
- Resistors
- Wires
- Veroboard or PCB

## Project Description

Digital tachometers are widely used in various industries to measure the speed of rotating machinery accurately. This project aims to create a cost-effective and efficient digital tachometer using Arduino Nano and an IR sensor. The tachometer will provide real-time feedback on the rotational speed of motors, shafts, or any rotating object.

The project consists of two main parts: the transmitter and the receiver. The transmitter part is responsible for reading the input from the IR sensor, calculating the RPM, and transmitting the data via serial communication. On the other hand, the receiver part receives the RPM data from the transmitter through serial communication and displays it on the LCD screen.

### Transmitter Code

```cpp
int val;
int ir = A1;
long last = 0;
int stat;
int stat2 = LOW;
int counter = 0;
int rpm;
int sens = 200;
int milisec = 1000;

void setup() {
  Serial.begin(38400);
  pinMode(ir, INPUT);
}

void loop() {
  val = analogRead(ir);
  if (val < sens) {
    stat = HIGH;
  } else {
    stat = LOW;
  }
  if (stat2 != stat) {
    counter++;
    stat2 = stat;
  }
  if (millis() - last >= milisec) {
    rpm = (counter / 2.0);
    Serial.write(rpm);
    counter = 0;
    last = millis();
  }
}
```

### Receiver Code

```cpp
#include <LiquidCrystal.h>
LiquidCrystal lcd(10, 12, 14, 16, 18, 19);

int data = 0;
int rpm = 0;
int milisec = 2000;

void setup() {
  lcd.begin(16, 2);
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();
    rpm = data * 60000.0 / (milisec);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print(rpm);
  }
}
```

## Project Implementation

The project consists of two main parts: the transmitter and the receiver.

- **Transmitter**: This part is responsible for reading the input from the IR sensor, calculating the RPM, and transmitting the data via serial communication.

- **Receiver**: The receiver part receives the RPM data from the transmitter through serial communication and displays it on the LCD screen.

## Circuit Diagram

https://github.com/SMFaizer/Digital-Techometer-Project/blob/main/Techo%20meter.pdsprj

## Usage

1. **Connect the Hardware**: Assemble the circuit according to the provided circuit diagram.
2. **Upload the Code**: Upload the transmitter code to one Arduino Nano and the receiver code to another Arduino Nano.
3. **Test the Tachometer**: Rotate the object in front of the IR sensor to measure its RPM. The RPM will be displayed on the LCD screen.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Special thanks to the Arduino community for their support and resources.
- Inspiration from various online resources and tutorials.

## Contacts

For any inquiries, please contact [S.M. Faizer] at [smfaizer000@gmail.com].
```
