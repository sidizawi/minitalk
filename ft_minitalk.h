/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szawi <szawi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 01:07:44 by szawi             #+#    #+#             */
/*   Updated: 2021/11/07 01:07:44 by szawi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
void	ft_print(const char *str, int fd);
void	ft_print_pid(int pid);
void	ft_exit(char *str);
int		ft_atoi(const char *str);

# define MAX_SLEEP 85

#endif
