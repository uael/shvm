/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op/cclr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/op.h"

int	shvm_opinit(t_op *op, t_ctx *ctx, char *ln)
{
	shvm_ctxreset(ctx, (t_bool)(op->flags & OPF_FULL));
	if (!(op->flags & OPF_FULL))
	{
		if (ctx->io[STDIN_FILENO] != STDIN_FILENO)
			close(ctx->io[STDIN_FILENO]);
		if (ctx->io[STDOUT_FILENO] != STDOUT_FILENO)
			close(ctx->io[STDOUT_FILENO]);
		ctx->io[STDIN_FILENO] = ctx->fds[0];
	}
	return (shvm_opeval(++op, ctx, ln));
}
