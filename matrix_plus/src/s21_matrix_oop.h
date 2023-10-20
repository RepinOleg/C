#ifndef SRC_S21_MATRIX_OOP_H
#define SRC_S21_MATRIX_OOP_H

class S21Matrix {
 private:
  int rows_;
  int cols_;
  double* matrix_;

  S21Matrix MatrixReduction(int column) const;
  S21Matrix MinorMatrix(int row, int column) const;

 public:
  S21Matrix() noexcept;
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  ~S21Matrix();

  int get_rows() const noexcept;
  int get_cols() const noexcept;
  void set_rows(int row);
  void set_cols(int columns);

  // functions
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  double Determinant() const;
  S21Matrix Transpose() const noexcept;
  S21Matrix CalcComplements() const;
  S21Matrix InverseMatrix() const;

  double& operator()(int i, int j);
  double operator()(int i, int j) const;

  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*(const double num) const;

  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);

  bool operator==(const S21Matrix& other) const;
};

#endif  // SRC_S21_MATRIX_OOP_H