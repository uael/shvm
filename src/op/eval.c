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
	[OP_INIT] = "OP_INIT",
	[OP_BINA] = "OP_BINA",
	[OP_FORK] = "OP_FORK",
	[OP_WORD] = "OP_WORD",
	[OP_EXEC] = "OP_EXEC",
	[OP_WAIT] = "OP_WAIT",
	[OP_COMP] = "OP_COMP",
	[OP_GOTO] = "OP_GOTO",
	[OP_TERM] = "OP_TERM"
};
#endif
static t_opc	*g_opc[] = {
	[OP_INIT] = shvm_opinit,
	[OP_BINA] = shvm_opbina,
	[OP_FORK] = shvm_opfork,
	[OP_WORD] = shvm_opword,
	[OP_EXEC] = shvm_opexec,
	[OP_WAIT] = shvm_opwait,
	[OP_COMP] = shvm_opcomp,
	[OP_GOTO] = shvm_opgoto,
	[OP_TERM] = shvm_opterm
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
