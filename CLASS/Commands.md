# Linux Commands

- cd ~/esp/esp-idf : ~ will take back to home, then proceed from home.

- whoami : To see the user.

- make -j(no. of processors) : For parallel compilation in esp32, compilation using all the proceaaors(CPU).

- cp -R : To copy the whole content of the directory.

# Commands To Set-Up esp32 IDF

- **Step- 1:** sudo apt-get install git wget flex bison gperf python3 python3-pip python3-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0

- **Step- 2:** sudo usermod -a -G dialout $USER

- **Step- 3:** mkdir -p ~/esp

- **Step- 4:** cd ~/esp

- **Step- 5:** git clone --recursive https://github.com/espressif/esp-idf.git

- **Step- 6:** cd ~/esp/esp-idf

- **Step- 7:** ./install.sh esp32  : Everytime run this command when env | grep IDF is not showing.

- **Step- 8:** $HOME/esp/esp-idf/export.sh   : Setting IDF_PATH to '/home/surya/esp/esp-idf'

- **Step- 9:** idf.py build  : To build the code.


- . $HOME/esp/esp-idf/export.sh

- lsusb

- ls -al /dev/ttyUSB* : To check usp port number for esp32 board connected.

- idf.py build

- idf.py -p /dev/ttyUSB0 flash


- ls -al /dev/ttyUSB*
- idf.py fullclean
- sudo chmod 777 /dev/ttyUSB0 : For all permissions.

- vTaskDelay(1000 / portTICK_PERIOD_MS)

# Files Required For esp23 IDF Project

- CMakeLists.txt

    - The following lines of boilerplate have to be in your project's

    - CMakeLists in this exact order for cmake to work correctly 

    - *cmake_minimum_required(VERSION 3.5)*

    - *include($ENV{IDF_PATH}/tools/cmake/project.cmake)*

    - *project(tasks)*

- main

    - CMakeLists.txt **idf_component_register(SRCS "source_code.c" INCLUDE_DIRS "")**

    - source_code.c

# Commands To Build & Flash Project In esp32

**. $HOME/esp/esp-idf/export.sh** : Run inside the project directory once in a cmd window. No need if already put in **vi ~/.profile**.

- **Step- 1:** *cd ~/esp/hello_world* : Go to project directory

- **Step- 2:** *idf.py set-target esp32* : Set as esp32 project.

- **Step- 3:** *idf.py menuconfig* : To load *O* and generate *sdkconfig* file. If you want to customize it. Like setting baude rate, tick rate, enable/disable bluetooth etc..

- **Step- 4:** *idf.py build* : To build the project(code).

- **Step- 5:** Keep pressing the boot button on the esp32 boad while flashing the code.

- **Step- 6:** *idf.py -p /dev/ttyUSB0 flash* : To flash code(executable) in esp32.

- **Step- 7:** *idf.py -p /dev/ttyUSB0 monitor* : To check if “hello_world” is indeed running.

- STEP 6 & 7 CAN BE COMBINED BY *idf.py -p /dev/ttyUSB0 flash monitor* 

    - Keep pressing the boot button on the esp32 boad while flashing the code.

    - After *waiting for download* shown on terminal, press the EN(enable) button on the esp32 board.

- **Step- 8:** *ctrl + ]* : To exit

# Setting up FREERTOS

- **DOWNLOAD THE FILES:** 

    - *FreeRTOSv202112.00* --> https://www.freertos.org/

    - *code_1.63.2-1639562499_amd64.deb* (Debian file) --> https://packages.microsoft.com/repos/code/pool/main/c/code/

- **Step- 1** Move the downloaded FREERTOS file

- **Step- 2** sudo dpkg -i code_1.63.2-1639562499_amd64.deb

- **Step- 3** *export FREERTOS_PATH=~/FREERTOSv202112.00* : Setting path for FREERTOS.

- **Step- 4** *echo $FREERTOS_PATH* : Checking assigned path for FREERTOS.




