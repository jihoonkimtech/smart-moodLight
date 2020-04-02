# 아두이노 스마트 무드등
> 아두이노를 이용한 블루투스 원격 제어 무드등 프로젝트 입니다.

[ENGLISH VERSION](https://github.com/jihoonkimtech/smart-moodLight/blob/master/README.md)

<!-- NPM Version -->
<!-- Build Status -->
[![NPM Version][npm-image]][npm-url]    [![Build Status][travis-image]][travis-url]

MIT 라이센스를 준수합니다. ( 더 자세한 정보는 ``LICENSE``를 참고하세요 ) 

<br>

## 설정

#### 핀 설정
- Bluetooth Pins Set-up
```C++
    #define BT_TX 6 //블루투스 모듈의 TX 핀
    #define BT_RX 7 //블루투스 모듈의 RX 핀
```
- RGB LED Pins Set-up
```C++
    #define COLOR_R_PIN 9  //RGB LED의 RED 핀
    #define COLOR_G_PIN 10 //RGB LED의 GREEN 핀
    #define COLOR_B_PIN 11 //RGB LED의 BLUE 핀
```
#### 통신 속도 설정 
- Serial Communication Baudrate Set-up
```C++
    Serial.begin(9600);         //아두이노 직렬 통신의 보 레이트
    myBluetooth.begin(9600);    //블루투스 모듈의 보 레이트
```

#### 필요 부품
- 블루투스 모듈
- 공통 캐소드 RGB LED

<br>

### 어플리케이션
#### 설치 방법
- ``Application`` 폴더 내의 어플리케이션 파일을 이용해 설치하시면 됩니다. 

#### 기능
- 블루투스 연결
- RGB LED의 색상 변경 ( 픽커를 사용합니다 )

<br>

## Update History

* 1.2.0
    * 불필요한 기능들 제거
* 1.1.0
    * 첫 릴리즈
* 1.0.0
    * 개발 시작

<br>

## 정보
### 제작
- Jihoon Kim ([jihoonkimtech](https://jihoonkimtech.github.io/), [jihoonkimtech@naver.com](mailto:jihoonkimtech@naver.com))




<!-- Markdown link & img dfn's -->
[npm-image]: https://img.shields.io/npm/v/datadog-metrics.svg?style=flat-square
[npm-url]: https://npmjs.org/package/datadog-metrics
[npm-downloads]: https://img.shields.io/npm/dm/datadog-metrics.svg?style=flat-square
[travis-image]: https://img.shields.io/travis/dbader/node-datadog-metrics/master.svg?style=flat-square
[travis-url]: https://travis-ci.org/dbader/node-datadog-metrics
[wiki]: https://github.com/yourname/yourproject/wiki