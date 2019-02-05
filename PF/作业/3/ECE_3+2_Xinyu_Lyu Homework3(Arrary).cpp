#include<iostream>
#include<iomanip>

using namespace std;
void Menu();
void InputArray10(double a[10][10], int& row, int& column);
void OutputArray10(double a[10][10], int row, int column);
void Addition(double a[10][10], double b[10][10], double c[10][10], int row1, int column1, int row2, int column2);
void Subtraction(double a[10][10], double b[10][10], double c[10][10], int row1, int column1, int row2, int column2);
void Multiplication(double a[10][10], double b[10][10], int row1, int column1, int row2, int column2);
void Transpose(double a[10][10], int row, int column);
void InputArray3(double a[3][3], int& row, int& column);
double  Determinant(double a[3][3]);
void  Inverse(double a[3][3], int row, int column);
void OutputArray3(double a[3][3], int row, int column);
int main()
{
	int choice;
	double A[10][10] = {  }; 
	double B[10][10] = {  };
	double C[10][10] = {  };
	double D[3][3] = {  };
	int row1;
	int column1;
	int row2;
	int column2;
	double t;
	
	do
	{
	do {
		Menu();
		cout << "Enter your Choice(1=<choice<=7):" << endl;
		cin >> choice;
	} while (choice > 7 || choice < 1);

	switch (choice)
	{
	case 1:
		InputArray10(A, row1, column1);
		cout << "Your input is:" << endl;
		OutputArray10(A, row1, column1);
		InputArray10(B, row2, column2);
		cout << "Your input is:" << endl;
		OutputArray10(B, row2, column2);
		Addition(A, B, C, row1, column1, row2, column2);                              //Add two matrix and output
		break;
	case 2:
		InputArray10(A, row1, column1);
		cout << "Your input is:" << endl;
		OutputArray10(A, row1, column1);
		InputArray10(B, row2, column2);
		cout << "Your input is:" << endl;
		OutputArray10(B, row2, column2);
		Subtraction(A, B, C, row1, column1, row2, column2);
		break;
	case 3:
		InputArray10(A, row1, column1);
		cout << "Your input is:" << endl;
		OutputArray10(A, row1, column1);
		InputArray10(B, row2, column2);
		cout << "Your input is:" << endl;
		OutputArray10(B, row2, column2);
		Multiplication(A, B, row1, column1, row2, column2);                             //Multiply two matrix and output
		break;
	case 4:
		InputArray10(A, row1, column1);
		cout << "Your input is:" << endl;
		OutputArray10(A, row1, column1);
		Transpose(A, row1, column1);                                                     //Transpose 3*3 matrix and output
		break;
	case 5:
		InputArray3(D, row1, column1);
		cout << "Your input is:" << endl;
		OutputArray3(D, row1, column1);
		t = Determinant(D);                                                                //Calculate the Determinant of 3*3 matrix
		cout << "Determinant is:" << fixed <<setprecision(4)<< t << endl;
		break;
	case 6:
		InputArray3(D, row1, column1);
		cout << "Your input is:" << endl;
		OutputArray3(D, row1, column1);
		Inverse(D, row1, column1);                                                             //Get the Inverse of 3*3 matrix and output
		break;
	case 7:
		break;
	default:
		break;
	}

	} while (choice!=7);
		system("pause");
		return 0;
	
} 
void InputArray10(double a[10][10], int& row, int& column)                                          //Input 10*10 matrix
{
	do {
		cout << "Please enter the number of row(1=<row<=10):" << endl;
		cin >> row;
	} while (row>10 || row<1);
	do {
		cout << "Please enter the number of column(1=<column<=10):" << endl;
		cin >> column;
	} while (column > 10 || column < 1);

	cout << "Please enter the values of elements:" << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> a[i][j];
		}
	}
}

void InputArray3(double a[3][3], int& row, int& column)                                              //Input 3*3 matrix
{
	do {
		cout << "Please enter the number of row(3):" << endl;
		cin >> row;
	} while (row!=3 );
	do {
		cout << "Please enter the number of column(3):" << endl;
		cin >> column;
	} while (column != 3);

	cout << "Please enter the values of elements:" << endl;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cin >> a[i][j];
		}
	}
}

void OutputArray10(double a[10][10], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << fixed << setprecision(4) << setw(10) << a[i][j];
		}
		cout << endl;
	}
}

void OutputArray3(double a[3][3], int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			cout << fixed << setprecision(4) << setw(10) << a[i][j];
		}
		cout << endl;
	}
}

