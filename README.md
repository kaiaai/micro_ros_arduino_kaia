# Micro-ROS Arduino library for [Kaia.ai](https://kaia.ai) robots platform

This is a fork of [Micro-ROS Arduino library](https://github.com/micro-ROS/micro_ros_arduino)
adapted to [Kaia.ai](https://kaia.ai/)-based robots. Specifically, this adapted fork

- successfully builds on Windows PC when using `git clone` to download the library
- adds [kaia_msgs](https://github.com/kaiaai/kaia_msgs/) ROS2 package
- moves WiFi.begin() outside of the Micro-ROS library for cleaner and convenient code development
- tweaks colcon.meta to optimize library features, performance and memory usage
- sets up the library for inclusion into the Arduino Library Manager
- pre-built for ESP32 only

## Install a library release using Arduino Library Manager
- open your Arduino IDE
- select the Tools -> Manage Libraries menu
- type `kaia` in the search filter
- click Install

Keep in mind that this library is pre-built for ESP32 platform only. If you would like to use it with another platform, see instructions below on how to modify and rebuild the library. In particular, try omitting `-p esp32` in the `docker run` command.

## Install a library release by .zip download
- Navigate to the [release section](https://github.com/kaiaai/micro_ros_arduino_kaia/releases)
and download the latest `micro_ros_arduino_kaia_prebuilt.zip` release
- Launch your Arduino IDE, open the Sketch -> Include library -> Add .ZIP Library... menu and
select the downloaded `kaia_arduino_lib_prebuilt.zip` file
- In your Arduino IDE, configure Tools -> Board as "ESP32 Dev Module" and leave the board settings at their defaults

## Install library using git
Alternatively, you can `git clone` this library as follows. This method may be useful if you need to edit library files or check out different versions of the library.
- confirm the location of your Arduino sketches by opening File -> Preferences in
your Windows Arduino IDE and noting the path "Sketchbook location" path, for example `C:\Users\YOUR-USER-NAME\Documents\Arduino`
- append `\libraries` to the sketchbook location path to get the path to your Arduino libraries,
e.g. `C:\Users\YOUR-USER-NAME\Documents\Arduino\libraries`
- make sure you have installed [Git for Windows](https://gitforwindows.org/) or a similar Windows Git tool
- run commands below in a Windows shell to clone this library to your Windows PC
```
cmd.exe
cd %HOMEPATH%\Documents\Arduino\libraries
git clone -b humble --depth 1 --recurse-submodules https://github.com/kaiaai/micro_ros_arduino_kaia micro_ros_kaia
```

Now you can include this library into your sketch using `#include <micro_ros_arduino_kaia.h>`.

## API tweaks
Now you can handle connecting to WiFi as you see fit, instead of Micro-ROS doing this for you. For example:
```
  WiFi.begin(ssid, passw);
  Serial.print("Connecting to WiFi ");

  unsigned long startMillis = millis();
  while (WiFi.status() != WL_CONNECTED) {
    if (millis() - startMillis >= 10000) {
      Serial.println(" timed out");
      return;
    }
    Serial.print('.'); // Don't use F('.'), it crashes ESP32
    delay(500);
  }

  Serial.println(F(" connected"));
  Serial.print(F("IP "));
  Serial.println(WiFi.localIP());

  set_microros_wifi_transports("192.168.1.57", 8888); // Micro-ROS setup
```


## Kaia.ai Arduino ESP32 firmware
Download the Kaia.ai firmware project code from the [Kaia.ai Arduino firmware repo](https://github.com/kaiaai/kaia_arduino_fw),
open the downloaded kaia_esp32.ino project file in your Arduino IDE and click the build button.
The project should build successfully. At this point, feel free to burn your ESP32 module with the compiled code and/or modify the firmware to your liking.

## Extend, modify and rebuild Micro-ROS Arduino library for Kaia.ai
In some cases, tayloring [Kaia.ai](https://kaia.ai/) software to your particular robot may require tweaking the Kaia.ai library code in addition to the Kaia.ai firmware - for example to add new types of Micro-ROS messages. Follow these steps to [extend and/or adapt](https://micro.ros.org/docs/tutorials/advanced/create_new_type/) and rebuild the Kaia.ai Arduino library on Windows for your particular robot design.
- Install Docker for your PC platform, e.g. [Docker for Windows](https://docs.docker.com/desktop/install/windows-install/) and make sure the Docker agent is running
- Install the [Micro-ROS Arduino library for Kaia.ai](https://github.com/kaiaai/micro_ros_arduino_kaia/) using the instructions above. Let's assume you are using Arduino IDE for Windows and your Arduino libraries are stored under `C:\Users\YOUR-USER-NAME\Documents\Arduino\libraries`.
- Open a Windows command shell and run these commands to rebuild the library using the [Micro-ROS library builder](https://github.com/micro-ROS/micro_ros_arduino):
```
cmd.exe
cd %HOMEPATH%\Documents\Arduino\libraries
git clone -b humble --depth 1 --recurse-submodules https://github.com/kaiaai/micro_ros_arduino_kaia micro_ros_kaia
docker run -it --rm -v .\micro_ros_kaia:/project --env MICROROS_LIBRARY_FOLDER=extras microros/micro_ros_static_library_builder:humble -p esp32
```
