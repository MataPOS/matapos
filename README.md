# MataPOS

MataPOS is a robust, compact and affordable Point of Sale (POS) device with a target market of small and medium scale retail outlets across the world. The project is part of a continous assessment for Real-time Embedded Programming course taken by masters students at the prestigious University of Glasgow in the United Kingdom. The design will demonstrate the power and dynamism of the Raspberry Pi with C++ codes in performing real-time operations that would be beneficial to the intended market.

## Initiated By

[Avinash Krishnan](https://github.com/avinashkrishnan2020)  
[Oluwatobi Abass A.](https://github.com/Tobiabass11)  
[Muktansh Chaturvedi](https://github.com/muktansh)  
[Abubakar Yusuf](https://github.com/fatherofcamels)

## Follow us on


## Install dependencies

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
  Read more about ZBar on: https://zbar.sourceforge.net/
```bash
sudo apt-get install libzbar-dev libzbar0
```
## Setup on Linux

After installing all dependencies as described above, follow below instructions to get the project running.

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
## Run tests

* Build project as instructed above.
* go to build directory and enter the following command
```bash
ctest
```

## Usage

```cpp

```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
