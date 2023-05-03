/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arebelo <arebelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:52:10 by anarebelo         #+#    #+#             */
/*   Updated: 2023/04/27 17:38:18 by arebelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

// key_hooks.c
_Bool	allow_move(t_master *master, float x, float y);
void	key_hook(t_master *master);
int		key_down(int keycode, t_master *master);
int		key_up(int keycode, t_master *master);
int		red_cross(t_master *master);

// key_letters.c
void	move_front(t_master *master);
void	move_left(t_master *master);
void	move_back(t_master *master);
void	move_right(t_master *master);

// key_arrows.c
void	move_larrow(t_master *master);
void	move_rarrow(t_master *master);

#endif
