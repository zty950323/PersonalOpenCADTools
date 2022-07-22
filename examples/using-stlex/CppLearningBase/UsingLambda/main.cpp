
///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("UsingSTLEx")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <list>
#include <vector>

using std::abs;
using std::cerr;
using std::cout;
using std::endl;
using std::find_if;
using std::for_each;
using std::function;
using std::list;
using std::out_of_range;
using std::sort;
using std::vector;

namespace {

void useDecltypeInLambda() {
  cout << "Using decltype in lambda:" << endl;
  // this is a funny code for use lambda.
  size_t i = 10;
  auto ii = i;
  auto itest = [&ii]() {
    for (decltype(ii) j = 0; j < ii; j++) {
      cout << "1" << '\t';
    }
  };
  itest();
  cout << endl;
}

void absSort(float* x, unsigned n) {
  sort(x, x + n,
       // Lambda expression begins
       [](float a, float b) {
         return (abs(a) < abs(b));
       }  // end of lambda expression
  );
}

void useAbsSort() {
  cout << "Using abs sort by using lambda:" << endl;
  float fArray[10] = {0.0f};
  short t = 1;
  cout << "\nInit the float array:" << endl;
  for (size_t i = 0; i < 10; ++i) {
    float r = i * 3.0f * t;
    fArray[i] = r;
    cout << "\t" << fArray[i];
    t = -t;
  }
  cout << "\nFinished Init." << endl;
  float* f = fArray;
  absSort(f, 10);
  cout << "After abs sort:" << endl;
  for (size_t i = 0; i < 10; ++i) {
    cout << "\t" << fArray[i];
  }
  cout << "\nAbs Finish!" << endl;
  sort(f, f + 10);
  cout << "After default sort:" << endl;
  for (size_t i = 0; i < 10; ++i) {
    cout << "\t" << fArray[i];
  }
  cout << "\nDefault Finish!" << endl;
}

template <class... Args>
void useTemplatefunc(Args... args) {
  auto x = [args...] { return g(args...); };
  x();
}

void useFunctionLambda() {
  cout << "Using Lambda expression by std::function." << endl;
  // Assign the lambda expression that adds two numbers to an auto variable.
  auto f1 = [](int x, int y) { return x + y; };
  cout << f1(2, 3) << endl;
  // Assign the same lambda expression to a function object.
  function<int(int, int)> f2 = [](int x, int y) { return x + y; };
  cout << f2(3, 4) << endl;
}

void useRefAndValueLambda() {
  cout << "Using Lambda expression by reference and value." << endl;
  int i = 3;
  int j = 5;

  // The following lamda expression captures i by value and j by reference.
  function<int(void)> f = [i, &j] { return i + j; };

  // Change the values of i and j.
  i = 22;
  j = 44;

  // Call f and print its result.
  cout << f() << endl;
  // the result will be i(3) + j(44) = 47, because the i pass by value and j
  // pass by reference.
}

void useLambdaDirectly() {
  cout << "Using Lambda expression directly." << endl;
  int n = [](int x, int y) { return x + y; }(5, 4);
  cout << n << endl;
}

void useLambdaInFindIf() {
  cout << "Using Lambda expression in std funcion find_if:" << endl;
  // Create a list of intergers with a few initial elements.
  list<int> numbers;
  numbers.push_back(13);
  numbers.push_back(17);
  numbers.push_back(42);
  numbers.push_back(46);
  numbers.push_back(99);
  numbers.push_back(-11);
  numbers.push_back(-22);
  numbers.push_back(-33);

  // Use the find_if function and a lambda expression to find the first even
  // number in the list.
  const list<int>::const_iterator result = find_if(
      numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });

  // To print the result:
  if (result != numbers.end()) {
    cout << "The first even number in the list is " << *result << "." << endl;
  } else {
    cout << "The list contains no even numbers." << endl;
  }
  cout << endl;
}

void useNestingLambdaExpression() {
  cout << "Using nesting Lambda expression :" << endl;
  // The following lamda expression contains a nested lamda expression.
  int timestwoplusthree = [](int x) {
    return [](int y) { return y * 2; }(x) + 3;
  }(5);
  // [](int y) { return y * 2; } is the nested lambda expression.

  // Print the result.
  cout << timestwoplusthree << endl;
}

