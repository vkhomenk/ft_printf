/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prinft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhomenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 20:56:55 by vkhomenk          #+#    #+#             */
/*   Updated: 2019/02/20 21:44:05 by vkhomenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int     g_fd = 1;

void print_bytes(void *ptr, int size) 
{
    unsigned char   *p = ptr;
    int             j;
    while (--size >= 0) {
        j = 8;
        while (--j >= 0)
            printf("%d", p[size] / ft_power(2, j) % 2);
        printf(" ");
    }
    printf("\n");
}

size_t read_data(const char *fmt)
{
    int     i;

    i = 0;
    while (fmt[i])
    /*i = -1;
    while (fmt[++i] != ' ')
        write(g_fd, fmt + i, 1);*/
    return (i);
}

int		ft_printf(const char *restrict format, ...)
{
    va_list args;
    int     output_len;


    va_start(args, format);
/*
    int d = -255;
    print_bytes(&d, 4);
    unsigned long long ll = (unsigned long long)d;
    printf("d = %d\nll = %llu\n", d, ll);
    print_bytes(&ll, 8);
    printf("%ld\n", ft_nbrlen(ll));
*/
    output_len = 0;
    while (*format)
    {
        if (*format == '%')
        {
            //write(g_fd, format, 1);
            format += read_data(format + 1);
            //olen += print_data();
        }
        else
            output_len += write(g_fd, format, 1);
        format++;
    } 
    va_end(args);
    printf("output_len = %d\n", output_len);
    char *s = malloc(2147483645);
    size_t i = 0;
    while (i < 2147483645)
        s[i++] = 'a';
    s[i] = 0;
    printf("printf res = %d", printf("%s\n", s));
	return (1);
}

/*
 * на початку обов'язково ва_старт, вкінці обов'язково ва_енд
 *
*/
