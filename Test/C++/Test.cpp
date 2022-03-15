#include <iostream>
#include <vector>
#include <string>

#include "Serial.hpp"


using namespace std;


int main(int,char const * []){

	string default_filename = "/dev/ttyUSB0";
	string serial_filename = "";

	cout << "Enter the name of the serial file (default: " << default_filename << " )" << endl;
	getline(cin, serial_filename);

	if(serial_filename.empty())
	{
		cout << "Using default serial file : " << default_filename << endl;
		serial_filename = default_filename;
	}

	int bytecount = 12;

    int a = bytecount >> 4;
    int b = bytecount & 255;


    const string s = "Hello Worl3";



    vector<uint8_t> bytes = { (uint8_t) a , (uint8_t) b , (uint8_t) 11 };
    bytes.insert(bytes.end(),s.begin(),s.end());

    const auto bs = bytes.data();

    cout << "Byte Composition : " << bs << endl;

    const auto code = synchronize((uint8_t *) "/dev/ttyUSB0",(uint8_t *) bs,14);

    cout << "ExitCode : " << code << endl;

    switch(code){
    case 1:
        cout << "Success" << endl;
        break;
    case 0:
        cout << "Unknown Error" << endl;
        break;
    case -1:
        cout << "Timeout" << endl;
        break;
    case -2:
        cout << "Machine Not Ready" << endl;
        break;
    }

    return 0;
}
