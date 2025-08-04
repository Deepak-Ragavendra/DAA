#include <iostream>
#include <vector>

using namespace std;

int scalarMultiplications = 0;
int scalarAdditions = 0;

using Matrix = vector<vector<int>>;

Matrix addMatrix(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            result[i][j] = A[i][j] + B[i][j];
            scalarAdditions++;
        }
    }
    return result;
}

Matrix subMatrix(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix result(n, vector<int>(n, 0));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            result[i][j] = A[i][j] - B[i][j];
            scalarAdditions++; 
        }
    }
    return result;
}

Matrix multiplyMatrix(const Matrix &A, const Matrix &B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));

    if(n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        scalarMultiplications++;
    } else {
        int newSize = n / 2;
        Matrix A11(newSize, vector<int>(newSize));
        Matrix A12(newSize, vector<int>(newSize));
        Matrix A21(newSize, vector<int>(newSize));
        Matrix A22(newSize, vector<int>(newSize));

        Matrix B11(newSize, vector<int>(newSize));
        Matrix B12(newSize, vector<int>(newSize));
        Matrix B21(newSize, vector<int>(newSize));
        Matrix B22(newSize, vector<int>(newSize));

        for(int i = 0; i < newSize; ++i){
            for(int j = 0; j < newSize; ++j){
                A11[i][j] = A[i][j];
                A12[i][j] = A[i][j + newSize];
                A21[i][j] = A[i + newSize][j];
                A22[i][j] = A[i + newSize][j + newSize];

                B11[i][j] = B[i][j];
                B12[i][j] = B[i][j + newSize];
                B21[i][j] = B[i + newSize][j];
                B22[i][j] = B[i + newSize][j + newSize];
            }
        }

        Matrix M1 = multiplyMatrix(A11, B11);
        Matrix M2 = multiplyMatrix(A12, B21);
        Matrix M3 = multiplyMatrix(A11, B12);
        Matrix M4 = multiplyMatrix(A12, B22);
        Matrix M5 = multiplyMatrix(A21, B11);
        Matrix M6 = multiplyMatrix(A22, B21);
        Matrix M7 = multiplyMatrix(A21, B12);
        Matrix M8 = multiplyMatrix(A22, B22);

        Matrix C11 = addMatrix(M1, M2);
        Matrix C12 = addMatrix(M3, M4);
        Matrix C21 = addMatrix(M5, M6);
        Matrix C22 = addMatrix(M7, M8);

        for(int i = 0; i < newSize; ++i){
            for(int j = 0; j < newSize; ++j){
                C[i][j] = C11[i][j];
                C[i][j + newSize] = C12[i][j];
                C[i + newSize][j] = C21[i][j];
                C[i + newSize][j + newSize] = C22[i][j];
            }
        }
    }
    return C;
}

void printMatrix(const Matrix &mat) {
    for(const auto &row : mat){
        for(int val : row)
            cout << val << " ";
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix (n = 2^k): ";
    cin >> n;

    Matrix A(n, vector<int>(n));
    Matrix B(n, vector<int>(n));

    cout << "Enter matrix A:\n";
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> A[i][j];

    cout << "Enter matrix B:\n";
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> B[i][j];

    clock_t start = clock();
    Matrix C = multiplyMatrix(A, B);
    clock_t end = clock();

    cout << "\nResultant Matrix:\n";
    printMatrix(C);
    cout << "\nScalar Multiplications: " << scalarMultiplications << endl;
    cout << "Scalar Additions: " << scalarAdditions << endl;
    cout << "Time taken: " << (double)(end - start) / CLOCKS_PER_SEC << " seconds" << endl;
    return 0;
}