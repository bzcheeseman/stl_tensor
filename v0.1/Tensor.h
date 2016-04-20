//
// Created by Aman LaChapelle on 4/18/16.
//

#include <vector>

#ifndef STL_MATRIX_MATRIX_H
#define STL_MATRIX_MATRIX_H

template<typename T>
struct Tensor{

  struct _base {
    std::vector< std::vector<T>* > base;

    std::vector<T>& operator[](std::size_t index) {
      if (index+1 > base.size()){
        for (int i = 0; i <= index; i++){
          base.push_back(new std::vector<T>);
        }
      }
      return *(base[index]);
    }
  };

  _base base;

  std::vector<T>& operator[](std::size_t i) {
    return base[i];
  }

  virtual T& operator()(std::size_t i, std::size_t j) {
    if (j+1 > base[i].size()){
      for (int k = 0; k <= j; k++){
        base[i].push_back(T(0));
      }
    }
    return base[i][j];
  }

  Tensor& insert(std::size_t i, std::size_t j, T item){
    (*this)(i,j) = item;
    return static_cast<Tensor&>(*this);
  }
};

template<typename T>
struct Tensor3 : public Tensor<T> {

  struct _base {
    std::vector< Tensor<T>* > base;

    Tensor<T>& operator[](std::size_t index) {
      if (index+1 > base.size()){
        for (int i = 0; i <= index; i++){
          base.push_back(new Tensor<T>);
        }
      }
      return *(base[index]);
    }
  };

  _base base;

  Tensor<T>& operator[](std::size_t i){
    return base[i];
  }

  T& operator()(std::size_t i, std::size_t j, std::size_t k) {
    if (k+1 > base[i][j].size()) {
      for (int l = 0; l <= k; l++){
        base[i][j].push_back(T(0));
      }
    }
    return base[i][j][k];
  }
};

#endif //STL_MATRIX_MATRIX_H
