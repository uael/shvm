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

# define OP_LOCK (1 << 1)
# define OP_FJMP (1 << 2)
# define OP_INIT (1 << 3)
# define OP_BACK (1 << 4)

enum e_opcode
{
	OP_BIN = 0,
	OP_WORD,
	OP_JUMP,
	OP_TERM,
	OP_WAIT,
	OP_PIPEB,
	OP_PIPEI,
	OP_PIPEE,
	OP_FORK,
	OP_CCLR,
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
extern int		shvm_opcclr(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_opbin(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_opword(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_opjump(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_opterm(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_opwait(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_oppipeb(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_oppipei(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_oppipee(t_op *op, t_ctx *ctx, char *ln);
extern int		shvm_opfork(t_op *op, t_ctx *ctx, char *ln);

#endif
