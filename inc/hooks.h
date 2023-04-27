/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:52:10 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/27 17:13:59 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

void	key_hook(t_master *master);
int		key_down(int keycode, t_master *master);
int		key_up(int keycode, t_master *master);
int		red_cross(t_master *master);

#endif
