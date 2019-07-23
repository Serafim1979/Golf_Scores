#include<iostream>
/////////////////////////////////////////////////////
using std::cout;
using std::cin;
using std::endl;
/////////////////////////////////////////////////////
const int ARR_SIZE = 10;
/////////////////////////////////////////////////////
void enter_scores(double * arr);
void show_results(double * arr, int sz);
double show_average(double * arr, int sz);
/////////////////////////////////////////////////////
int main()
{
	double * golfScores = new double[ARR_SIZE];
	for (int i = 0; i < ARR_SIZE; ++i)
		golfScores[i] = -1;

	cout << "Please enter your golf scores.\n"
		<< "You may enter up to " << ARR_SIZE
		<< " golf scores <q to terminate>.\n";

	enter_scores(golfScores);

	int sz = 0;

	for (int i = 0; i < ARR_SIZE; ++i)
		if (golfScores[i] >= 0)
			++sz;

	if (sz > 0)
	{
		cout << "There are results: ";
		show_results(golfScores, sz);
		cout << "\nAverage value is: " <<
			show_average(golfScores, sz) << endl;
	}
	else
	{
		cout << "No results, because you prefer quit program.\n"
			<< "Bye then.\n";
	}

	delete[] golfScores;

	system("pause");
	return 0;
}
//////////////////////////////////////////////////////
void enter_scores(double * arr)
{
	cout << "Scores #1: ";

	for (int i = 0; i < ARR_SIZE; ++i)
	{
		if (cin >> arr[i])
		{
			cout << "Score #" << i + 2 << ": ";
		}
		else
		{
			arr[i] = -1;
			break;
		}
	}
}
//////////////////////////////////////////////////////
void show_results(double * arr, int sz)
{
	for (int i = 0; i < sz; ++i)
		cout << arr[i] << " ";
}
//////////////////////////////////////////////////////
double show_average(double * arr, int sz)
{
	double sum = 0;
	for (int i = 0; i < sz; ++i)
		sum += arr[i];
	return sum / sz;
}