#include <iostream>
#include <string>
using namespace std;

class TV {
	int size;
public:
	//TV() { size = 20; }
	TV(int size) { 
		cout << "TV(" << size << ")" << endl;
		this->size = size; }
	int getSize() { return size; }
};

class WideTV : public TV {
	bool videoIn;
public:
	WideTV(int size, bool videoIn) : TV(size) {
		cout << "WideTv(" << size << "," << boolalpha << videoIn << ")" << endl;
		this->videoIn = videoIn;
	}
	bool getVideoIn() { return videoIn; }
};

class SmartTV : public WideTV {
	string ipAddr;
public:
	SmartTV(string ipAddr, int size) : WideTV(size, true) {
		cout << "SmartTV(" << ipAddr << "," << size << ")" << endl;
		this->ipAddr = ipAddr;
	}
	string getIpAddr() { return ipAddr; }
};

int main() {

	SmartTV htv("192.0.0.1", 32);
	cout << "size=" << htv.getSize() << endl;
	cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
	cout << "IP=" << htv.getIpAddr() << endl;


	return 0;
}