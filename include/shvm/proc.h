/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/proc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_PROC_H
# define SHVM_PROC_H

# include <libft.h>

enum e_state
{
	STATE_COMPLETED = 0,
	STATE_STOPPED,
	STATE_RUNNING,
	STATE_CONTINUED
};

typedef struct	s_proc
{
	pid_t		pid;
	uint8_t		state;
	uint8_t		status;
}				t_proc;

extern void		shvm_procctor(t_proc *proc);
extern t_bool	shvm_procfork(t_proc *proc, pid_t *pgid, int *io, int fg);
extern int		shvm_procexec(t_proc *proc, char *bin, char *av[], char *ev[]);
extern void		shvm_procmark(t_proc *proc, int status);

#endif
