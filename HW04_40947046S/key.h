#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include <ctype.h>

#define yellow      "\033[33m"
#define blue        "\033[34m"
#define light       "\033[36m"
#define none        "\033[0m"

void print(FILE *);
void line(FILE *);
int  color(FILE *at,char *type);
int color_line(FILE *at,char *type);