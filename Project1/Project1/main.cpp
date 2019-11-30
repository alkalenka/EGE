#include <iostream>
#include <chrono>

using namespace std;

void printMatrix(double** a, int n = 3)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void initializeMatrixWithValue(double** a, double value, int n = 3)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			a[i][j] = value;
		}
	}
}

void initialize1MatrixByPrepod(double** A, int N, double a)
{
	auto startTime = std::chrono::steady_clock::now();
	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < N; ++y)
		{
			A[x][y] = a + 0.0000001 * (x + N * y);
		}
	}
	auto endTime = std::chrono::steady_clock::now();
	auto elapsedNS = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	std::cout << "initialize matix A time = " << elapsedNS.count() << " ns\n";
}

void initialize2MatrixByPrepod(double** B, int N, double b)
{
	auto startTime = std::chrono::steady_clock::now();
	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < N; ++y)
		{
			B[x][y] = b - 0.0000001 * (x + N * y);
		}
	}
	auto endTime = std::chrono::steady_clock::now();
	auto elapsedNS = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	std::cout << "initialize matix B time = " << elapsedNS.count() << " ns\n";
}

void multMatrix1(double **a, double** b, double** mult, int n = 3)
{
	auto startTime = std::chrono::steady_clock::now();
	initializeMatrixWithValue(mult, 0);
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
	auto endTime = std::chrono::steady_clock::now();
	auto elapsedNS = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	std::cout << "mult1 time = " << elapsedNS.count() << " ns\n";
}

void multMatrix2(double** a, double** b, double** mult, int n = 3)
{
	auto startTime = std::chrono::steady_clock::now();
	initializeMatrixWithValue(mult, 0);
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
	auto endTime = std::chrono::steady_clock::now();
	auto elapsedNS = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
	std::cout << "mult2 time = " << elapsedNS.count() << " ns\n";
}

int main()
{
	int N = 0;
	cin >> N;

	#pragma region Выделение памяти
	double** A = new double* [N];
	double** B = new double* [N];
	double **C = new double* [N];
	double** D = new double*[N];
	for (int i = 0; i < N; ++i)
	{
		A[i] = new double[N];
		B[i] = new double[N] ;
		C[i] = new double[N];
		D[i] = new double[N];
	}
	#pragma endregion
	
	double a = 0;
	double b = 0;
	cin >> a >> b;

	initialize1MatrixByPrepod(A, N, a);
	initialize2MatrixByPrepod(B, N, b);
	
	multMatrix1(A, B, C);

	multMatrix2(A, B, D);

	#pragma region Очистка памяти
	for (int i = 0; i < N; ++i)
	{
		delete[] A[i];
		delete[] B[i];
		delete[] C[i];
		delete[] D[i];
		delete[] A;
		delete[] B;
		delete[] C;
		delete[] D;
	}
	#pragma endregion

	return 0;
}