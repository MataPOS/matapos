<!-- PROJECT LOGO -->
<br />
<div align="center">
 <img src="https://github.com/MataPOS/matapos/blob/main/lib/window/src/Logo.png" alt="logo" width="400" div al ign=center />
 </br>
 Matapos is here to help you small businesses around the world with affordable payment solution!
 </br>
 </br>
 
![Contributors](https://img.shields.io/github/contributors/tobiabass11/matapos?style=for-the-badge)
![Github Repo stars](https://img.shields.io/github/stars/matapos/matapos?style=for-the-badge)
![Issues](https://img.shields.io/github/issues-raw/tobiabass11/matapos?style=for-the-badge)
[![License](https://img.shields.io/github/license/matapos/matapos?style=for-the-badge)](https://github.com/MataPOS/matapos/blob/main/LICENSE)
 <br />
 <a href="https://github.com/MataPOS/matapos/issues">Report Bug</a>
    .
    <a href="https://github.com/MataPOS/matapos/issues">Request Feature</a>
 <br />

![Branch checks state](https://img.shields.io/github/checks-status/tobiabass11/matapos/main?style=flat-square)
![Commits reader](https://img.shields.io/github/commit-activity/m/matapos/matapos?style=flat-square)

MataPOS is a robust, compact and affordable Point of Sale (POS) device with a target market of small and medium scale retail outlets across the world. The project is part of a continous assessment for Real-time Embedded Programming course taken by masters students at the prestigious University of Glasgow in the United Kingdom. The design will demonstrate the power and dynamism of the Raspberry Pi with C++ codes in performing real-time operations that would be beneficial to the intended market.

# Install dependencies

* Install pigpio
```bash
sudo apt-get install libpigpio-dev
```

* Install Qt
```bash
sudo apt-get install qtdeclarative5-dev-tools
sudo apt-get install libqwt-qt5-dev
```

* Install OpenCV
```bash
sudo apt install libopencv-dev
```

* Install ZBar on your system which is used to read barcodes/qr codes
```bash
sudo apt-get install libzbar-dev libzbar0
```

# Setup on Linux 👨‍💻

* Fork this repo to your github account.
* Clone it to your local machine.
* Create a 'build' directory in root directory matapos.
```bash
mkdir build
```
* Go to the build directory and run following commands to build the project.
```bash
cd build
cmake ..
make
./app/matapos
```
# Run tests

* Build project as instructed above.
* go to build directory and enter the following command
```bash
ctest
```


# Contributing 

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## Social Media 🌐
Keep up to date with Matapos! Find us on all our social channels:
</br>

<p align="center">
<a href="https://twitter.com/MataPos" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/twitter.svg" alt="signups" height="150" width="100" /></a>·
   <a href="https://www.instagram.com/matapos15" target="blank"><img align="center" src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e7/Instagram_logo_2016.svg/1024px-Instagram_logo_2016.svg.png" alt="instagram" height="100" width="100" /></a> 

</p>

# Technologies ⚙️
MataPOS is built using:
- [C++ Programming Language](https://www.cplusplus.com/)
- [Debian/Ubuntu Linux](https://www.linux.org/)
- [Raspberry Pi](https://www.raspberrypi.org)
- [Cmake](https://cmake.org/)
- [OpenCV](https://opencv.org/)
- [Google Test](https://github.com/google/googletest)
- [Doxygen](https://www.doxygen.nl/index.html)
- [Qt](https://www.qt.io/)

<!-- LICENSE -->

# License 📰

Distributed under the LGPL-2.1 License. See [`LICENSE`](https://github.com/MataPOS/matapos/blob/main/LICENSE) for more information.

# Contact Us 📞
- 🔭This project is being completed by a team of students at the University of Glasgow :
  * [Avinansh Krishnan](https://github.com/avinashkrishnan2020)
  * [Oluwatobi Abass A.](https://github.com/Tobiabass11) 
  * [Muktansh Chaturvedi](https://github.com/muktansh)
  * [Abubakar Yusuf](https://github.com/fatherofcamels)
- 📫 Email: **matapos15@gmail.com**

