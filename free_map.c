/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrubio-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 15:16:41 by jrubio-m          #+#    #+#             */
/*   Updated: 2024/06/01 15:16:44 by jrubio-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int f)
{
	size_t	l;

	l = 0;
	if (f == 1)
	{
		while (map[l])
		{
			free(map[l]);
			l++;
		}
	}
	free(map);
}
