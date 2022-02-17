/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:41:34 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/17 17:31:09 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_receive(int sig)
{
	static int	push;
	static int	bin;
	static int	idx;

	if (idx == 0)
	{
		bin = 128;
		push = 0;
	}
	if (sig == SIGUSR2)
		push += bin;
	idx += 1;
	bin /= 2;
	if (idx == 8)
	{
		ft_putchar(push);
		push = 0;
		bin = 128;
		idx = 0;
	}
}

int	main(int ac, char *av[])
{
	ft_putstr("pid : ");
	ft_putnbr(getpid());
	ft_putstr("\nReady to receive messages\n");
	signal(SIGUSR1, ft_receive);
	signal(SIGUSR2, ft_receive);
	while (1)
		pause();
	return (0);
}
