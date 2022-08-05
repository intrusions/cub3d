/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucheval <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 00:51:42 by jucheval          #+#    #+#             */
/*   Updated: 2022/08/05 05:26:55 by jucheval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// ========================================================================= //
//                                   Library                                 //
// ========================================================================= //

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// ========================================================================= //
//                                   Define                                  //
// ========================================================================= //

#define BUFFER_SIZE 1

// ========================================================================= //
//                                    Enum                                   //
// ========================================================================= //

typedef enum e_errors
{
	argc_errors,
}   t_e_errors;

// ========================================================================= //
//                                 Structure                                 //
// ========================================================================= //

typedef struct s_global_data
{
	char	**file;
}	t_global_data;

typedef struct s_parsing_errors
{
	int				map_name;
	int				incorrect_fd;
	t_global_data	*data;
}	t_parsing_errors;


// ========================================================================= //
//                                  Parsing                                  //
// ========================================================================= //

// Function to call of another secondary function about parsing
int		p_start_parsing(char *str, t_parsing_errors *errors);

// Function to check if the map are ended by a ".cub"
int		p_parse_name(char *str, t_parsing_errors *errors);

// Function to stock all data of the file in a char **
char    **p_get_file(char *file, t_parsing_errors *errors);

// Function to count how many line are in file
size_t	p_count_line_in_file(char *argv, t_parsing_errors *errors);

// ========================================================================= //
//                                   Game                                    //
// ========================================================================= //


// ========================================================================= //
//                                    Utils                                  //
// ========================================================================= //

// Function to print differents errors
void	u_print_errors(t_parsing_errors *errors);

// Get_next_line part
char	*ft_strjoin(char *s1, char *s2);
int		ft_have_newline(char *str);
size_t	ft_strlen(const char *s);
char	*ft_free(char *str);
char	*ft_get_line(char *stash);
char	*ft_get_stash(char *stash);
char	*get_next_line(int fd);

// Debug
void	print_file(char **file);


#endif