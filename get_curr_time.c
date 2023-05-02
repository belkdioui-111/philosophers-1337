#include "philo.h"

long long get_curr_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long diff_bet_first_now(long long first, long long now)
{
	return (now - first);
}