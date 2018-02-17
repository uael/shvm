/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/env.h"
#include "shvm/vm.h"

extern void		shvm_envctor(char *ev[])
{
	ssize_t	i;
	t_bool	hasp;

	i = -1;
	hasp = 0;
	if (ev)
		while (ev[++i])
		{
			*(char **)ft_vecpush(&g_shvm->env) = ft_strdup(ev[i]);
			if (ft_strbegw("PATH", ev[i]) && ev[i][4] == '=')
				hasp = 1;
		}
	if (!hasp)
		*(char **)ft_vecpush(&g_shvm->env) = ft_strdup(PATH_DFL);
	*(char **)ft_vecpush(&g_shvm->env) = NULL;
	--g_shvm->env.len;
}

extern char		*shvm_envget(char const *var);
extern void		shvm_envset(char const *var, char const *val);
extern t_bool	shvm_envunset(char const *var);
extern void		shvm_envdump(int fd);
