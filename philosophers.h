/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yosherau <yosherau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:09:59 by yosherau          #+#    #+#             */
/*   Updated: 2025/06/10 20:30:00 by yosherau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# if 1
#  define RED "\033[31m"
#  define RST "\033[0m"
#  define YELLOW "\033[33m"
#  define GREEN "\033[32m"
#  define BLUE "\033[34m"
#  define CYAN "\033[36m"
#  define MAGENTA "\033[35m"
#  define WHITE "\033[1;37m"
# else
#  define RED ""
#  define RST ""
#  define YELLOW ""
#  define GREEN ""
#  define BLUE ""
#  define CYAN ""
#  define MAGENTA ""
#  define WHITE ""
# endif


# define INVALID_ARGS "Invalid number of args\n"
# define INVALID_ARG_FORMAT "Args provided is invalid\n"
# define INVALID_ARG_VALUE "Args provided has invalid values\n"
# define ADDITION_ASCII 43
# define SUBTRACTION_ASCII 45
# define ZERO_ASCII 48
# define NINE_ASCII 57
# define HORIZONTAL_TAB 9
# define CARRIAGE_RETURN 13
# define SPACE_ASCII 32

typedef enum e_time_measurement
{
	MICRO,
	MILLI,
	SECONDS
}	t_time_measurement;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	fork;
}	t_fork;

typedef struct s_philo
{
	int				id;
	long			meals_eaten;
	long			last_meal;
	t_fork			*first_fork;
	t_fork			*second_fork;
	pthread_t		thread;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	last_meal_lock;
	struct s_prog	*prog;
}	t_philo;

typedef struct s_prog
{
	long			num_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			sim_start;
	long			meals_to_have;
	long			threads_running;
	bool			threads_ready;
	bool			sim_has_ended;
	bool			limit_meals;
	bool			philo_dieded;
	t_fork			*forks;
	t_philo			*philos;
	pthread_t		monitor_thread;
	pthread_mutex_t	threads_running_lock;
	pthread_mutex_t	threads_ready_lock;
	pthread_mutex_t	sim_end_lock;
	pthread_mutex_t	print_lock;
}	t_prog;

int		ft_isspace(char c);
int		ft_isdigit(char c);
int		check_init(t_prog *prog);
int		check_input(int argc, char *argv[]);
long	ft_atol(char *str);
void	init_forks(t_prog *prog);
void	init_prog(int argc, char *argv[], t_prog *prog);
void	init_philos(t_prog *prog);
int		print_error(char *message);
long	get_time(t_time_measurement time_measurement);
void	*start_routine(void *args);
void	precise_sleep(long usec, t_prog *prog);
void	set_bool(pthread_mutex_t *lock, bool *dest, bool value);
void	set_long(pthread_mutex_t *lock, long *dest, long value);
long	get_long(pthread_mutex_t *lock, long *dest);
bool	get_bool(pthread_mutex_t *lock, bool *dest);
void	print_status(t_philo *philo, t_prog *prog, char *message);
void	start_eating(t_philo *philo, t_prog *prog);
void	start_sleeping(t_philo *philo, t_prog *prog);
void	start_thinking(t_philo *philo, t_prog *prog);
void	wait_threads_ready(t_prog *prog);
void	wait_threads_running(t_prog *prog);
void	*start_monitoring(void *args);
void	*handle_one_philo(t_philo *philo, t_prog *prog);
void	stagger_threads(t_philo *philo, t_prog *prog);
void	destroy_mallocs(t_prog *prog);

#endif