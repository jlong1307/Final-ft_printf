

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <wchar.h>
#include <stdio.h>

#include "printfh.h"

int	main()
{
	int nbr1, nbr2;
	nbr1 = 0;
	nbr2 = 0;
	//TEST POUR %%
	printf("test pour le pourcentagex2\n");
	nbr1 = ft_printf("%%lol %%mdr----->mon printf\n");
	nbr2 = printf("%%lol %%mdr---->vrai printf\n");
	printf("%i---%i\n", nbr1, nbr2);
	//TEST POUR c
	printf("test pour char\n");
	int nbr3, nbr4;
	nbr3 = ft_printf("mon printf = %c\n", 'a');
	nbr4 = printf("vrai printf =%c\n", 'a');
	printf("%i---%i\n", nbr3, nbr4);
	//TEST POUR s et c
	printf("test pour string\n");
	char chaine[] = "j'aime les pommes et les banane";
	int nbr5, nbr6;
	nbr5 = ft_printf("mon printf = %s hello %c\n", chaine, 'a');
	nbr6 = printf("vrai printf =%s hello %c\n", chaine, 'a');
	printf("%i---%i\n", nbr5, nbr6);
	//TEST POUR i et d
	printf("test pour l int en décimal signé i et d\n");
	int nbr11, nbr12, nbr13, nbr14;
	nbr11 = ft_printf("mon printf : mon nombre est le %i et le deuxieme %d\n", 55, -55);
	nbr12 = printf("vrai printf :mon nombre est le %i et le deuxieme %d\n", 55, -55);
	printf("%i---%i\n", nbr11, nbr12);
	nbr13 = ft_printf("nombre min_int %i | %d et max_int %i | %d\n",-2147483647, -2147483647, 2147483647, 2147483647);
	nbr14 = printf("nombre min_int %i | %d et max_int %i | %d\n",-2147483647, -2147483647, 2147483647, 2147483647);
	printf("%i---%i\n", nbr13, nbr14);
	//TEST pour u
	printf("test pour u\n");
	int nbr22, nbr23;
	nbr22 = ft_printf("mon printf : mon nombre est le %u || %u\n", -489, 489);
	nbr23 = printf("vrai printf: mon nombre est le %u || %u\n", -489, 489);
	printf("%i---%i\n", nbr22, nbr23);
	//TEST POUR x
	printf("test pour x\n");
	unsigned int nbr66 = 0;
	while (nbr66 <= 100)
	{
		printf("le nombre en décimal : %i et en hexa %x \n", nbr66, nbr66);
		printf("mon printf----------------------------\n");
		ft_printf("le nombre en décimal : %i et en hexa %x \n", nbr66, nbr66);
		printf(" \n");
		nbr66++;
	}

	//TEST pour 
	printf("test pour p\n");

	int var = 78;
	int *lol = &var;
	printf("Adresse de ma variable %p\n", lol);
	ft_printf("Adresse de ma variable %p\n", lol);
	return (0);
}
