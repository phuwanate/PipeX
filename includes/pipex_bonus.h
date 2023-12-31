/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plertsir <plertsir@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:32:16 by plertsir          #+#    #+#             */
/*   Updated: 2023/07/25 10:09:36 by plertsir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

typedef struct s_data
{
	int			**pipes;
	int			*pid;
	int			pipe_nb;
	int			proc;
	int			status;
	int			len_av;
}				t_data;

int		find_path(const char *s1);
void	get_path(t_data *data, char **envp, char **spl_av);
char	**get_cmd(t_data *data, char *av);
void	free_2d(char **ptr);
void	int_free_2d(int **ptr, int size);
void	go_exec(t_data *data, char *path, char **spl_av, char **envp);
void	cmd_err(t_data *data, char **spl_av);
void	param_error(void);
void	open_file(int proc_id, char **av, int ac);
void	data_status(t_data *data, int nb_proc, int ac);
void	close_infile(t_data *data, int id);
void	close_child(t_data *data, int id);
void	close_outfile(t_data *data, int id);
void	close_pipe_main(t_data *data);
void	file_error(char *file);
void	path_error(t_data *data, char **path);
void	free_mem(t_data *data, int status);
void	fork_error(t_data *data);
int		is_heredoc(char **av, int ac);
void	normal_infile(t_data *data, int ac, char **av, char **envp);
void	heredoc_infile(t_data *data, int ac, char **av, char **envp);
void	out_heredoc(char **av, int ac);
void	heredoc_status(t_data *data, int nb_proc, int ac);
int		end_doc(char *hay_stack, char *needle);
void	check_slash(t_data *data, char *cmd, char **spl_av, char **envp);
int		doc_cmp(const char *s1, const char *s2);

#endif