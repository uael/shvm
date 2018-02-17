/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/op.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_OP_H
# define SHVM_OP_H

# include "ctx.h"

# define OPF_FULL (1 << 1)
# define OPF_PIPE (1 << 2)
# define OPF_LOCK (1 << 3)

enum e_opcode
{
	OP_CLR,
	OP_BIN,
	OP_FORK,
	OP_WORD,
	OP_EXEC,
	OP_WAIT,
	OP_COMP,
	OP_GOTO,
	OP_TERM
};

typedef struct	s_op
{
	uint8_t		kind;
	uint8_t		flags;
	uint16_t	pos;
	uint16_t	len;
	uint16_t	jump;
}				t_op;

typedef int		(t_opc)(t_op *op, t_ctx *ctx, char *ln);

extern t_op		*shvm_oppush(uint16_t *it);
extern t_op		*shvm_opput(uint16_t it);
extern t_op		*shvm_opat(uint16_t it);

extern int		shvm_opeval(t_op *op, t_ctx *ctx, char *ln);


#endif
