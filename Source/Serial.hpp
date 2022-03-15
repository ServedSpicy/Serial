#ifndef Header_Serial
#define Header_Serial

#include <cinttypes>


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

int synchronize(const uint8_t * device,const uint8_t * bytes,const short int size);


#endif
