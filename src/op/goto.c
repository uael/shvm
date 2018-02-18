/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op/jump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/op.h"
#include "shvm/vm.h"

int	shvm_opgoto(t_op *op, t_ctx *ctx, char *ln)
{
	return (shvm_opeval(g_shvm->op + op->jump, ctx, ln));
}
