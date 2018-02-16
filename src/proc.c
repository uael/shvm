/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/13 08:28:05 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shvm/proc.h"

extern void		shvm_procctor(t_proc *proc);
extern t_bool	shvm_procfork(t_proc *proc, pid_t *pgid, int *io, int fg);
extern int		shvm_procexec(t_proc *proc, char *bin, char *av[], char *ev[]);
extern void		shvm_procmark(t_proc *proc, int status);
