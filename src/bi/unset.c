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
#include "shvm/var.h"
#include "shvm/word.h"

static char const	*g_usage = "usage: unset [NAME ...]\n"
"\tThe unset builtin command is used to unset values and attributes\n"
"\tof shell variables.\n";

static int	unsetexhdl(int rcode, void *arg)
{
	if (!errno || errno == EBADF || errno == EIO)
		return (rcode);
	if (arg)
		ft_putf(STDERR_FILENO, "unset: %s: %e\n",
			arg, errno);
	else
		ft_putf(STDERR_FILENO, "unset: %e\n", errno);
	if (errno == ENOARG)
		ft_puts(STDERR_FILENO, g_usage);
	if (errno == ENOMEM)
		exit(EXIT_FAILURE);
	errno = 0;
	return (rcode);
}

inline int	shvm_biunset(int ac, char **av)
{
	ft_exbind(EXALL, ft_exhdl(unsetexhdl, NULL), NULL);
	if (ac == 1)
		return (ENO_THROW(EXIT_FAILURE, ENOARG));
	while (*++av)
	{
		ft_exbind(EXALL, ft_exhdl(unsetexhdl, *av), NULL);
		if (shvm_wordisvar(*av, ft_strlen(*av)) && !ft_strchr(*av, '=') &&
			shvm_varget(*av, NULL))
			shvm_varset(*av, NULL);
		else
			shvm_envunset(*av);
	}
	return (EXIT_SUCCESS);
}
