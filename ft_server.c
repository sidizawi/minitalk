/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:03:53 by szawi             #+#    #+#             */
/*   Updated: 2021/11/07 01:03:53 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

static void	handle_sigusr(int sig)
{
	static int	res;
	static int	exp;

	if (!exp)
		exp = 128;
	if (sig == SIGUSR2)
		res += exp;
	exp /= 2;
	if (!exp)
	{
		if (res)
			write(1, &res, 1);
		else
			write(1, "\n\n", 2);
		res = 0;
	}
}

int	main(void)
{
	struct sigaction sa_usr;

	ft_print("pid = ", 1);
	ft_print_pid(getpid());
	ft_print("\n", 1);
	sa_usr.sa_handler = handle_sigusr;
	sa_usr.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa_usr, NULL);
	sigaction(SIGUSR2, &sa_usr, NULL);
	while(1)
		;
	return (0);
}