void Addition(double a[10][10], double b[10][10], double c[10][10], int row1, int column1, int row2, int column2)
{
	if (row1 == row2&&column1 == column2)                                                           //Judge whether two matrix can add or not
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < column1; j++)
			{
				c[i][j] = a[i][j] + b[i][j];
			}
		}
		cout << "The result is:" << endl;
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j < column2; ++j)
			{
				cout << fixed << setprecision(4) << setw(10) << c[i][j];
			}
			cout << endl;
		}
	}
	else
		cout << "These two matrix can't be added!" << endl;
}

void Subtraction(double a[10][10], double b[10][10], double c[10][10], int row1, int column1, int row2, int column2)
{
	if (row1 == row2&&column1 == column2)                                                              //Judge whether two matrix can substract or not
	{
		for (int i = 0; i < row1; i++)
		{
			for (int j = 0; j < column1; j++)
			{
				c[i][j] = a[i][j] - b[i][j];
			}
		}
		cout << "The result is:" << endl;
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j < column2; ++j)
			{
				cout << fixed << setprecision(4) << setw(10) << c[i][j];
			}
			cout << endl;
		}
	}
	else	
	cout << "These two matrix can't be substracted!" << endl;
}


void Multiplication(double a[10][10], double b[10][10], int row1, int column1, int row2, int column2)
{
	double c[10][10] = {};
	if (row2 == column1)                                                                                  //Judge whether two matrix can multipy or not
	{
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j< column2; ++j)
			{
				for (int k = 0; k<column1; ++k)
				{
					c[i][j]+= a[i][k] * b[k][j];
				}
			}
		}
		cout << "result:" << endl;
		for (int i = 0; i < row1; ++i)
		{
			for (int j = 0; j < column2; ++j)
			{
				cout << fixed << setprecision(4) << setw(10) << c[i][j];
			}
			cout << endl;
		}
	}
	else
		cout << "These two matrix can't multiply!" << endl;
}

void Transpose(double a[10][10], int row, int column)
{
	cout << "Its Transpose is:" << endl;
	for (int i = 0; i < column; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << fixed << setprecision(4) << setw(10) << a[j][i];
		}
		cout <<endl;
	}
}

double  Determinant(double a[3][3])
{
	double c;
	double b;
	double t;
	c = a[0][0] * a[1][1] * a[2][2] + a[1][0] * a[2][1] * a[0][2] + a[0][1] * a[1][2] * a[2][0];             //Calculate Deteminant
	b = a[0][2] * a[1][1] * a[2][0] + a[0][1] * a[1][0] * a[2][2] + a[0][0] * a[1][2] * a[2][1];
	t = c - b;
	return t;
}
void Inverse(double a[3][3],int row ,int column)
{
	double b[3][3] = { 0 };
	double c[3][3] = { 0 };
	double t = 0;
	t = Determinant(a);
	if (t != 0)
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				b[j][i] = a[i][j];
			}
		}
		c[0][0] = b[1][1] * b[2][2] - b[1][2] * b[2][1];
		c[0][1] = b[1][0] * b[2][2] - b[1][2] * b[2][0];
		c[0][2] = b[1][0] * b[2][1] - b[1][1] * b[2][0];

		c[1][0] = b[0][1] * b[2][2] - b[0][2] * b[2][1];
		c[1][1] = b[0][0] * b[2][2] - b[0][2] * b[2][0];
		c[1][2] = b[0][0] * b[2][1] - b[2][0] * b[0][1];

		c[2][0] = b[0][1] * b[1][2] - b[0][2] * b[1][1];
		c[2][1] = b[0][0] * b[1][2] - b[1][0] * b[0][2];
		c[2][2] = b[0][0] * b[1][1] - b[0][1] * b[1][0];

		c[0][1] = -c[0][1];

		c[1][0] = -c[1][0];
		c[1][2] = -c[1][2];

		c[2][1] = -c[2][1];
		cout << "The inverse is:" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				c[i][j] = c[i][j] / t;
				cout << fixed << setprecision(4) << setw(10) << c[i][j];
			}
			cout << endl;
		}
	}
	else cout << "There is no inverse array for it." << endl;
}

void Menu()
{
	cout << "Menu" << endl;
	cout << "Choice 1: Addition" << endl;
	cout << "Choice 2: Substraction" << endl;
	cout << "Choice 3: Multiplication" << endl;
	cout << "Choice 4: Transpose" << endl;
	cout << "Choice 5: Determinant" << endl;
	cout << "Choice 6: Inverse" << endl;
	cout << "Choice 7: Quit" << endl;
}
