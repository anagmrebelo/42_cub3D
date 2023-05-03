/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:41:56 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/28 15:58:34 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Returns the angle (given in degrees) in radians 
*/
float	deg_to_rad(float d)
{
	return (d * M_PI / 180.0);
}

/**
 * Corrects angle to always be between 0 and 359 (inclusive)
*/
float	angle_check(float ang)
{
	if (ang > 359)
		ang -= 360;
	else if (ang < 0)
		ang += 360;
	return (ang);
}

/**
 * Returns absolute value of int
*/
int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (n * (-1));
}

/**
 * Returns absolute value of float
*/
float	ft_abs_float(float n)
{
	if (n > 0)
		return (n);
	else
		return (n * (-1));
}
