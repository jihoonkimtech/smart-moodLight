# Arduino Smart Mood-Light
![](picture.jpg)
> this project is Bluetooth control MoodLight made of Arduino.

[KOREAN VERSION](https://github.com/jihoonkimtech/smart-moodLight/blob/master/README_kor.md)

<!-- NPM Version -->
<!-- Build Status -->
[![NPM Version][npm-image]][npm-url]    [![Build Status][travis-image]][travis-url]

Follows the MIT license ( Please check ``LICENSE`` file for more information. ) 

<br>

## Set-up

#### Changing Pins
- Bluetooth Pins Set-up
```C++
    #define BT_TX 6 //module tx pin
    #define BT_RX 7 //module rx pin
```
- RGB LED Pins Set-up
```C++
    #define COLOR_R_PIN 9  //red pin
    #define COLOR_G_PIN 10 //green pin
    #define COLOR_B_PIN 11 //blue pin
```
#### Baud rate Set-up
- Serial Communication Baudrate Set-up
```C++
    Serial.begin(9600);         //Serial's Baud rate
    myBluetooth.begin(9600);    //Bluetooth Module's Baud rate
```

#### Used Parts
- Bluetooth Module
- Common Cathode RGB LED (or Module)

<br>

### Application
#### How to use?
- Installing applications in folder ``Application`` 

#### Function
- Bluetooth Connecting
- Color Changing (use Circle Picker)

<br>

## Update History

* 1.2.0
    * Remove unnecessary function
* 1.1.0
    * First release
* 1.0.0
    * Start develop

<br>

## Information
### Maker
- Jihoon Kim ([jihoonkimtech](https://jihoonkimtech.github.io/), [jihoonkimtech@naver.com](mailto:jihoonkimtech@naver.com))




<!-- Markdown link & img dfn's -->
[npm-image]: https://img.shields.io/npm/v/datadog-metrics.svg?style=flat-square
[npm-url]: https://npmjs.org/package/datadog-metrics
[npm-downloads]: https://img.shields.io/npm/dm/datadog-metrics.svg?style=flat-square
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://github.com/yourname/yourproject/wiki