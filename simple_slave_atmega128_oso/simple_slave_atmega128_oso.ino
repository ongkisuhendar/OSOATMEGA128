#define MASTER 0
#define baud 115200
#define ID_ 1


#if MASTER
#define MASTER 1
#define SLAVE 0
#else
#define MASTER 0
#define SLAVE 1
#endif
uint16_t pin_IN[8] = {52, 51, 50, 49, 23, 4, 48, 47};
uint16_t pin_OUT[8] = {44, 43, 42, 41, 40, 39, 13, 3};

#include <ModbusRtu.h>
//#include <SoftwareSerial.h>

//SoftwareSerial mySerial(20, 21); // RX, TX

uint16_t au16data[16] = {
  3, 1415, 9265, 4, 2, 7182, 28182, 8, 0, 0, 0, 0, 0, 0, 1, -1
};
#if MASTER
Modbus master(ID_, Serial1, 22); //master
modbus_t telegram;
#endif
#if SLAVE
Modbus slave(ID_, Serial, 2); //slave
#endif
void setup() {
#if MASTER
  Serial1.begin(baud);
  master.start();
#endif
#if SLAVE
  Serial.begin(baud);
  slave.start();
#endif
  for (int i = 0; i < 8; i++) {
    pinMode(pin_IN[i], INPUT);
  }
  for (int i = 0; i < 8; i++) {
    pinMode(pin_OUT[i], OUTPUT);
  }


}

void loop() {
#if MASTER
  master.poll( au16data, 16 );
#endif
#if SLAVE
  slave.poll( au16data, 16 );
#endif

  bitWrite( au16data[0], 0, digitalRead( pin_IN[0]));
  bitWrite( au16data[0], 1, digitalRead( pin_IN[1]));
  bitWrite( au16data[0], 2, digitalRead( pin_IN[2]));
  bitWrite( au16data[0], 3, digitalRead( pin_IN[3]));
  bitWrite( au16data[0], 4, digitalRead( pin_IN[4]));
  bitWrite( au16data[0], 5, digitalRead( pin_IN[5]));
  bitWrite( au16data[0], 6, digitalRead( pin_IN[6]));
  bitWrite( au16data[0], 7, digitalRead( pin_IN[7]));

  digitalWrite(pin_OUT[0], ! bitRead( au16data[0], 0 ));
  digitalWrite(pin_OUT[1], ! bitRead( au16data[0], 1 ));
  digitalWrite(pin_OUT[2], ! bitRead( au16data[0], 2 ));
  digitalWrite(pin_OUT[3], ! bitRead( au16data[0], 3 ));
  digitalWrite(pin_OUT[4], ! bitRead( au16data[0], 4 ));
  digitalWrite(pin_OUT[5], ! bitRead( au16data[0], 5 ));
  digitalWrite(pin_OUT[6], ! bitRead( au16data[0], 6 ));
  digitalWrite(pin_OUT[7], ! bitRead( au16data[0], 7 ));

}
