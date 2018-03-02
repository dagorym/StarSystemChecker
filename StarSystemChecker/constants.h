#include <cmath>

const double PI = std::acos(-1.0);
const double G = 6.67408e-11;


template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}
