/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:10:22 by ade-fran          #+#    #+#             */
/*   Updated: 2024/03/06 18:10:24 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_data
{
	int		ac;
	char	**av;
	char	**envp;
	char	**paths;
	int		nb_cmd;
	int		index_cmd;
	int		heredoc[2];
	int		if_heredoc;
}	t_data;

void	ft_init_data(t_data *data, int argc, char **argv, char **envp);
int		if_heredoc(char *arg);
void	ft_get_heredoc(char *limiter, int heredoc[2], int fd);
char	**ft_split_env(char **envp);
char	**ft_split_cmd(char *str_cmd, int *err);
char	*ft_search_path(char **env_tab, char *cmd, int *err);

void	ft_exec_cmd(t_data data);

typedef struct s_child
{
	char	**cmd;
	char	*path;
	int		infile;
	int		outfile;
}	t_child;

void	ft_init_child_data(t_child *data);
void	ft_manage_child(t_data data, char *str_cmd, int pipefd[2], int nb_cmd);

int		ft_manage_heredoc(t_data data, int pipefd[2]);
int		ft_manage_infile(t_child *c_data, char *file, int pipefd[2]);
int		ft_inter_file(int pipefd[2]);
int		ft_manage_outfile(t_child *c_data, t_data data, char *file,
			int pipefd[2]);

enum	e_errors
{
	SPLIT_ENV = 2,
	SEARCH_PATH = 3,
	CMD_NOT_FOUND = 127,
	PERM_DENIED = 126,
	PIPE_ERR = 5,
	FORK_ERR = 6,
	SPLIT_CMD = 7,
	EXEC_ERR = 126,
	FILE_ACCESS = 9,
	OPEN_FILE = 10,
	DUP_ERR = 11,
	CMD_ACCESS = 13,
	GNL_ERR = 14,
};

# define HD "pipex: warning: here-document delimited by end-of-file (wanted '"

void	ft_errors(int err);
void	ft_cmd_errors(int err, char *arg, int *error);
void	ft_file_errors(char *file);
void	ft_null_env_err(t_child c_data, t_data data, int pipefd[2], int *err);
void	ft_execve_err(t_child c_data, t_data data, int pipefd[2], int *err);

void	ft_close_pipe(int pipefd[2]);
void	ft_exit_child(t_child c_data, t_data data, int pipefd[2], int status);
int		ft_get_exit_status(int pid);
void	ft_exit_prog(int pipefd[2], int prev_fd, int pid, int err);

#endif
