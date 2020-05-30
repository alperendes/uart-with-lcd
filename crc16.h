

/*
 * crc16.h
 *
 *  Created on: 8 Oca 2020
 *      Author: koray
 */

#ifndef CRC16_H_
#define CRC16_H_
unsigned int pos;
int i;
unsigned short crc;
unsigned int len;
unsigned short mod_rtu_crc(char* bytes, int len)
{
    crc = 65535;

  for(pos = 0; pos < len; pos++){
    crc ^= (unsigned short)bytes[pos];          // XOR byte into least sig. byte of crc

    for(i = 8; i != 0; i--){    // Loop over each bit
      if((crc & 0x0001) != 0){      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      }
      else{                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
      }
    }
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)

}
return crc;
}



#endif /* CRC16_H_ */
