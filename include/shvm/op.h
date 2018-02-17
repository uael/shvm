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

# include <libft.h>

enum e_opcode
{
	OP_EXEC = 0,
	OP_WORD,
	OP_JUMP,
	OP_TERM,
	OP_WAIT,
	OP_PIPE,
	OP_FORK,
};

typedef struct	s_op
{
	uint8_t		kind;
	uint8_t		flags;
	uint16_t	pos;
	uint16_t	len;
	uint16_t	jump;
}				t_op;

typedef int		(t_opc)( t_op *op, char *ln);

extern t_op		*shvm_oppush(uint16_t *it);
extern t_op		*shvm_opat(uint16_t it);

extern int		shvm_opeval(t_op *op, char *ln);
extern int		shvm_opexec(t_op *op, char *ln);
extern int		shvm_opword(t_op *op, char *ln);
extern int		shvm_opjump(t_op *op, char *ln);
extern int		shvm_opterm(t_op *op, char *ln);
extern int		shvm_opwait(t_op *op, char *ln);
extern int		shvm_oppipe(t_op *op, char *ln);
extern int		shvm_opfork(t_op *op, char *ln);

#endif
