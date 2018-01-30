//
// Created by Andrii MAZUROK on 1/30/18.
//

#include "ft_printf.h"

int ft_onechar(unsigned int v)
{
	write(1, &v, 1);
	return (1);
}

int ft_twochar(unsigned int v, unsigned int mask1)
{
	unsigned char octet;
	unsigned char o2;
	unsigned char o1;

	o1 = ((v >> 6) << 27) >> 27;
	o2 = (v << 26) >> 26;
	octet = (mask1 >> 8) | o1;
	write(1, &octet, 1);
	octet = ((mask1 << 24) >> 24) | o2;
	write(1, &octet, 1);
	return (2);
}

int ft_threechar(unsigned int v, unsigned int mask2)
{
	unsigned char octet;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o1 = ((v >> 12) << 28) >> 28;
	o2 = ((v >> 6) << 26) >> 26;
	o3 = (v << 26) >> 26;
	octet = (mask2 >> 16) | o1;
	write(1, &octet, 1);
	octet = ((mask2 << 16) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask2 << 24) >> 24) | o3;
	write(1, &octet, 1);
	return (3);
}

int ft_fourchar(unsigned int v, unsigned int mask3)
{
	unsigned char octet;
	unsigned char o4;
	unsigned char o3;
	unsigned char o2;
	unsigned char o1;

	o1 = ((v >> 18) << 29) >> 29;
	o2 = ((v >> 12) << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o4 = (v << 26) >> 26;
	octet = (mask3 >> 24) | o1;
	write(1, &octet, 1);
	octet = ((mask3 << 8) >> 24) | o2;
	write(1, &octet, 1);
	octet = ((mask3 << 16) >> 24) | o3;
	write(1, &octet, 1);
	octet = ((mask3 << 24) >> 24) | o4;
	write(1, &octet, 1);
	return (4);
}

void ft_putuchar(int nb, unsigned int octet)
{
	unsigned int mask1;
	unsigned int mask2;
	unsigned int mask3;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	nb == 1 ? ft_onechar(octet) : 0;
	nb == 2 ? ft_twochar(octet, mask1) : 0;
	nb == 3 ? ft_threechar(octet, mask2) : 0;
	nb == 4 ? ft_fourchar(octet, mask3) : 0;
}
