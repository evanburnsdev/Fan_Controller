#include "main.h"




int main(int argc, char *argv[])
{

	if(argc != 3){
		std::cout << "Please enter two numbers, [fan speed]..." << std::endl;
		return -1;
	}
	std::ofstream usb0 = init();
	unsigned char speed = 0;
	unsigned int speedInt = 0;
	unsigned char fan = 0;
	unsigned int fanInt = 0;
	//std::cout << "Enter Fan:" << std::endl;
	//std::cin >> fanInt;
	fanInt = static_cast<unsigned int>(atoi(argv[1]));
	//std::cout << "Enter Speed:" << std::endl;
	//std::cin >> speedInt;
	speedInt = static_cast<unsigned int>(atoi(argv[2]));
	fan = static_cast<unsigned char>(fanInt);
	speed = static_cast<unsigned char>(speedInt);
	//std::cout << "Entered: " << static_cast<unsigned short> (test) << std::endl;
	usb0 << fan;
	usb0 << speed;
	usb0.flush();
	//std::cout << "Sent: " << test << std::endl;
}


std::ofstream init(){
	std::ofstream usb = std::ofstream("/dev/ttyUSB0");
	if(int i = system("stty -F /dev/ttyUSB0 115200 \
parenb -parodd cs8 -hupcl cstopb cread clocal -crtscts \
-iuclc -ixany -imaxbel -iutf8 -opost -olcuc -ocrnl \
-onlcr -onocr -onlret -ofill -ofdel nl0 cr0 tab0 bs0 \
vt0 ff0 -isig -icanon -iexten -echo -echoe -echok -echonl \
-noflsh -xcase -tostop -echoprt -echoctl -echoke") == -1)
	{
		std::cout << "Didn't set up UART: " << i << std::endl;
	};
	return usb;
}
