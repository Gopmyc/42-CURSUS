/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghoyaux <ghoyaux@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 07:07:43 by ghoyaux           #+#    #+#             */
/*   Updated: 2025/01/06 08:15:02 by ghoyaux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int	ft_key_press(int keycode, void *params)
{
	t_fdf	*env;

	env = (t_fdf *)params;
	if (keycode == ESCAPE)
		ft_close_win(env);
	ft_draw(env->map, env);
	return (0);
}
