#ifndef _INCLUDE_FUNCTIONS_H
#define _INCLUDE_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/*Kbit arate*/
//#include "spatiallib.h"
#include <termios.h>
#include <fcntl.h>
#include <unistd.h>

#include <math.h>
#include <sys/time.h>                // for gettimeofday()
#include <alsa/asoundlib.h>

#include <stdbool.h> /*for true and false*/

/*Reproducing*/
#include "./../include/spatiallib.h"
#include "./../include/superwavlib.h"

//Thread
#include <pthread.h>

typedef struct Arg_thread_TAG{

    long long timeToStart;
    int flag;
    int finishPlaying;

} Arg_thread;

#define TRUE   1
#define FALSE  0

long long current_timestamp();
void error(const char *msg);
int kbhit(void);
int changeFlag(int flag);

long long timeToStartInSeconds(int s);
long long timeToStartInMilisecons(int m);

/*Mejorar el codigo del envío de parametros (varios parametros en un string)*/
#include <string.h>
#include <assert.h>
char** str_split(char* a_str, const char a_delim);

void* playSuperWav(void *arguments) ;

#endif