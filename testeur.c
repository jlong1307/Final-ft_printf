#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <wchar.h>
#include <stdio.h>

int	main(void)
{
	char lapin[] = "lolmdrxp";

	char *loup;

	loup = lapin;

	printf("%p",loup);
	return 0;
}