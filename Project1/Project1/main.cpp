#include <iostream>
#include <chrono>

using namespace std;

void initializeMatrixWithValue(double** a, int n, double value)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = value;
		}
	}
}

void initializeMatrixA(double** a, int n, double value)
{
	auto startTime = chrono::steady_clock::now();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = value + 0.0000001 * (i + n * j);
		}
	}
	auto endTime = chrono::steady_clock::now();
	auto elapsedNS = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
	cout << "initialize matix A time = " << elapsedNS.count() << " ns\n";
}

void initializeMatrixB(double** a, int n, double value)
{
	auto startTime = chrono::steady_clock::now();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = value - 0.0000001 * (i + n * j);
		}
	}
	auto endTime = chrono::steady_clock::now();
	auto elapsedNS = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
	cout << "initialize matix B time = " << elapsedNS.count() << " ns\n";
}

void multMatrix1(double** a, double** b, double** mult, int n)
{
	auto startTime = chrono::steady_clock::now();
	initializeMatrixWithValue(mult, n, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				mult[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	auto endTime = chrono::steady_clock::now();
	auto elapsedNS = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
	cout << "mult1 time = " << elapsedNS.count() << " ns\n";
}

void multMatrix2(double** a, double** b, double** mult, int n)
{
	auto startTime = chrono::steady_clock::now();
	initializeMatrixWithValue(mult, n, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			for (int j = 0; j < n; ++j)
			{
				mult[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	auto endTime = chrono::steady_clock::now();
	auto elapsedNS = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
	cout << "mult2 time = " << elapsedNS.count() << " ns\n";
}

void multMatrix3(double** a, double** b, double** mult, int n)
{
	auto startTime = chrono::steady_clock::now();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			double r = 0;
			for (int k = 0; k < n; ++k)
			{
				r += a[i][k] * b[k][j];
			}
			mult[i][j] = r;
		}
	}
	auto endTime = chrono::steady_clock::now();
	auto elapsedNS = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
	cout << "mult3 time = " << elapsedNS.count() << " ns\n";
}

int main()
{
	int N = 0;
	cin >> N;

	#pragma region Выделение памяти
	double** A = new double*[N];
	double** B = new double*[N];
	double** C = new double*[N];
	for (int i = 0; i < N; ++i)
	{
		A[i] = new double[N];
		B[i] = new double[N];
		C[i] = new double[N];
	}
	#pragma endregion

	#pragma region Инициалищация
	double a = 0;
	double b = 0;
	cin >> a >> b;

	initializeMatrixA(A, N, a);
	initializeMatrixB(B, N, b);
	#pragma endregion

	#pragma region Умножения, собственно
	multMatrix1(A, B, C, N);
	cout << "C[0][0] = " << C[0][0] << "; " << "C[N - 1][N - 1] = " << C[N - 1][N - 1] << endl;
	multMatrix2(A, B, C, N);
	cout << "C[0][0] = " << C[0][0] << "; " << "C[N - 1][N - 1] = " << C[N - 1][N - 1] << endl;
	multMatrix3(A, B, C, N);
	cout << "C[0][0] = " << C[0][0] << "; " << "C[N - 1][N - 1] = " << C[N - 1][N - 1] << endl;
	#pragma endregion

	#pragma region Очистка памяти
	for (int i = 0; i < N; ++i)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] C[i];
	}
	delete[] A;
	delete[] B;
	delete[] C;
	#pragma endregion

	return 0;
}