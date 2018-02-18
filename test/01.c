/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alucas- <alucas-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 09:52:30 by alucas-           #+#    #+#             */
/*   Updated: 2017/12/11 13:31:59 by alucas-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shvm.h>

int main(int ac, char *av[], char *ev[])
{
	int st;

	shvm_ctor(STDIN_FILENO, ac, av, ev);
	shvm_reset();

	// sleep 1
	*shvm_oppush(NULL) = (t_op){OP_INIT,	OPF_FULL,			0,	0,	0}; 	// clear the context (full)
	*shvm_oppush(NULL) = (t_op){OP_BINA,	OPF_LOCK,			6,	5,	0}; 	// "sleep" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_FORK,	0,					0,	0,	0}; 	// fork
	*shvm_oppush(NULL) = (t_op){OP_WORD,	OPF_LOCK,			12,	1,	0}; 	// "1" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_EXEC,	0,					0,	0,	0}; 	// exec
	*shvm_oppush(NULL) = (t_op){OP_WAIT,	0,					0,	0,	0}; 	// wait proc

	// sleep 1 exited with 0 ?
	*shvm_oppush(NULL) = (t_op){OP_COMP,	0,					0,	0,	}; 	// if 0 continue else jump

	// cat /dev/random |
	*shvm_oppush(NULL) = (t_op){OP_INIT,	OPF_FULL,			0,	0,	0}; 	// clear the context (full)
	*shvm_oppush(NULL) = (t_op){OP_BINA,	OPF_LOCK,			18,	3,	0}; 	// "cat" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_FORK,	OPF_PIPE,			0,	0,	0}; 	// fork
	*shvm_oppush(NULL) = (t_op){OP_WORD,	OPF_LOCK,			22,	11,	0}; 	// "/dev/random" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_EXEC,	0,					0,	0,	0}; 	// exec

	// base64 |
	*shvm_oppush(NULL) = (t_op){OP_INIT,	0,					0,	0,	0}; 	// clear the context (only argv/envv)
	*shvm_oppush(NULL) = (t_op){OP_BINA,	OPF_LOCK,			36,	6,	0}; 	// "base64" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_FORK,	OPF_PIPE,			0,	0,	0}; 	// fork
	*shvm_oppush(NULL) = (t_op){OP_EXEC,	0,					0,	0,	0}; 	// exec

	// head -c 8
	*shvm_oppush(NULL) = (t_op){OP_INIT,	0,					0,	0,	0}; 	// clear the context (only argv/envv)
	*shvm_oppush(NULL) = (t_op){OP_BINA,	OPF_LOCK,			45,	4,	0}; 	// "head" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_FORK,	0,					0,	0,	0}; 	// fork
	*shvm_oppush(NULL) = (t_op){OP_WORD,	OPF_LOCK,			50,	2,	0}; 	// "-c" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_WORD,	OPF_LOCK,			53,	1,	0}; 	// "8" (locked because no quote/glob/var)
	*shvm_oppush(NULL) = (t_op){OP_EXEC,	0,					0,	0,	0}; 	// exec
	*shvm_oppush(NULL) = (t_op){OP_WAIT,	OPF_PIPE,			0,	0,	0}; 	// wait pipeline

	// loop
	*shvm_oppush(NULL) = (t_op){OP_GOTO,	0,					0,	0,	6}; 	// goto 6 (OP_COMP)

	// done
	*shvm_oppush(NULL) = (t_op){OP_TERM,	0,					0,	0,	0}; 	// return status

	st = shvm_eval(
		"while sleep 1; do cat /dev/random | base64 | head -c 8; done"
	);
	shvm_dtor();
	return (st);
}