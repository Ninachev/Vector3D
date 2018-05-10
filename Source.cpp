#include<iostream>
#include "Vector3D.h"
using namespace std;

int main()
{
	char task_input[5]; // най-дългото NUM е 4 символа(1000)+ '*' + '\0' = 5, като бройм от 0;
	int number_vectors;
	cin >> task_input >> number_vectors;

	Vector3D *vectors = new Vector3D[number_vectors];	// Заделяме динамично масив от вектори защото не знаем точната им бройка;
	Vector3D new_vector;   // Създава нов вектор;
	Vector3D first_vector; // Пази първия вектор;

	if (task_input[0] == '+')									// Сумиране на вектори;
	{
		for (int i = 0; i < number_vectors; i++)
		{
			cin >> vectors[i];
		}
		for (int i = 0; i < number_vectors; i++)			// Създали сме нов вектор който пази сумата на предишните вектори (new_vector) и събираме със всеки следващ;
		{
			new_vector = new_vector + vectors[i];
		}
		cout << new_vector;
	}

	if (task_input[0] == '-')									// Изваждане на вектори от първия;
	{														// Тук използвам сумирането за улеснение; Нека 'х' е първият вектор,а 'v' всеки следващ;

		for (int i = 0; i < number_vectors; i++)			// x -v-v...-v = (-x +v+v...+v) * -1;  (-x +v+v...+v) = (x +v+v...+v - x -x) ;
		{													// Пример: 1-2-3 е равно на -4, а ( 1+2+3 -1-1 )*-1 също е равно на -4;
			cin >> vectors[i];
		}
		first_vector = vectors[0];
		for (int i = 0; i < number_vectors; i++)
		{
			new_vector = new_vector + vectors[i];
		}
		cout << (new_vector - (first_vector * 2))*-1;
	}

	if (task_input[0] == 'N' && task_input[1] == 'E' && task_input[2] == 'G')	// Негация на вектори;
	{
		for (int i = 0; i < number_vectors; i++)
		{
			cin >> vectors[i];
		}
		for (int i = 0; i < number_vectors; i++)
		{
			cout << vectors[i] * -1;
		}
	}

	if (task_input[0] == '*')										// Умножение на вектор с число;
	{
		int number = task_input[1] - '0';				// Понеже входа е char, number ще приеме стойността на символа от аски таблицата, затова вадим стойността на '0';
		for (int i = 0; i < number_vectors; i++)
		{
			cin >> vectors[i];
		}
		for (int i = 0; i < number_vectors; i++)
		{
			cout << number * vectors[i];
		}
	}

	int number = 0;												// Умножение на число с вектор;
	if (task_input[0] >= '0' && task_input[0] <= '9')
	{												// Проверяваме дали всеки въведен символ е число и според това колко числа са въведени <макс. 4(1000)> съставяме
		if (task_input[1] >= '0' && task_input[1] <= '9')		// самото number;
		{														// Примерен вход :345 => 3*100 + 4*10 + 5*1;
			if (task_input[2] >= '0' && task_input[2] <= '9')
			{
				if (task_input[3] >= '0' && task_input[3] <= '9')
				{
					number = (task_input[0] - '0') * 1000 + (task_input[1] - '0') * 100 + (task_input[2] - '0') * 10 + (task_input[3] - '0');
				}
				else number = (task_input[0] - '0') * 100 + (task_input[1] - '0') * 10 + (task_input[2] - '0');
			}
			else number = (task_input[0] - '0') * 10 + (task_input[1] - '0');
		}
		else number = (task_input[0] - '0');

		for (int i = 0; i < number_vectors; i++)				// Същото като умножение на вектор с число
		{
			cin >> vectors[i];
		}
		for (int i = 0; i < number_vectors; i++)
		{
			cout << number * vectors[i];
		}
	}

	delete[] vectors;

	return 0;

}