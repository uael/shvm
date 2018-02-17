/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op/bin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/bi.h"
#include "shvm/op.h"
#include "shvm/vm.h"
#include "shvm/word.h"
#include "shvm/exe.h"

static int	binnotfound(int ac, char **av, char **ev)
{
	(void)ac;
	(void)av;
	(void)ev;
	if (g_shvm->ctx->scope->status == PROC_ISDIR)
		ft_putf(2, "%s: Is a directory\n", g_shvm->ctx->bin);
	else
		ft_putf(2, g_shvm->ctx->scope->status == PROC_NOTFOUND &&
			!ft_strchr(g_shvm->ctx->bin, '/') ?
			"%s: Command not found\n" : "%s: %e\n", g_shvm->ctx->bin, errno);
	return (g_shvm->ctx->scope->status);
}

static int	binfail(t_op *op, t_ctx *ctx, char *ln, int st)
{
	while (ctx->ac)
		ft_pfree((void **)ctx->av + --ctx->ac);
	ctx->scope->status = st;
	return (shvm_opeval(g_shvm->op + op->jump, ctx, ln));
}

static int 	binpredef(t_op *op, t_ctx *ctx, char *ln)
{
	uint32_t	it;
	int			st;
	char		buf[PATH_MAX + 1];

	if (!ft_strcmp(*ctx->av, "true"))
		return (binfail(op, ctx, ln, 0));
	if (!ft_strcmp(*ctx->av, "fals"))
		return (binfail(op, ctx, ln, 1));
	if (ft_mapget(&g_shvm->builtins, *ctx->av, &it))
		ctx->bi = ((t_bi **)g_shvm->builtins.vals)[it];
	else if ((st = shvm_exelookup(g_shvm->env.buf, *ctx->av, "PATH", buf)))
	{
		ctx->bi = binnotfound;
		ctx->bin = *ctx->av;
		*ctx->av = NULL;
		return (binfail(op, ctx, ln, st));
	}
	else
		ctx->bin = ft_strdup(buf);
	return (shvm_opeval(++op, ctx, ln));
}

int			shvm_opbin(t_op *op, t_ctx *ctx, char *ln)
{
	while (!ctx->ac)
		if ((op->flags & OP_LOCK))
		{
			ctx->av[ctx->ac++] = ft_strndup(ln + op->pos, op->len);
			break ;
		}
		else
		{
			shvm_wordexp(&ctx->ac, ctx->av, ln + op->pos, op->len);
			if (!ctx->ac && (++op)->kind != OP_WORD)
				return (binfail(op, ctx, ln, 0));
		}
	return (binpredef(op, ctx, ln));
}
