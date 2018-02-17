/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/scope.h"

void	shvm_scopector(t_scope *scope, int fd, int ac, char *av[])
{
	scope->ac = ac;
	scope->av = av;
	scope->pid = getpid();
	scope->tty = (t_bool)isatty(fd);
	scope->status = 0;
	setpgid(scope->pid, scope->pid);
	tcsetpgrp(fd, scope->pid);
}
