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

#ifndef NDEBUG
static char	*opn[] = {
	[OP_EXEC] = "OP_EXEC",
	[OP_WORD] = "OP_WORD",
	[OP_TERM] = "OP_TERM",
	[OP_JUMP] = "OP_JUMP",
	[OP_WAIT] = "OP_WAIT",
	[OP_PIPE] = "OP_PIPE",
	[OP_FORK] = "OP_FORK",
};
#endif

int			shvm_opeval(t_op *op, char *ln)
{
	static t_opc	*opc[] = {
		[OP_EXEC] = shvm_opexec,
		[OP_WORD] = shvm_opword,
		[OP_TERM] = shvm_opterm,
		[OP_JUMP] = shvm_opjump,
		[OP_WAIT] = shvm_opwait,
		[OP_PIPE] = shvm_oppipe,
		[OP_FORK] = shvm_opfork,
	};
}
