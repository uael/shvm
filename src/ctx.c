/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/ctx.h"
#include "shvm/vm.h"

void	shvm_ctxctor(t_ctx *ctx)
{
	ft_bzero(ctx, sizeof(t_ctx));
	ft_memcpy(ctx->io, STD_FILENOS, 3 * sizeof(int));
	ft_vecctor(&ctx->env, sizeof(char *));
	ft_mapctor(&ctx->locals, g_strhash, sizeof(char *), sizeof(char *));
	ctx->scope = g_shvm->scope + g_shvm->sc;
}

void	shvm_ctxdtor(t_ctx *ctx)
{
	while (ctx->ac)
		ft_pfree((void **)ctx->av + --ctx->ac);
	ft_vecdtor(&ctx->env, (t_dtor)ft_pfree);
	ft_mapdtor(&ctx->locals, (t_dtor)ft_pfree, (t_dtor)ft_pfree);
	ft_pfree((void **)ctx->bin);
}

void	shvm_ctxreset(t_ctx *ctx)
{
	while (ctx->ac)
		ft_pfree((void **)ctx->av + --ctx->ac);
	ft_vecclr(&ctx->env, (t_dtor)ft_pfree);
	ft_mapclr(&ctx->locals, (t_dtor)ft_pfree, (t_dtor)ft_pfree);
	ft_memcpy(ctx->io, STD_FILENOS, 3 * sizeof(int));
	ft_bzero(ctx->fds, 2 * sizeof(int));
	ft_pfree((void **)ctx->bin);
	ctx->scope = g_shvm->scope + g_shvm->sc;
	ctx->bi = NULL;
	ctx->job = NULL;
}
