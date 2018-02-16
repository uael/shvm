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
extern t_op		*shvm_opjump(uint16_t it, uint16_t jump);
extern t_op		*shvm_opor(uint16_t it, uint16_t flag);

extern int		shmv_opexec(t_op *op, char *ln);
extern int		shmv_opword(t_op *op, char *ln);
extern int		shmv_opjump(t_op *op, char *ln);
extern int		shmv_opterm(t_op *op, char *ln);
extern int		shmv_opwait(t_op *op, char *ln);
extern int		shmv_oppipe(t_op *op, char *ln);
extern int		shmv_opfork(t_op *op, char *ln);

#endif
