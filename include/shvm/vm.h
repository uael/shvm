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

# include <term.h>

# include "op.h"

# ifndef TTY
#  define TTY struct termios
# endif
# ifndef CHILD_MAX
#  define CH_MAX 266
# else
#  define CH_MAX CHILD_MAX
# endif
# define OP_MAX UINT16_MAX

/*
** The shvm struct contains all required information and shell environment
** to execute shell instruction(s).
*/

typedef struct	s_shvm
{
	TTY			tcmode;
	pid_t		pid;
	t_scope		scope[CH_MAX];
	uint8_t		sc;
	t_map		binaries;
	t_map		builtins;
	t_map		locals;
	t_map		aliases;
	t_vec		env;
	t_op		op[OP_MAX];
	uint16_t	oc;
	t_proc		ch[CH_MAX];
	uint8_t		cc;
	t_job		bg[CH_MAX];
	uint8_t		bc;
	t_job		fg;
	t_ctx		*ctx;
}				t_shvm;

extern t_shvm	*g_shvm;

extern void		shvm_ctor(int fd, int ac, char *av[], char *ev[]);
extern void		shvm_dtor(void);
extern void		shvm_reset(void);
extern int		shvm_eval(char *line);

#endif
