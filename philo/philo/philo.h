/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:38:54 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/12/01 12:11:20 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct t_table
{
	int				num_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	long long		start_time;
	int				someone_died;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_t		waiter_thread;
}	t_table;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long long		last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table			*table;
}	t_philo;

//Parse
int			ft_isdigit(int c);
int			ft_isspace(int c);
long		ft_atol(char *str);
int			validate_args(int argc, char **argv);
/**
 * @brief Initializes the simulation table with command-line
 * parameters and mutexes.
 * This function reads the philosopher count, timing constraints,
 * and optional meal limit from the CLI arguments, records the simulation
 * start time, resets the death flag, and initializes the synchronization
 * primitives required for the table.
 * @param argc Argument count
 * @param argv Argument vector
 * @param table Pointer to the struct of table
 * @return 0 on success or 1 if mutex initialization fails.
 */
int			init_table(int argc, char **argv, t_table *table);
/**
 * @brief Initializes each philosopher structure with its identifier, 
 * fork references, meal counters, timestamps, and a pointer to the
 * shared table context.
 *
 * @param philo  Array of philosopher structures to initialize.
 * @param table  Shared dining table data, including forks and timing info.
 * @return       Always returns 0 on successful initialization.
 */
int			init_philo(t_philo *philo, t_table *table);
/**
 * @brief Initialize the synchronization mutexes of the table.
 *
 * This function sets up the print, death, and meal mutexes used to
 * coordinate philosopher threads. If any mutex fails to initialize,
 * an error is reported and initialization stops.
 *
 * @param table Pointer to the simulation table holding the mutexes.
 * @return 0 on success, 1 if any mutex initialization fails.
 */
int			init_forks(t_table *table);
/**
 * @brief Initialize the synchronization mutexes of the table.
 *
 * This function sets up the print, death, and meal mutexes used to
 * coordinate philosopher threads. If any mutex fails to initialize,
 * an error is reported and initialization stops.
 *
 * @param table Pointer to the simulation table holding the mutexes.
 * @return 0 on success, 1 if any mutex initialization fails.
 */
int			init_mutex(t_table *table);
/**
 * @brief Allocates memory for philosophers and forks arrays.
 *
 * This function allocates two dynamic arrays needed for the dining philosophers
 * simulation:
 * - An array of t_philo structures (philosophers)
 * - An array of pthread_mutex_t structures (forks)
 *
 * Both arrays have a length equal to table->num_philo.
 *
 * @param table Pointer to the main table structure containing simulation data.
 * @return 0 on success, 1 on allocation failure.
 * @note On failure, the function:
 *       - Prints an error message to stdout
 *       - Destroys the three pre-initialized mutexes (print_mutex, death_mutex, meal_mutex)
 *       - Frees any previously allocated memory (if forks allocation fails)
 */
int			mem_alloc(t_table *table);
int			hollocaust_mutex(t_table *table, int size);
long long	get_time(void);
void		precise_time(t_philo *philo, long long time);
void		print_pthread(t_philo *philo, char *str);
//Routine
void		*start_routine(void *arg);
void		eat_routine(t_philo *philo);
void		sleep_routine(t_philo *philo);
void		think_routine(t_philo *philo);
void		*one_notes(void *arg);
//Monitor
void		*waiter_routine(void *arg);
int			check_death(t_philo *philo);
int			death_row(t_philo *philo);
int			check_all_ate(t_table *table);
//Threads
int			first_init_thread(t_table *table);
int			second_init_thread(t_table *table);

#endif