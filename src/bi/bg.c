/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi/bg.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/bi.h"
#include "shvm/vm.h"

inline int	shvm_bibg(int ac, char **av, char **env)
{
	ssize_t	i;
	t_job	*job;

	(void)env;
	if (!(i = g_shvm->bc))
		return (ft_retf(EXIT_FAILURE, "bg: no current job\n"));
	if (ac != 1)
	{
		while (*++av)
			if (ft_strlen(*av) != ft_intlen(i = ft_atoi(*av), 10) ||
				!(job = shvm_jobget((uint8_t)i)) || shvm_jobstopped(job))
				ft_putf(STDERR_FILENO, "bg: %s: job not found\n", *av);
			else
				shvm_jobcont(shvm_jobget((uint8_t)i), 0);
		return (EXIT_SUCCESS);
	}
	else
		while (--i >= 0)
			if (shvm_jobstopped(job = shvm_jobget((uint8_t)i)))
			{
				shvm_jobcont(job, 0);
				return (EXIT_SUCCESS);
			}
	return (ft_retf(EXIT_FAILURE, "bg: bg current job\n"));
}
