#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdint.h>
#include <iconv.h>

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#define yellow      "\033[33m"
#define none        "\033[0m"
#define ITEMCAP (50U);

typedef struct _sAttribute {
	// block 0
	uint16_t stamina;
	uint16_t strnth;
	uint16_t intell;
	uint16_t elegance;
	uint16_t glamour;
	uint16_t morality;
	uint16_t faith;
	uint16_t karma;
	uint16_t senstv;
	uint16_t stress;
	uint16_t reserve;
	// block 1
	uint16_t war_rep;
	uint16_t magic_rep;
	uint16_t social_rep;
	uint16_t housework_rep;
	// block 2
	uint16_t war_skill;
	uint16_t attack;
	uint16_t def;
	uint16_t mag_skill;
	uint16_t mag_atk;
	uint16_t mag_def;
	// block 3
	uint16_t manner;
	uint16_t art;
	uint16_t speech;
	uint16_t cooking;
	uint16_t housework;
	uint16_t personal;
}Attribute;

void print_att_0(Attribute *att);
void health_modify(uint16_t *health);
void attr_modify(Attribute *att);
void money_modify(uint32_t *money);

typedef struct _Item {
    uint16_t id;
    uint16_t cost;
//泰維說： armor 1000(E8 03), weapon 2000(D0 07) cloth 3000(B8 0B), accessory 4000(A0 0F)  
    uint16_t type;  //笑死 神秘的8001跟8000
    uint16_t reserve;
    char name[16];
    uint16_t loc_point; // 0x0040 "@ " 
    char effect_en[66];
    char effect_zh[18];
} items;  // size 110 Byte 
//為啥EN的部分66字元?為啥ZH的部分18字元?爽

typedef struct _string{
    char name[16];
}STRING;