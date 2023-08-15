/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_soln.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjegades <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:03:10 by tjegades          #+#    #+#             */
/*   Updated: 2023/08/15 16:03:10 by tjegades         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_soln(t_sol sol, t_data data)
{
	print_map(data);
	printf("\nsize=%d x=%d y=%d", sol.size, sol.x, sol.y);
}