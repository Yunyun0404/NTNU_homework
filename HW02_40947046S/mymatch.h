#pragma once
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

int mymatch(char ***pppList , const char *pStr, const char *pPattern);
int recursive(char *s,char *p,int i,int j);