/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/signal.h>
#include <signal.h>

#include "shvm/vm.h"
#include "shvm/scope.h"
#include "shvm/bi.h"
#include "shvm/env.h"

static t_shvm	g_shvm_stack;

void			shvm_ctor(int fd, int ac, char *av[], char *ev[])
{
	pid_t pid;

	g_shvm = &g_shvm_stack;
	ft_bzero(g_shvm, sizeof(t_shvm));
	ft_vecctor(&g_shvm->env, sizeof(char *));
	ft_mapctor(&g_shvm->builtins, g_strhash, sizeof(char *), sizeof(t_bi *));
	ft_mapctor(&g_shvm->binaries, g_strhash, sizeof(char *), sizeof(char *));
	ft_mapctor(&g_shvm->locals, g_strhash, sizeof(char *), sizeof(char *));
	ft_mapctor(&g_shvm->aliases, g_strhash, sizeof(char *), sizeof(char *));
	tcgetattr(fd, &g_shvm->tcmode);
	pid = getpgrp();
	while (tcgetpgrp(fd) != pid)
		kill(-pid, SIGTTIN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCHLD, SIG_DFL);
	shvm_scopector(g_shvm->scope + g_shvm->sc, fd, ac, av);
	shvm_envctor(ev);
}

void			shvm_dtor(void)
{
	while (g_shvm->bc)
		shvm_jobkill(shvm_jobget(--g_shvm->bc));
	ft_vecdtor(&g_shvm->env, (t_dtor)ft_pfree);
	ft_mapdtor(&g_shvm->builtins, (t_dtor)ft_pfree, NULL);
	ft_mapdtor(&g_shvm->binaries, (t_dtor)ft_pfree, (t_dtor)ft_pfree);
	ft_mapdtor(&g_shvm->locals, (t_dtor)ft_pfree, (t_dtor)ft_pfree);
	ft_mapdtor(&g_shvm->aliases, (t_dtor)ft_pfree, (t_dtor)ft_pfree);
}

void			shvm_reset(void)
{
	if (g_shvm->oc)
	{
		ft_bzero(g_shvm->op, g_shvm->oc * sizeof(t_op));
		g_shvm->oc = 0;
	}
}

int				shvm_eval(char *line)
{
	int		st;
	t_ctx	ctx;

	shvm_ctxctor(&ctx);
	g_shvm->ctx = &ctx;
	st = shvm_opeval(g_shvm->op, &ctx, line);
	shvm_ctxdtor(&ctx);
	return (st);
}
