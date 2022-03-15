
#include <SerialPortConstants.h>
#include <SerialStream.h>
#include <SerialPort.h>
#include <exception>
#include <iostream>
#include <fstream>
#include <cstdint>
#include <string>
#include <chrono>


using namespace std;
using namespace LibSerial;


#define cycle while(true)

#define finish(exitCode) {  \
        serial.Close();     \
        return (exitCode);  \
    }


const auto SearchTimeout = 2000UL;


using namespace chrono;
using Clock = chrono::system_clock;

unsigned long millis(){
    return time_point_cast<milliseconds>(Clock::now())
        .time_since_epoch()
        .count();
}

SerialPort connect(const char * device){
    return SerialPort(
		device,
		BaudRate::BAUD_9600,
		CharacterSize::CHAR_SIZE_8,
		FlowControl::FLOW_CONTROL_NONE,
		Parity::PARITY_NONE,
		StopBits::STOP_BITS_1
	);
}


#ifdef Testing

#include "Serial.hpp"

#else

extern "C" {

#endif


    /**
     * @brief Synchronizes the machine controller
     * @details Sends the given bytes to be saved in the controllers EEPROM
     * @warning At max, 1024 bytes can be sent
     *
     * @return
     *   1 = Success
     *   0 = Unknown Error
     *  -1 = Timeout
     *  -2 = Machine Not Ready
     */

    int synchronize(const uint8_t * device,const uint8_t * bytes,const short int size){

        try {

            cout << "Using device : " << device << endl;

            cout << "Starting Syncronization" << endl;


            auto serial = connect((char *) device);


            cout << "Connected To Machine" << endl;

            cout << "Waiting For Status" << endl;


            const auto start = millis();

            cycle {

                if(serial.IsDataAvailable())
                    break;

                if(millis() - start > SearchTimeout)
                    finish(-1);
            }


            cout << "Status Available" << endl;


            char status;
            serial.ReadByte(status);


            cout << "Machine Status : " << status << endl;


            if(status != 1)
                finish(-2);


            cout << "Machine Ready To Receive" << endl;


            serial.WriteByte((unsigned char) '1'); // Switch to Sync Mode


            cout << "Sending " << size << " Bytes" << endl;


            for(int b = 0;b < size;b++)
                serial.WriteByte((unsigned char) bytes[b]);


            cout << "Data Sent" << endl;


            finish(1);

        } catch (const exception & error){
            cerr << "Error : " << error.what() << endl;
            return 0;
        }
    }


#ifndef Testing

}

#endif


