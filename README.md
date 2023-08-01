# iotArduino Project

## Overview
This project utliizes an Arudino Uno, with both infrared receiver and transmittor circuits to obtain and send IR readings to a remote-controlled fan. 

Using the IRremote library and the IRreceieveDump sketch, I obtained readings from an IR remote that controls a standing room fan. Using the timings and values obtained from this remote, I created an IR transmittor circuit that emitts these same values.

Designing a web interface using the Vue.js javascript framework and Vuetify component framework, I designed a webpage to control the Arduino through the UART serial interface via a Javascript WebSerial library. 

![Demo][product-screenshot]

### Web Frameworks Used
* Vue.js <img src="https://segwitz.com/wp-content/uploads/2021/06/vuejs-development-malaysia.jpeg" alt="vuejs" width="100"/>
* Vuetify <img src="https://cdn.vuetifyjs.com/docs/images/logos/vuetify-logo-v3-slim-text-light.svg" alt="vuetify" width="100"/>
* Sweetalert2 <img src="https://raw.githubusercontent.com/sweetalert2/sweetalert2/HEAD/assets/swal2-logo.png" alt="sweetalert2" width="100"/>

## Hardware Partslist
* 2 IR LEDs
* 2 36 ohm reistors
* 1 NPM Transistor
* 1 IR Receiver (38 kHz)
* 1 1k ohm resistor
* 1 Arduino Uno

![Circuit-picture][circuit-picture]

2 IR LEDs are used in parallel to provide a larger singal transmission range. The npm transistor acts as a current amplifier, mitigating the maximum current draw of the Arudino I/O pins. The receiver and transmittor can be connected at the same time to the board as they use different I/O pins.


## Using this Repo
To run the arduino code, first install and configure the IRremote library using the Arduino IDE. Run the IRreceiveDump example that comes with the library to obtain readings from whichever device/remote you are using, utilizing the IR receiver. This program will identify and output the IR protocol and values to the serial console.

After obtaining these readings, modify the SimpleSender.ino sketch as necessary to work with your device. 

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

I included a few resources I used to help me design this project. Check out the following links to learn more about the frameworks and componenets I used.

* [WebSerial Javascript API](https://makeabilitylab.github.io/physcomp/communication/web-serial.html)
* [Dijikey Partslist](https://www.digikey.ca/en/maker/blogs/2021/how-to-send-and-receive-ir-signals-with-a-raspberry-pi)
* [Arduino IRremote Library Tutorial](https://randomnerdtutorials.com/arduino-ir-remote-control/)
* [Vuetify API Documentation](https://vuetifyjs.com/en/getting-started/installation/)


<!-- MARKDOWN LINKS & IMAGES -->
[product-screenshot]: images/uiDemo.png
[circuit-picture]: images/IMG_1640.jpg
[vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D
[vuetfy]: https://cdn.vuetifyjs.com/docs/images/logos/vuetify-logo-v3-slim-text-light.svg
[sweetalert2]: https://raw.githubusercontent.com/sweetalert2/sweetalert2/HEAD/assets/swal2-logo.png