void useHighOrderLambdaFunctions() {
  cout << "Using higher order Lambda expression :" << endl;
  // The following code declares a lambda expression that returns
  // another lambda expression that adds two numbers.
  // The returned lambda expression captures parameter x by value.
  auto addTwoIntegers = [](int x) -> function<int(int)> {
    return [=](int y) { return x + y; };
  };

  // The following code declares a lambda expression that takes another
  // lambda expression as its argument.
  // The lambda expression applies the argument z to the function f and
  // multiplies by 2.
  auto higherOrder = [](const function<int(int)>& f, int z) {
    return f(z) * 2;
  };

  // Call the lambda expression that is bound to higherorder.
  auto answer = higherOrder(addTwoIntegers(7), 8);

  // Print the result, which is (7+8)*2.
  cout << answer << endl;
}

class Scale {
 public:
  // The constructor
  explicit Scale(int scale) : m_scale(scale) {}

  // Prints the product of each element in a vector object and the scale value
  // to the console.
  void applyScale(const vector<int>& v) const {
    // capture the this pointer implicitly.
    for_each(v.begin(), v.end(), [=](int n) { cout << n * m_scale << '\t'; });
  }

  // capture "this" by reference.
  void applyScale_ref(const vector<int>& v) const {
    for_each(v.begin(), v.end(),
             [this](int n) { cout << n * m_scale << '\t'; });
  }

  // capture "this" by value (since /stdc++17).
  void applyScale_value(const vector<int>& v) const {
    for_each(v.begin(), v.end(),
             [*this](int n) { cout << n * m_scale << '\t'; });
  }

 private:
  int m_scale;
};

template <typename T>
void printVec(const vector<T>& vec) {
  decltype(vec.size()) len = vec.size();
  for (decltype(len) i = 0; i < len; ++i) {
    cout << vec.at(i) << '\t';
  }
  cout << endl;
}

void useLambdaInFunction() {
  cout << "Using Lambda expression in function :" << endl;
  vector<int> values;
  for (int i = 0; i < 10; ++i) {
    values.push_back(i);
  }

  // print values before using.
  cout << "Before deal with values:" << endl;
  printVec<int>(values);
  cout << "End values." << endl;

  // Create a scale object that scales elements by 3 and apply it to the vector
  // object. Does not modify the vector.
  Scale s(3);
  s.applyScale(values);
  cout << endl;
  cout << "After scale values:" << endl;
  printVec<int>(values);
  cout << "End values scale." << endl;

  Scale s1(4);
  s1.applyScale_ref(values);
  cout << endl;
  cout << "After scale values by lambda ref:" << endl;
  printVec<int>(values);
  cout << "End values scale by lambda ref." << endl;

  Scale s2(2);
  s2.applyScale_value(values);
  cout << endl;
  cout << "After scale values by lambda value:" << endl;
  printVec<int>(values);
  cout << "End values scale by lambda value." << endl;
}

// Negates each element int the vector object. Assumes signed data type.
template <typename T>
void negate_all(vector<T>& v) {
  for_each(v.begin(), v.end(), [](T& n) { n = -n; });
}

// Prints to the console each element in the vector object.
template <typename T>
void print_all(const vector<T>& v) {
  for_each(v.begin(), v.end(), [](const T& n) { cout << n << endl; });
}

void useLambdaInTemplate() {
  // Create a vector of signed integers with few elements.
  vector<int> v;
  v.push_back(34);
  v.push_back(-43);
  v.push_back(56);
  v.push_back(33);

  print_all(v);
  negate_all(v);
  cout << "After negate_all()" << endl;
  print_all(v);
}

void useLambdaInExpection() {
  // Create a vector that contain 3 elements.
  vector<int> elements(3);

  // Create another vector that contains index values.
  vector<int> indices(3);
  indices[0] = 0;
  indices[1] = -1;
  // This is not a valid subscript. It will trigger an exception.
  indices[2] = 2;

  // Use the values from the vector of index values to
  // fill the elements vector. This example uses a
  // try/catch block to handle invalid access to the
  // elements vector.
  try {
    for_each(indices.begin(), indices.end(),
             [&](int index) { elements.at(index) = index; });
  } catch (const out_of_range& e) {
    cerr << "Caught '" << e.what() << "'." << endl;
  };
}

}  // namespace

int main() {
  useDecltypeInLambda();
  useAbsSort();
  useFunctionLambda();
  useRefAndValueLambda();
  useLambdaDirectly();
  useLambdaInFindIf();
  useNestingLambdaExpression();
  useHighOrderLambdaFunctions();
  useLambdaInFunction();
  useLambdaInTemplate();
  useLambdaInExpection();
  system("pause");
  return 0;
}
