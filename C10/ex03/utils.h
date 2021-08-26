//
// Created by Mano Segransan on 8/19/21.
//

#ifndef UTILS_H
# define UTILS_H

typedef struct s_t_string
{
	  unsigned char	c[17];
	  unsigned char	d[17];
	  int			is_star;
}	t_string;

int		ft_chr_is_printable(unsigned char c);

void	ft_strncpy(unsigned char *dest, const unsigned char *src,
			unsigned int n);

void	ft_getnbr_hex(long nb, char *nbs, int size);

int		ft_strncmp(unsigned char *s1, unsigned char *s2, unsigned int n);

#endif //UTILS_H
