/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op/eval.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/op.h"
#include "shvm/vm.h"

#ifndef NDEBUG
#include <stdio.h>
static char		*g_opn[] = {
	[OP_BIN] = "OP_BIN",
	[OP_WORD] = "OP_WORD",
	[OP_TERM] = "OP_TERM",
	[OP_JUMP] = "OP_JUMP",
	[OP_WAIT] = "OP_WAIT",
	[OP_PIPEB] = "OP_PIPEB",
	[OP_PIPEI] = "OP_PIPEI",
	[OP_PIPEE] = "OP_PIPEE",
	[OP_FORK] = "OP_FORK",
	[OP_CCLR] = "OP_CCLR",
};
#endif
static t_opc	*g_opc[] = {
	[OP_BIN] = shvm_opbin,
	[OP_WORD] = shvm_opword,
	[OP_TERM] = shvm_opterm,
	[OP_JUMP] = shvm_opjump,
	[OP_WAIT] = shvm_opwait,
	[OP_PIPEB] = shvm_oppipeb,
	[OP_PIPEI] = shvm_oppipei,
	[OP_PIPEE] = shvm_oppipee,
	[OP_FORK] = shvm_opfork,
	[OP_CCLR] = shvm_opcclr,
};

int				shvm_opeval(t_op *op, t_ctx *ctx, char *ln)
{
#ifndef NDEBUG
	dprintf(1, "%d -> [%zu]{%s, %d, %d, %d, %d} -> '%s'\n",
		g_shvm->scope[g_shvm->sc].status, op - g_shvm->op,
		g_opn[op->kind], op->flags, op->pos, op->len, op->jump,
		ft_strncpy(alloca(op->len + 1), ln + op->pos, op->len));
#endif
	return (g_opc[op->kind](op, ctx, ln));
}
