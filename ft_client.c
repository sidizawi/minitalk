/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:29:25 by szawi             #+#    #+#             */
/*   Updated: 2021/11/07 23:29:25 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	ft_send(const char *str, int pid)
{
	int		j;

	while(*str)
	{
		j = 7;
		while (j >= 0)
		{
			if (*str & 1 << j--)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(MAX_SLEEP);
		}
		str++;
	}
	j = 0;
	while (j++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(MAX_SLEEP);
	}
}

int			main(int ac, char *av[])
{
	int	pid;

	pid = ft_atoi(av[1]);
	if (ac != 3)
		ft_exit("Arguments Error\n");
	ft_send(av[2], pid);
	return (0);
}
