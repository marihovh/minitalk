/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:01:20 by marihovh          #+#    #+#             */
/*   Updated: 2023/06/01 06:19:17 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	send_str(char *str, int pid)
{
	int		sf;
	int		i;

	i = -1;
	while (str[++i])
	{
		sf = 8;
		while (sf--)
		{
			if ((str[i] >> sf) & 1)
			{
				if (kill(pid, SIGUSR1) == -1 && ft_printf("Wrong procces ID\n"))
					exit (1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1 && ft_printf("Wrong procces ID\n"))
					exit (1);
			}
			usleep(100);
		}
	}
}

int	main(int args, char *argv[])
{
	int	pid;
	int	i;

	i = 1;
	if (args == 3)
	{
		pid = ft_atoi(argv[1]);
		send_str(argv[2], pid);
		ft_printf("Message was received correctly\n");
	}
	else
		ft_printf("Wrong count of arguments\n");
	return (0);
}
