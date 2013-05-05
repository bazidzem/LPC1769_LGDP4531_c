######################################################################################################
There is nothing to install. But there are some requiremets for this software to
compile and run:

   - CodeSourcery (Sourcery G++ Lite 2011.03-42) 4.5.2 with compiler GNU toolchain for ARM
   - GNU Make 3.81 for makefile
   - Doxygen 1.72 for documentation generation
   - libusb 0.1.8 Library for talking to USB devices from user-space. 
     Needed by libftdi, libusb-devel must be installed as well   
   - libftdi-0.19 Open Source FTDI driver. Install also libftdi-dev. By default this is intalled in /usr/local/include and in /usr/local/lib and those are not considered as global include paths by OPENOCD. So this need to be done manually by editiong ~/.profile file. Please add following:
if [ -d "/usr/local/include" ]; then
  PATH="/usr/local/include:$PATH"
fi

if [ -d "/usr/local/lib" ]; then
  PATH="/usr/local/lib:$PATH"
fi    

if [ -d "/usr/include/" ]; then
  PATH="/usr/include/:$PATH"
fi

if [ -d "/usr/lib/" ]; then
  PATH="/usr/lib/:$PATH"
fi    
   - then after libftdi and libusb is installed you can install openocd but remember to configure with option "./configure --enable-ft2232_libftdi"

######################################################################################################
If you are using Linux ( as we use Ubutu 11.04 ) additional action is required to get the access to USB (no needed for root)

   1. create file "10-ft2232-libftdi.rules"
   2. print in to the file following content:
     ATTRS{idProduct}=="baf8", ATTRS{idVendor}=="0403", MODE="666", GROUP="plugdev"
   3. move the file 10-ft2232-libftdi.rules under /etc/udev/rules.d 
   4. reload udev rules by: sudo udevadm trigger
   
######################################################################################################     
    Setup of eclipse(optional): TODO

