/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/job.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_JOB_H
# define SHVM_JOB_H

# include "proc.h"

typedef struct	s_pipeline
{
	t_proc		*beg;
	t_proc		*end;
}				t_pipeline;

typedef struct	s_job
{
	pid_t		pgid;
	t_pipeline	pipeline;
}				t_job;

extern void		shvm_jobctor(t_job *job);
extern t_job	*shvm_jobget(uint8_t idx);
extern t_bool	shvm_jobrem(uint8_t idx, t_job *out);
extern int		shvm_jobpmark(t_job *job, pid_t pid, int status);
extern void		shvm_jobwait(t_job *job);
extern void		shvm_jobkill(t_job *job);
extern void		shvm_jobcont(t_job *job, int fg);
extern t_bool	shvm_jobcompleted(t_job *job);
extern t_bool	shvm_jobstopped(t_job *job);

#endif
