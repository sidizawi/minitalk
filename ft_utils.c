/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 23:26:35 by szawi             #+#    #+#             */
/*   Updated: 2021/11/07 23:26:35 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while(str && *str++)
		len++;
	return (len);
}

void	ft_print(const char *str, int fd)
{
	if (str && fd > -1)
		write(fd, str, ft_strlen(str));
}

void	ft_print_pid(int pid)
{
	char	temp;

	if (pid < 10)
	{
		temp = pid + '0';
		write(1, &temp, 1);
	}
	else
	{
		ft_print_pid(pid/10);
		temp = pid % 10 + '0';
		write(1, &temp, 1);
	}
}

void	ft_exit(char *str)
{
	ft_print(str, 2);
	exit(1);
}

int		ft_atoi(const char *str)
{
	int	res;

	res = 0;
	if (str && ft_strlen(str) <= 10)
	{
		while (*str && *str >= '0' && *str <= '9')
			res = res * 10 + *str++ - '0';
		if (*str)
			ft_exit("Wrong Pid\n");
	}
	else
		ft_exit("Wrong Pid\n");
	return (res);
}
