# iotArduino Project

## Overview
This project utliizes an Arudino Uno, with both infrared receiver and transmittor circuits to obtain and send IR readings to a remote-controlled fan. 

Using the IRremote library and the IRreceieveDump sketch, I obtained readings from an IR remote that controls a standing room fan. Using the timings and values obtained from this remote, I created an IR transmittor circuit that emitts these same values.

Designing a web interface using the Vue.js javascript framework and Vuetify component framework, I designed a webpage to control the Arduino through the UART serial interface via a Javascript WebSerial library. 

[product-screenshot]
[[Vue.js]

## Overview

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

I included a few resources I used to help me design this project. Check out the following links to learn more about the frameworks and componenets I used.

* [WebSerial Javascript API](https://makeabilitylab.github.io/physcomp/communication/web-serial.html)
* [Dijikey Partslist](https://www.digikey.ca/en/maker/blogs/2021/how-to-send-and-receive-ir-signals-with-a-raspberry-pi)
* [Arduino IRremote Library Tutorial](https://randomnerdtutorials.com/arduino-ir-remote-control/)
* [Vuetify API Documentation](https://vuetifyjs.com/en/getting-started/installation/)


<!-- MARKDOWN LINKS & IMAGES -->
[product-screenshot]: images/uiDemo.png
[Vue.js]: https://img.shields.io/badge/Vue.js-35495E?style=for-the-badge&logo=vuedotjs&logoColor=4FC08D