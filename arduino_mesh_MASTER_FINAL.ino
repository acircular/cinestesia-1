/** RF24Mesh_Example_Master.ino by TMRh20


    This example sketch shows how to manually configure a node via RF24Mesh as a master node, which
    will receive all data from sensor nodes.

    The nodes can change physical or logical position in the network, and reconnect through different
    routing nodes as required. The master node manages the address assignments for the individual nodes
    in a manner similar to DHCP.

*/


#include "RF24Network.h"
#include "RF24.h"
#include "RF24Mesh.h"
#include <SPI.h>
//Include eeprom.h for AVR (Uno, Nano) etc. except ATTiny
#include <EEPROM.h>

/***** Configure the chosen CE,CS pins *****/
RF24 radio(7, 8); ///pines del CE y CSN creo...
RF24Network network(radio);
RF24Mesh mesh(radio, network);

uint32_t displayTimer = 0;
float dat[3];
boolean usar_print = true;

void setup() {
  Serial.begin(115200);

  // Set the nodeID to 0 for the master node
  mesh.setNodeID(0);
  Serial.println(mesh.getNodeID());
  // Connect to the mesh
  mesh.begin();

}


void loop() {

  // Call mesh.update to keep the network updated
  mesh.update();

  // In addition, keep the 'DHCP service' running on the master node so addresses will
  // be assigned to the sensor nodes
  mesh.DHCP();


  // Check for incoming data from the sensors
  if (network.available()) {
    RF24NetworkHeader header;
    network.peek(header);

    //int32_t dat=0;
    if (usar_print == true) {
      switch (header.type) {

        case '1': network.read(header, &dat, sizeof(dat));
          Serial.print('a');
          Serial.println(dat[0]);
          Serial.print('b');
          Serial.println(dat[1]);
          Serial.print('c');
          Serial.println(dat[2]);
          Serial.println();
          break;
        case '2': network.read(header, &dat, sizeof(dat));
          Serial.print('d');
          Serial.println(dat[0]);
          Serial.print('e');
          Serial.println(dat[1]);
          Serial.print('f');
          Serial.println(dat[2]);
          Serial.println();
          break;
        case '3': network.read(header, &dat, sizeof(dat));
          Serial.print('g');
          Serial.println(dat[0]);
          Serial.print('h');
          Serial.println(dat[1]);
          Serial.print('i');
          Serial.println(dat[2]);
          Serial.println();
          break;
        case '4': network.read(header, &dat, sizeof(dat));
          Serial.print('j');
          Serial.println(dat[0]);
          Serial.print('k');
          Serial.println(dat[1]);
          Serial.print('l');
          Serial.println(dat[2]);
          Serial.println();
          break;
        case '5': network.read(header, &dat, sizeof(dat));
          Serial.print('m');
          Serial.println(dat[0]);
          Serial.print('n');
          Serial.println(dat[1]);
          Serial.print('o');
          Serial.println(dat[2]);
          Serial.println();
          break;
        default: network.read(header, 0, 0);
          Serial.println(header.type);
          break;

      }
    }
      else {
        switch (header.type) {
          // Display the incoming millis() values from the sensor nodes
//
//          case '1': network.read(header, &dat, sizeof(dat));
//            Serial.write('a');
//            Serial.write(lowByte(dat[0]));
//            Serial.write(highByte(dat[0]));
//            Serial.write('\r');
//            Serial.write('b');
//            Serial.write(lowByte(dat[1]));
//            Serial.write(highByte(dat[1]));
//            Serial.write('\r');
//            Serial.write('c');
//            Serial.write(lowByte(dat[2]));
//            Serial.write(highByte(dat[2]));
//            Serial.write('\r');
//            Serial.write('\r');
//            break;
//          case '2': network.read(header, &dat, sizeof(dat));
//            Serial.write('d');
//            Serial.write(lowByte(dat[0]));
//            Serial.write(highByte(dat[0]));
//            Serial.write('\r');
//            Serial.write('e');
//            Serial.write(lowByte(dat[1]));
//            Serial.write(highByte(dat[1]));
//            Serial.write('\r');
//            Serial.write('f');
//            Serial.write(lowByte(dat[2]));
//            Serial.write(highByte(dat[2]));
//            Serial.write('\r');
//            Serial.write('\r');
//            break;
//          case '3': network.read(header, &dat, sizeof(dat));
//            Serial.write('g');
//            Serial.write(lowByte(dat[0]));
//            Serial.write(highByte(dat[0]));
//            Serial.write('\r');
//            Serial.write('h');
//            Serial.write(lowByte(dat[1]));
//            Serial.write(highByte(dat[1]));
//            Serial.write('\r');
//            Serial.write('i');
//            Serial.write(lowByte(dat[2]));
//            Serial.write(highByte(dat[2]));
//            Serial.write('\r');
//            Serial.write('\r');
//            break;
//          case '4': network.read(header, &dat, sizeof(dat));
//            Serial.write('j');
//            Serial.write(lowByte(dat[0]));
//            Serial.write(highByte(dat[0]));
//            Serial.write('\r');
//            Serial.write('k');
//            Serial.write(lowByte(dat[1]));
//            Serial.write(highByte(dat[1]));
//            Serial.write('\r');
//            Serial.write('l');
//            Serial.write(lowByte(dat[2]));
//            Serial.write(highByte(dat[2]));
//            Serial.write('\r');
//            Serial.write('\r');
//            break;
//          case '5': network.read(header, &dat, sizeof(dat));
//            Serial.write('m');
//            Serial.write(lowByte(dat[0]));
//            Serial.write(highByte(dat[0]));
//            Serial.write('\r');
//            Serial.write('n');
//            Serial.write(lowByte(dat[1]));
//            Serial.write(highByte(dat[1]));
//            Serial.write('\r');
//            Serial.write('o');
//            Serial.write(lowByte(dat[2]));
//            Serial.write(highByte(dat[2]));
//            Serial.write('\r');
//            Serial.write('\r');
//            break;
//          default: network.read(header, 0, 0);
//            Serial.println(header.type);
//            break;
        }
      }
    }

    //  if(millis() - displayTimer > 5000){
    //    displayTimer = millis();
    //    Serial.println(" ");
    //    Serial.println(F("********Assigned Addresses********"));
    //     for(int i=0; i<mesh.addrListTop; i++){
    //       Serial.print("NodeID: ");
    //       Serial.print(mesh.addrList[i].nodeID);
    //       Serial.print(" RF24Network Address: 0");
    //       Serial.println(mesh.addrList[i].address,OCT);
    //     }
    //    Serial.println(F("**********************************"));
    //  }
  }
