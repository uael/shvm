/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/vm.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_VM_H
# define SHVM_VM_H

# include "job.h"
# include "op.h"
# include "proc.h"

# ifndef CHILD_MAX
#  define CH_MAX 266
# else
#  define CH_MAX CHILD_MAX
# endif
# define AV_MAX UINT16_MAX
# define OP_MAX UINT16_MAX

/*
** The shvm struct contains all required information and shell environment
** to execute shell instruction(s).
*/

typedef struct	s_shvm
{
	uint8_t		status;
	t_map		binaries;
	t_map		builtins;
	t_map		locals;
	t_vec		env;
	char		*av[AV_MAX];
	uint16_t	ac;
	t_op		op[OP_MAX];
	uint16_t	oc;
	t_proc		ch[CH_MAX];
	uint8_t		cc;
	t_job		bg[CH_MAX];
	uint8_t		bc;
	t_job		fg;
}				t_shvm;

extern t_shvm	*g_shvm;

extern void		shvm_ctor(int fd, char *ev);
extern void		shvm_dtor(void);
extern int		shvm_reset(void);
extern int		shvm_eval(char *line);

#endif
