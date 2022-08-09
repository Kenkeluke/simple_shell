#include "main.h"
/**
 * my_ppid - a function that priint the parent process
 * Id of the current process
 *
 *
 */

int main(void)
{
char *args = split(line_reader());
printf("%s", args);

exec(&args);

    return(0);
}