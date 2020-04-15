#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
/* #pragma GCC diagnostic ignored "-Wunused-lambda-capture" */
#pragma GCC diagnostic ignored "-Wunused-const-variable"
#pragma GCC diagnostic ignored "-Wunused-variable"
// helper, to print in cpp
auto c_txt(auto f) {
  return f([](auto x) { return x; })('I');
}

auto c_bool(auto f) {
  // return f (1)(0);
  return f("True")("False");
}
//////////////////
auto M = [](auto f) { // Mockingbird M = λf.ff
  return [f](auto x) { return f(f(x)); };
};

auto I = [](auto x) { return x; }; // Identidy I= λx.x

auto K = [](auto p) { // Kestrel K = λpq.p
  return [p](auto q) { return p; };
};

auto KI = [](auto p) { // Kite KI = λpq.q
  return [](auto q) { return q; };
};

auto KI_ = [](auto x) { // another KI
  return K(I)(x);
};

auto C = [](auto f) { // Cardinal C = λfab.fba
  return [f](auto a) {
    return [f, a](auto b) { return f(b)(a); };
  };
};

constexpr auto T = K;
constexpr auto F = KI;

// #pragma GCC diagnostic pop

using namespace std;
int main() {
  auto K42 = K(42);

  cout << c_txt(M(I)) << '\n';   // 'I'
  cout << c_txt(I(I)) << "\n\n"; // 'I'

  cout << K(1)(2) << '\n';     // 1
  cout << K42(11233) << "\n";  // 42
  cout << KI(1)(2) << '\n';    // 2
  cout << KI_(1)(2) << "\n\n"; // 2

  cout << c_bool(T) << '\n';   // "True"
  cout << c_bool(F) << "\n\n"; // "False"

  cout << c_bool(F(F)(T)) << '\n';    // True
  cout << c_bool(C(F)(F)(T)) << '\n'; // False
}
