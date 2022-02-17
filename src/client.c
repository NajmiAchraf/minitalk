/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:41:34 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/17 17:25:01 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send(int pid, char c)
{
	int	bit;

	bit = 8;
	while (--bit >= 0)
	{
		if (c & (1 << bit))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		i = -1;
		while (av[1][++i])
		{
			if (!('0' <= av[1][i] && av[1][i] <= '9'))
			{
				ft_putstr("Incorrect type of pid must be integer\n");
				exit(0);
			}
		}
		pid = ft_atoi(av[1]);
		i = -1;
		while (av[2][++i])
			ft_send(pid, av[2][i]);
		ft_send(pid, av[2][i]);
		ft_send(pid, '\n');
	}
	else
		ft_putstr("Incorrect Arguments ./EXE [INT:pid] [STR:message]\n");
	return (0);
}
