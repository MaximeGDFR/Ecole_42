/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:11:58 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/12/02 22:14:47 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	handle_error(char *msg_err, int syst_funct)
{
	if (!syst_funct)
		write (2, msg_err, ft_strlen(msg_err));
	else
		write (1, msg_err, ft_strlen(msg_err));
	exit(-1);
}
