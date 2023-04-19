/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:41:56 by arebelo           #+#    #+#             */
/*   Updated: 2023/04/19 15:21:52 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

/**
 * Returns the angle (given in degrees) in radians 
*/
float	deg_to_rad(int d)
{ 
	return d * M_PI/ 180.0;
}

float	angle_check(float ang)
{
	if (ang > 359)
		ang -= 360;
	else if (ang < 0)
		ang += 360;
	return (ang);
}