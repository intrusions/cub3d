/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   report_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 20:52:55 by pducos            #+#    #+#             */
/*   Updated: 2022/10/05 02:39:04 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

static size_t	write_all(int fd, const void *buf, size_t s)
{
	ssize_t	c;
	size_t	ret;

	ret = 0;
	while (s)
	{
		c = write(fd, buf + ret, s);
		if (c == -1)
			break ;
		ret += c;
		s -= c;
	}
	return (ret);
}

static size_t	str_fd(const char *s, int fd)
{
	char	*tmp;

	if (s)
	{
		tmp = (char *)s;
		while (*tmp)
			tmp++;
		return (write_all(fd, s, tmp - s));
	}
	return (write_all(fd, "(null)", 6));
}

static size_t	int_fd(int64_t c, int fd)
{
	int8_t	nbr[20];
	int64_t	n;
	int		i;

	n = c;
	if (n)
	{
		if (n < 0)
			n *= -1;
		i = 20;
		while (n)
		{
			nbr[--i] = (n % 10) | 0x30;
			n /= 10;
		}
		if (c < 0)
			nbr[--i] = '-';
		return (write_all(fd, &nbr[i], 20 - i));
	}
	return (write_all(fd, "0", 1));
}

static ssize_t	print_field(int fd, va_list *ap, const char *s)
{
	if (*s == 's')
		return (str_fd(va_arg(*ap, char *), fd));
	if (*s == 'd')
		return (int_fd(va_arg(*ap, int64_t), fd));
	if (*s == 'e')
		return (str_fd(strerror(errno), fd));
	return (-1);
}

void	report_error(const char *s, ...)
{
	va_list	ap;
	char	*p;

	va_start(ap, s);
	while (*s)
	{
		p = (char *)s;
		while (*p && *p != '%')
			p++;
		if (s != p)
		{
			write_all(STDERR_FILENO, s, p - s);
			s = p;
		}
		if (*s && print_field(STDERR_FILENO, &ap, ++s) != -1)
			s++;
		else
			break ;
	}
	va_end(ap);
}
