#pragma once

#include <stdint.h>

typedef struct _sTest
{
    uint8_t version;
    uint8_t ihl;
    uint8_t typeofservice;
    uint16_t totallength;
    uint16_t identification;
    uint8_t flags;
    uint16_t fragmentoffset;
    uint8_t timetolive;
    uint8_t protocol;
    uint16_t headerchecksum;
    uint32_t sourceaddress;
    uint32_t destinationaddress;
    uint32_t options;
    uint8_t padding;
}Test;

Test * iph_init( void );
void iph_free( Test * );
int iph_encode( void *, const Test * );
int iph_decode( const void *, Test * );
