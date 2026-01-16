/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:35:20 by ajeloyan          #+#    #+#             */
/*   Updated: 2025/12/09 16:57:20 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_nbr(long int nb, int *count, int size_base, char *base)
{
	int	ret;

	if (nb < 0)
	{
		ft_print_char('-', count);
		nb = -nb;
	}
	if (nb >= size_base)
	{
		ret = ft_print_nbr(nb / size_base, count, size_base, base);
		if (ret == -1)
			return (-1);
		if (ft_print_char(base[nb % size_base], count) == -1)
			return (-1);
	}
	else
	{
		if (ft_print_char(base[nb], count) == -1)
			return (-1);
	}
	return (1);
}
