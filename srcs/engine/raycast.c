/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pducos <pducos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:20:54 by pducos            #+#    #+#             */
/*   Updated: 2022/10/19 11:35:52 by pducos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define HORIZONTAL       0
#define VERTICAL         1
#define FOV        1.15192	

inline static void	drawline(int *data, size_t line_size, size_t len, int c)
{
	int	*ptr;

	ptr = data;
	while (len--)
	{
		*ptr = c;
		ptr += line_size;
	}
}

void	raycast(t_self *self)
{
	t_ray	r;
	int		side;
	float	line_len;
	float	current_angle;
	int		i;
	
	// current_angle c'est l'angle du joueur, nous on va envoyer des rayons
	// depuis (angle du joueur - FOV / 2), jusqu'a (angle du joueur + FOV / 2)
	// comme ca le rayon du joueur (la ou il regarde) est au millieu de l'ecran
	// et le champ de vision complet est egal a FOV
	current_angle = self->mlx.display.player.a - (FOV / 2);
	// la position initiale de chaque rayon c'est la position du joueur
	r.pos.x       = self->mlx.display.player.x;
	r.pos.y       = self->mlx.display.player.y;

	i = 0;
	while (i < RENDER_X)
	{
		// on va ajouter (FOV / largeur de l'ecran) a l'angle pour chaques rayons,
		// pour qu'il ajoute a l'angle de chaque rayons l'equivalent 1 pixel 
		current_angle += FOV / RENDER_X;
		// pour calculer une direction a partir d'un angle on utilise sinus/cosinus
		// on verra plus en detail ensemble mais en gros ca veut dire que pour avancer de 1 case
		// dans la direction x ou y, on doit ajouter cos(angle) a x ou sin(angle) a y
		r.dir.x        = cos(current_angle);
		r.dir.y        = sin(current_angle);
		// le delta j'ai pas tout a fait capte encore mdr
		r.delta.x      = sqrt(1 + (r.dir.y * r.dir.y) / (r.dir.x * r.dir.x));
		r.delta.y      = sqrt(1 + (r.dir.x * r.dir.x) / (r.dir.y * r.dir.y));
		// ici c'est la position du rayon dans la map (self->map.line)
		r.map.x        = (int)r.pos.x;
		r.map.y        = (int)r.pos.y;

		// si la direction de x est negative, on va avancer avec + -1 au lieu de + 1.
		// r.step c'est la taille d'un pas vers une direction
		// r.len c'est la taille du rayon pour l'instant, il y en a deux (x et y) car 
		// pour chaque rayon en vrai on en envoit 2, un qui cherche les murs de face et un 
		// qui cherche les murs perpendiculaires
		if (r.dir.x < 0) {
        	r.step.x = -1;
        	r.len.x = (r.pos.x - r.map.x) * r.delta.x;
      	} else {
       		r.step.x = 1;
        	r.len.x = (r.map.x + 1.0 - r.pos.x) * r.delta.x;
      	}
		// pareil pour direction de y
		if (r.dir.y < 0) {
        	r.step.y = -1;
        	r.len.y = (r.pos.y - r.map.y) * r.delta.y;
      	} else {
       		r.step.y = 1;
        	r.len.y = (r.map.y + 1.0 - r.pos.y) * r.delta.y;
      	}

		// tant que le rayon ne touche pas un mur, on avance le rayon
		while (self->map.line[r.map.y][r.map.x] != '1')
    	{
			// ici c'est pour detecter quelle face du mure on touche,
			// on verra plus en detail ensemble
        	if (r.len.x < r.len.y)
        	{
          		r.len.x += r.delta.x;
          		r.map.x += r.step.x;
          		side = HORIZONTAL;
			}
        	else
        	{
          		r.len.y += r.delta.y;
          		r.map.y += r.step.y;
          		side = VERTICAL;
			}
    	}

		// ici on check quelle face on a touche en dernier
		// et on calcule la taille de la ligne a afficher 
		if (side == HORIZONTAL)
			line_len = RENDER_Y / (r.len.x - r.delta.x);
		else
			line_len = RENDER_Y / (r.len.y - r.delta.y);		

		if (line_len > RENDER_Y)
			line_len = RENDER_Y;
		
		// ici on affiche la ligne au bon endroit
		drawline(
			self->mlx.display.screen.data + (RENDER_Y - (int)line_len) / 2 * RENDER_X + i,
			RENDER_X,
			line_len,
			side == HORIZONTAL ? 0x708090 : 0x536872);
		i++;
	}
}
















