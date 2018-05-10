#include<iostream>
#include "Vector3D.h"
using namespace std;

int main()
{
	char task_input[5]; // ���-������� NUM � 4 �������(1000)+ '*' + '\0' = 5, ���� ����� �� 0;
	int number_vectors;
	cin >> task_input >> number_vectors;

	Vector3D *vectors = new Vector3D[number_vectors];	// �������� ��������� ����� �� ������� ������ �� ����� ������� �� ������;
	Vector3D new_vector;   // ������� ��� ������;
	Vector3D first_vector; // ���� ������ ������;

	if (task_input[0] == '+')									// �������� �� �������;
	{
		for (int i = 0; i < number_vectors; i++)
		{
			cin >> vectors[i];
		}
		for (int i = 0; i < number_vectors; i++)			// ������� ��� ��� ������ ����� ���� ������ �� ���������� ������� (new_vector) � �������� ��� ����� �������;
		{
			new_vector = new_vector + vectors[i];
		}
		cout << new_vector;
	}

	if (task_input[0] == '-')									// ��������� �� ������� �� ������;
	{														// ��� ��������� ���������� �� ���������; ���� '�' � ������� ������,� 'v' ����� �������;

		for (int i = 0; i < number_vectors; i++)			// x -v-v...-v = (-x +v+v...+v) * -1;  (-x +v+v...+v) = (x +v+v...+v - x -x) ;
		{													// ������: 1-2-3 � ����� �� -4, � ( 1+2+3 -1-1 )*-1 ���� � ����� �� -4;
			cin >> vectors[i];
		}
		first_vector = vectors[0];
		for (int i = 0; i < number_vectors; i++)
		{
			new_vector = new_vector + vectors[i];
		}
		cout << (new_vector - (first_vector * 2))*-1;
	}

	if (task_input[0] == 'N' && task_input[1] == 'E' && task_input[2] == 'G')	// ������� �� �������;
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

	if (task_input[0] == '*')										// ��������� �� ������ � �����;
	{
		int number = task_input[1] - '0';				// ������ ����� � char, number �� ������ ���������� �� ������� �� ���� ���������, ������ ����� ���������� �� '0';
		for (int i = 0; i < number_vectors; i++)
		{
			cin >> vectors[i];
		}
		for (int i = 0; i < number_vectors; i++)
		{
			cout << number * vectors[i];
		}
	}

	int number = 0;												// ��������� �� ����� � ������;
	if (task_input[0] >= '0' && task_input[0] <= '9')
	{												// ����������� ���� ����� ������� ������ � ����� � ������ ���� ����� ����� �� �������� <����. 4(1000)> ���������
		if (task_input[1] >= '0' && task_input[1] <= '9')		// ������ number;
		{														// �������� ���� :345 => 3*100 + 4*10 + 5*1;
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

		for (int i = 0; i < number_vectors; i++)				// ������ ���� ��������� �� ������ � �����
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