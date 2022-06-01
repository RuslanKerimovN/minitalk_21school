/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 11:42:14 by botilia           #+#    #+#             */
/*   Updated: 2021/12/29 11:28:53 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		j = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		k *= 10;
		k += ((int)str[i] - '0');
		i++;
	}
	if (j == 1)
		return (-k);
	else
		return (k);
}

void	handler(int signal, siginfo_t *siginfo, void *none)
{
	(void)none;
	(void)siginfo;
	(void)signal;
}

void	give_bit(int pid, int bit)
{
	int	counter;

	counter = 0;
	while (counter <= 7)
	{
		if ((bit >> counter) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		counter++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	cl;
	int					pid;
	int					i;

	if (argc != 3)
	{
		write(1, "Error of arfuments\n", 19);
		return (0);
	}
	i = 0;
	cl.sa_flags = SA_SIGINFO;
	cl.sa_sigaction = handler;
	sigaction(SIGUSR1, &cl, 0);
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
		give_bit(pid, argv[2][i++]);
	give_bit(pid, '\0');
	write (1, "Mission complite\n", 17);
	return (0);
}
