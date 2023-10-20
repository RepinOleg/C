#include "s21_matrix_oop.h"

#include <cmath>
#include <iostream>
#include <utility>

/*  Конструктор по умолчанию  */

S21Matrix::S21Matrix() noexcept : rows_(0), cols_(0), matrix_(nullptr) {}

/*  Конструктор */

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows < 0 || cols < 0) {
    throw std::length_error("Rows or columns must not be less than 0");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double[rows_ * cols_]();
}

/*  Деструктор */

S21Matrix::~S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  delete[] matrix_;
  matrix_ = nullptr;
}

/* Конструктор копирования */

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double[rows_ * cols_];
  std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

/* Конструктор переноса */

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.cols_ = 0;
  other.rows_ = 0;
}

/* Перегрузка = копированием*/

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    delete[] matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = new double[rows_ * cols_]();
    std::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
  }

  return *this;
}

/* Перегрузка присваивания перемещением */
S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);

  return *this;
}

/* Перегрузка оператора скобочки () */
/* Благодаря этой функции можно каждый раз не писать (matrix_ + i * cols_)[j]
const после функции озаначает что функция не меняет никаких значений */

double& S21Matrix::operator()(int i, int j) {
  /*
  Вызывать данную функцию нужно с помощью обьекта, а не конкретного поля
  класса)))*/
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Wrong indexes");
  }
  return (matrix_ + i * cols_)[j];
}

double S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Wrong indexes");
  }
  return (matrix_ + i * cols_)[j];
}

/* Получения приватного значения rows*/

int S21Matrix::get_rows() const noexcept { return rows_; }

/* Получения приватного значения cols*/

int S21Matrix::get_cols() const noexcept { return cols_; }

/* Сеттер значения rows_ */

void S21Matrix::set_rows(int rows) {
  if (rows < 0) {
    throw std::length_error("Rows value cannot be less than zero");
  }
  if (rows != rows_) {
    S21Matrix tmp(rows, cols_);
    for (int i = 0; i < std::min(rows, rows_); ++i) {
      for (int j = 0; j < cols_; ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    (*this) = std::move(tmp);
  }
}

/* Сеттер значения cols_ */

void S21Matrix::set_cols(int columns) {
  if (columns < 0) {
    throw std::length_error("Columns value cannot be less than zero");
  }

  if (columns != cols_) {
    S21Matrix tmp(rows_, columns);
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < std::min(columns, cols_); ++j) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    (*this) = std::move(tmp);
  }
}

/* Функция сравнения матриц*/

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  if (other.cols_ != cols_ || other.rows_ != rows_) {
    return false;
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      /* abs  в C++ можно использовать для чисел типа double*/
      if (std::abs((*this)(i, j) - other(i, j)) > 1e-7) return false;
    }
  }

  return true;
}

/* Функция суммирования матриц */

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error(
        "It is impossible to add matrices of different sizes");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) += other(i, j);
    }
  }
}

/* Функция вычитания матриц */

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::logic_error(
        "It is impossible to sub matrices of different sizes");
  }

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

/* Умножение матрицы на число */

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      (*this)(i, j) *= num;
    }
  }
}

/* Функция умножение матрицы на другую матрицу */

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.get_rows()) {
    throw std::logic_error(
        "The number of columns of the first matrix must be equal to the row "
        "value of the second matrix");
  }
  /* Приходится создавать временную матрицу чтобы не изменять поля матрицы this,
   * пока все вычисления не будут выполнены */
  S21Matrix result(rows_, other.get_cols());

  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < other.get_cols(); ++j) {
      for (int k = 0; k < other.get_rows(); ++k) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }
  (*this) = std::move(result);
}

S21Matrix S21Matrix::Transpose() const noexcept {
  S21Matrix transpose_matrix(cols_, rows_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; j++) {
      transpose_matrix(j, i) = (*this)(i, j);
    }
  }
  return transpose_matrix;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::logic_error("Rows and columns are not equal");
  }

  double determinant = 0;
  if (rows_ == 0) {
    determinant = 1;
  } else if (rows_ == 1) {
    return (*this)(0, 0);
  } else if (rows_ == 2) {
    return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  } else {
    int k = 1;
    for (int i = 0; i < rows_; ++i, k = -k) {
      S21Matrix tmp = (*this).MatrixReduction(i);
      determinant += (k * (*this)(0, i) * tmp.Determinant());
    }
  }
  return determinant;
}

S21Matrix S21Matrix::MatrixReduction(int column) const {
  S21Matrix tmp(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_ - 1; i++) {
    int offsetrow = 1, offsetcolumn = 0;
    for (int j = 0; j < rows_ - 1; j++) {
      if (j == column) offsetcolumn = 1;
      tmp(i, j) = (*this)(i + offsetrow, j + offsetcolumn);
    }
  }
  return tmp;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::logic_error("Rows and columns are not equal");
  }

  S21Matrix result(rows_, cols_);
  for (int k = 0; k < rows_; k++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minors = (*this).MinorMatrix(k, j);
      double determinant = minors.Determinant();
      result(k, j) = determinant * std::pow(-1.0, (k + j));
    }
  }
  return result;
}

S21Matrix S21Matrix::MinorMatrix(int row, int column) const {
  int x = 0, y = 0;
  S21Matrix minor(rows_ - 1, cols_ - 1);
  for (int i = 0; i < rows_; i++) {
    if (row == i) continue;
    for (int j = 0; j < rows_; j++) {
      if (column == j) continue;
      minor(x, y) = (*this)(i, j);
      y++;
    }
    x++;
    y = 0;
  }
  return minor;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double determinant = (*this).Determinant();
  if (determinant == 0.0) {
    throw std::logic_error(
        "Unable to calculate inverse matrix, determinant is zero");
  }
  S21Matrix result(rows_, cols_), minor_matrix = (*this).CalcComplements();
  S21Matrix transpose_matrix = minor_matrix.Transpose();
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = transpose_matrix(i, j) / determinant;
    }
  }
  return result;
}
/* Перегрузка оператора сложения
Просто вызываем функцию сложения матриц*/

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);
  return tmp;
}

/* Перегрузка опертора += */

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  (*this).SumMatrix(other);
  return *this;
}

/* Перегрузка оператора - */

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);
  return tmp;
}

/* Перегрузка оператора -= */

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  (*this).SubMatrix(other);
  return (*this);
}

/* Перегрузка оператора * умножение матриц */

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix tmp(*this);
  tmp.MulMatrix(other);
  return tmp;
}

/* Перегрузка оператора * умножение на число */

S21Matrix S21Matrix::operator*(const double num) const {
  S21Matrix tmp(*this);
  tmp.MulNumber(num);
  return tmp;
}

/* Перегрузка оператора *= умножение на число */

S21Matrix& S21Matrix::operator*=(const double num) {
  (*this).MulNumber(num);
  return (*this);
}

/* Перегрузка оператора *= умножение матриц */

S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  (*this).MulMatrix(other);
  return (*this);
}

/* Перегрузка оператор сравнения */

bool S21Matrix::operator==(const S21Matrix& other) const {
  return (*this).EqMatrix(other);
}
