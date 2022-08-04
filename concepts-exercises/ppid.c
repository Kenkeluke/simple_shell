#include "main.h"
/**
 * my_ppid - a function that priint the parent process
 * Id of the current process
 *
 *
 */
pid_t my_ppid(void)
{
pid_t ppid = getppid();


printf("%u is my ppid not yet pid\n", ppid);
}

