#include <stdio.h> /* printf */

/**
 * Computes the safe position in the Josephus problem.
 * @param number_of_people Number of people standing in the circle.
 * @param kill_step The k-th person will be eliminated.
 * @return Index of the last surviving person.
 * 
 * Author: Ben
 * Date: 2024-08
 */

int Josephus(int const number_of_people, int const kill_step);

int main()
{
	int const number_of_people = 200;
    int const kill_step = 2;
    int last_person;

    last_person = Josephus(number_of_people, kill_step);
    
    printf("The index of the last person (1-based) is: %d\n", last_person + 1);

    return 0;
}


int Josephus(int const number_of_people, int const kill_step) 
{
    int last_survivor_index = 0;
	int i;
	
    for (i = 2; i <= number_of_people; ++i) 
    {
        last_survivor_index = (last_survivor_index + kill_step) % i;
    }

    return last_survivor_index;
}

