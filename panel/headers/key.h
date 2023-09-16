#ifndef _KEY
#define _KEY
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

key_t creo_clave(int r_clave);

#endif