/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:41:34 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/17 21:04:21 by anajmi           ###   ########.fr       */
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
	usleep(100);
}

static void	quit(int i)
{
	if (i == 1)
		ft_putstr("Incorrect type of pid must be integer\n");
	else if (i == 2)
		ft_putstr("Incorrect Arguments ./EXE [INT:pid] [STR:message]\n");
	exit(0);
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
				quit(1);
		}
		pid = ft_atoi(av[1]);
		i = -1;
		while (av[2][++i])
			ft_send(pid, av[2][i]);
		ft_send(pid, av[2][i]);
		ft_send(pid, '\n');
	}
	else
		quit(2);
	return (0);
}
