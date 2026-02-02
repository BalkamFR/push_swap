/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeloyan <ajeloyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:18:16 by ajeloyan          #+#    #+#             */
/*   Updated: 2025/12/03 16:18:13 by ajeloyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_print_char(char c, int *count);
int	ft_print_str(char *str, int *count);
int	ft_printf(const char *format, ...);
int	ft_check_format(const char **format, int *count, va_list *args);
int	ft_print_nbr(long int nb, int *count, int size_base, char *base);
int	ft_check_format(const char **format, int *count, va_list *args);
int	ft_pointer(int *count, va_list *args);

#endif
