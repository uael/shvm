/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op/pipe.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/op.h"

int	shvm_oppipeb(t_op *op, t_ctx *ctx, char *ln)
{
	ft_memcpy(ctx->io, STD_FILENOS, 3 * sizeof(int));
	if (pipe(ctx->fds) < 0)
		exit(1);
	ctx->io[STDOUT_FILENO] = ctx->fds[1];
	return (shvm_opeval(++op, ctx, ln));
}

int	shvm_oppipei(t_op *op, t_ctx *ctx, char *ln)
{
	if (ctx->io[STDIN_FILENO] != STDIN_FILENO)
		close(ctx->io[STDIN_FILENO]);
	if (ctx->io[STDOUT_FILENO] != STDOUT_FILENO)
		close(ctx->io[STDOUT_FILENO]);
	ctx->io[STDIN_FILENO] = ctx->fds[0];
	if (pipe(ctx->fds) < 0)
		exit(1);
	ctx->io[STDOUT_FILENO] = ctx->fds[1];
	return (shvm_opeval(++op, ctx, ln));
}

int	shvm_oppipee(t_op *op, t_ctx *ctx, char *ln)
{
	ctx->fds[0] = 0;
	ctx->fds[1] = 0;
	ctx->io[STDOUT_FILENO] = STDOUT_FILENO;
	return (shvm_opeval(++op, ctx, ln));
}
