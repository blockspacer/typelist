#include <atomic>
#include <chrono>
#include <exception>
#include <functional>
#include <future>
#include <iostream>
#include <iterator>
#include <map>
#include <optional>
#include <regex>
#include <set>
#include <string>
#include <thread>
#include <tuple>
#include <unordered_map>
#include <variant>

#include "typelist.hpp"

using std::cout;
using std::endl;

template <typename T>
struct AddConst {
  using type = const T;
};

int main() {
  using list = lib::typelist<int, double, std::string>;
  using list2 = lib::push_front_t<char, list>;
  lib::nth_element_t<1, list2> var;

  lib::largest_type_t<list2> var2;
  // var2 = "3232";
  std::cout << std::is_same_v<std::string, decltype(var2)> << std::endl;
  using list3 = typename lib::reverse<list2>::type;

  using list_accum = lib::accumulate_t<list, lib::push_front, lib::typelist<>>;
  lib::nth_element_t<0, list_accum> s = "doksods";
  using pop_back_list = lib::pop_back_t<list2>;
  lib::nth_element_t<2, pop_back_list> dd = 2.3;

  using transformed_list = lib::transform_t<list, AddConst>;
  std::cout << std::is_same_v<lib::nth_element_t<0, transformed_list>,
                              const int> << endl;

  return 0;
}
