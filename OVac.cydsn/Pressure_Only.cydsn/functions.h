/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <FS.h>
#include <stdbool.h>

#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
    
#define COMMANDS "\ncommands: \n05,start\n" \
                 "05,reset\n" \
                 "04,data\n" \
                 "05,depth"            
    
#define COMMANDS_LEN 46
    
#define STATE_WAITING "STATE: WAIT_TO_LAUNCH\n"
#define WAITING_LEN 24
    
#define SEND_DEPTH "Enter desired depth:"
#define SEND_DEPTH_LEN 20
    
#define STATE_DESCENDING "\nSTATE: DESCENDING\n"
#define DESCENDING_LEN 19
    
#define STATE_LANDED "STATE: LANDED\n"
#define LANDED_LEN 14
    
#define STATE_VACUUM "STATE: VACUUMING\n"
#define VACUUM_LEN 17
    
#define STATE_RESURFACE "STATE: RESURFACE\n"
#define RESURFACE_LEN 17
    
#define STATE_TRANSMIT "STATE: TRANSMIT\n"
#define TRANSMIT_LEN 16
   
#define TRANSMITTING "Transmitting data\n"
#define TRANSMITTING_LEN 18
    
/*State Declarations*/
typedef enum STATES{
    SYSTEM_CHECK, 
    WAIT_TO_LAUNCH,
    DESCENDING,
    LANDED,
    RESURFACE,
    TRANSMIT,
    ERROR
}STATES;      

float ComputeMA(float avg, int16_t n, float sample);

int BT_Process(char *RxBuffer, int bytes, int *reset);

void BT_Send(char *RxBuffer, STATES *STATE, int lengthOfBuf, int *firstPacket);

void uint8_to_char(uint8_t a[], char b[], int len);

#endif /* _FUNCTIONS_H_ */
/* [] END OF FILE */