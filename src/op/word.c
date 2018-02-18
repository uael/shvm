/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op/word.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/op.h"
#include "shvm/word.h"

int	shvm_opword(t_op *op, t_ctx *ctx, char *ln)
{
	if ((op->flags & OPF_LOCK))
		ctx->av[ctx->ac++] = ft_strndup(ln + op->pos, op->len);
	else
		shvm_wordexp(&ctx->ac, ctx->av, ln + op->pos, op->len);
	return (shvm_opeval(++op, ctx, ln));
}
