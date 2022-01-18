# Linux Commands

- cd ~/esp/esp-idf : ~ will take back to home, then proceed from home.

# Commands To Set-Up esp32 IDF

- **Step- 1:** sudo apt-get install git wget flex bison gperf python3 python3-pip python3-setuptools cmake ninja-build ccache libffi-dev libssl-dev dfu-util libusb-1.0-0

- **Step- 2:** sudo usermod -a -G dialout $USER

- **Step- 3:** mkdir -p ~/esp

- **Step- 4:** cd ~/esp

- **Step- 5:** git clone --recursive https://github.com/espressif/esp-idf.git

- **Step- 6:** cd ~/esp/esp-idf

- **Step- 7:** ./install.sh esp32

- **Step- 8:** $HOME/esp/esp-idf/export.sh   : Setting IDF_PATH to '/home/surya/esp/esp-idf'