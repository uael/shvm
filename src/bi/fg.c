/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ush/env.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/bi.h"
#include "shvm/vm.h"

#define FG "fg: "

static void	fg(uint8_t idx)
{
	t_job	*job;

	if (!shvm_jobrem(idx, job = alloca(sizeof(t_job))))
		return ;
	if (shvm_jobstopped(job))
		shvm_jobcont(job, 1);
	else
	{
		//TODO
	}
}

inline int	shvm_bifg(int ac, char **av, char **env)
{
	ssize_t	i;

	(void)env;
	if (!g_shvm->bc)
		return (ft_retf(EXIT_FAILURE, FG"no current job\n"));
	if (ac != 1)
		while (*++av)
		{
			i = ft_atoi(*av);
			if (ft_strlen(*av) != ft_intlen(i, 10) || (size_t)i >= g_shvm->bc)
				ft_putf(STDERR_FILENO, FG"%s: job not found\n", *av);
			else
				fg((uint8_t)i);
		}
	else
		fg((uint8_t)(g_shvm->bc - 1));
	return (EXIT_SUCCESS);
}
