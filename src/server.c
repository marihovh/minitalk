/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marihovh <marihovh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 20:01:42 by marihovh          #+#    #+#             */
/*   Updated: 2023/06/01 06:19:55 by marihovh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	handle(int sig_int)
{
	static unsigned char	ch = 0;
	static int				sf = 0;

	++sf;
	ch = ch << 1;
	if (sig_int == SIGUSR1)
		ch = ch | 1;
	if (sf == 8)
	{
		ft_printf("%c", ch);
		sf = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle;
	ft_printf("%i\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
