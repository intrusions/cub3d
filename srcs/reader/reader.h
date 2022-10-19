/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 00:09:56 by pducos            #+#    #+#             */
/*   Updated: 2022/10/05 03:21:29 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READER_H
# define READER_H

# include <stdbool.h>
# include <sys/types.h>
# include <stdint.h>
# include <stddef.h>

# define R_ERROR	-1
# define BUFF_SIZE  64

typedef struct s_reader
{
	int		fd;
	size_t	cap;
	size_t	checked;
	struct	s_save {
		uint8_t	*buf;
		size_t	size;
	}	save;
}	t_reader;

ssize_t		reader(uint8_t **buf, t_reader *r, char *sep);
t_reader	*reader_init(const char *file);
void		reader_destroy(t_reader *reader);
//
bool		r_alloc(uint8_t **ptr, size_t size);
bool		r_realloc(uint8_t **buf, size_t *cap, size_t len, size_t new_cap);
void		*r_memcpy(uint8_t *dst, const uint8_t *src, size_t n);

#endif
