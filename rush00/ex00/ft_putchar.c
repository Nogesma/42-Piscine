/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*  ft_putchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*  By: mbelarbi <mbelarbi@student.42lausanne.ch>   +#+  +:+       +#+        */
/*      msegrans <msegrans@student.42lausanne.ch> +#+#+#+#+#+   +#+           */
/*      vroch    <vroch@student.42lausanne.ch>         #+#    #+#             */
/*  Created: 2021/08/07 14:34:55                      ###   ########.fr       */
/*  Updated: 2021/08/07 14:34:58                                              */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
