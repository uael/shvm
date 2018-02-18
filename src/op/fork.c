/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op/fork.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/op.h"

int	shvm_opfork(t_op *op, t_ctx *ctx, char *ln)
{
	t_bool ch;

	ch = 0;
	if ((op->flags & OPF_PIPE))
	{
		ch = 1;
		if (pipe(ctx->fds) < 0)
			exit(1);
		ctx->io[STDOUT_FILENO] = ctx->fds[1];
	}
	else
	{
		ctx->fds[0] = 0;
		ctx->fds[1] = 0;
		ctx->io[STDOUT_FILENO] = STDOUT_FILENO;
	}
	if (!ctx->bi)
		ch = 1;

	return (shvm_opeval(++op, ctx, ln));
}
