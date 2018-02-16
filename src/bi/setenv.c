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
#include "shvm/env.h"

#define M_SYNER "Syntax error"
#define M_ENOID "not an identifier"
#define N_SETENV "setenv: "

static t_bool	isname(char *word)
{
	if (!ft_isalpha(*word) && *word != '_')
		return (0);
	++word;
	while (*word)
	{
		if (!ft_isalnum(*word) && *word != '_')
			return (0);
		++word;
	}
	return (1);
}

inline int		shvm_bisetenv(int ac, char **av, char **env)
{
	if (ac == 1)
		return (shvm_bienv(ac, av, env));
	(void)env;
	if (ac < 2 || ac > 3 || !av[1] ||
		ft_strchr(av[1], '=') ||
		(ac == 3 && ft_strchr(av[2], '=')))
		return (ft_retf(NOP, N_SETENV"%s\n", M_SYNER));
	if (!isname(av[1]))
		return (ft_retf(NOP, N_SETENV"%s: %s\n", av[1], M_ENOID));
	shvm_envset(av[1], ac == 3 ? av[2] : 0);
	return (YEP);
}
