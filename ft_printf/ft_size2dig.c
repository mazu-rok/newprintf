
#include "ft_printf.h"

int ft_size(t_key *key, int p, int w)
{
	int size;

	size = (p > 0 ? p : 0) + key->lenr + (w > 0 ? w : 0);
	size += key->flag->hash && ft_searcINline("oO", key->sym) ? 1 : 0;
	size += key->flag->hash && ft_searcINline("xX", key->sym) ? 2 : 0;
	size += key->sym == 'p' ? 2 : 0;
	size += key->flag->space;
	size -= (key->res[0] == '0' && !key->precision);
	return (size);

}

int ft_width(t_key *key, int p)
{
	int w;

	w = key->width - (p > 0 ? p : 0) - (key->res[0] == '0' && \
		!key->precision ? 0 : key->lenr);
	w -= key->flag->hash && ft_searcINline("oO", key->sym) ? 1 : 0;
	w -= key->flag->hash && ft_searcINline("xX", key->sym) ? 2 : 0;
	w -= key->sym == 'p' ? 2 : 0;
	w -= key->flag->space;
	return (w);
}

int ft_precision(t_key *key)
{
	int p;

	p = key->precision - key->lenr + (key->res[0] == '-');
	p -= key->flag->hash && (key->sym == 'o' || key->sym == 'O') ? 1 : 0;
	return (p);
}
