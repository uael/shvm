/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shvm/ctx.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by cmalfroy          #+#    #+#             */
/*   Updated: 2017/12/06 12:00:10 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHVM_CTX_H
# define SHVM_CTX_H

# include "bi.h"
# include "job.h"
# include "scope.h"

# define AV_MAX UINT16_MAX

#include <sys/syslimits.h>

typedef struct	s_ctx
{
	t_scope		*scope;
	int			io[3];
	int			fds[2];
	t_bi		*bi;
	char		*bin;
	t_job		*job;
	char		*av[AV_MAX];
	t_vec		env;
	t_map		locals;
	uint16_t	ac;
}				t_ctx;

extern void		shvm_ctxctor(t_ctx *ctx);
extern void		shvm_ctxdtor(t_ctx *ctx);
extern void		shvm_ctxreset(t_ctx *ctx);

#endif
