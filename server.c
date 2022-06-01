/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:42:30 by botilia           #+#    #+#             */
/*   Updated: 2021/12/29 11:29:05 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	i;

	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + 48);
}

void	ft_take_bit(int signal, siginfo_t *siginfo, void *none)
{
	static unsigned char	sym = 0;
	static int				i = 0;

	(void)none;
	if (signal == SIGUSR1)
		sym |= (1 << i);
	i++;
	if (i == 8)
	{
		if (sym != 0)
			ft_putchar(sym);
		else
			write (1, "\n", 1);
		i = 0;
		sym = 0;
		kill(siginfo->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	se;

	se.sa_flags = SA_SIGINFO;
	se.sa_sigaction = ft_take_bit;
	sigaction(SIGUSR1, &se, NULL);
	sigaction(SIGUSR2, &se, NULL);
	write (1, "Server PID is ", 14);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
