/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:56:55 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/16 07:07:28 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_printf(const char *restrict fmt/* format*/, ...)
{
    va_list args;
    va_start(args, fmt);

    while (*fmt != '\0') {
        if (*fmt == 'd') {
            int i = va_arg(args, int);
            printf("%2$d %1$d %2$d %4$s\n", i, i/2, "qwe", "asd");
        } else if (*fmt == 'c') {
            // A 'char' variable will be promoted to 'int'
            // A character literal in C is already 'int' by itself
            int c = va_arg(args, int);
            printf("%c\n", c);
        } else if (*fmt == 'f') {
            double d = va_arg(args, double);
            printf("%8.2f\n", d);
            printf("%.20a\n", d);
			printf("%.20E\n", d);
			printf("%.10g\n", d);
        }
		else if (*fmt == 's')
		{
			int	w = va_arg(args, int);
			char *str = va_arg(args, char*);
			printf("%-*s\n", w, str);
		}
        ++fmt;
    } 
    va_end(args);
	return (1);
}

/*
 * на початку обов'язково ва_старт, вкінці обов'язково ва_енд
 *
*/
