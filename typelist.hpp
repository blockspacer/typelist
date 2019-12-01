#pragma once

#include <type_traits>

#include "if_then_else.hpp"

namespace lib {

// ----------------------------------------------

template <typename...>
struct typelist {};

// ----------------------------------------------

template <typename TypeList>
struct is_empty : public std::false_type {};

template <>
struct is_empty<typelist<>> : public std::true_type {};

// ----------------------------------------------

template <typename TypeList>
struct front;

template <typename Head, typename... Tail>
struct front<typelist<Head, Tail...>> {
  using type = Head;
};

template <typename TypeList>
using front_t = typename front<TypeList>::type;

// ----------------------------------------------

template <typename PushType, typename TypeList>
struct push_front;

template <typename PushType, typename... Types>
struct push_front<PushType, typelist<Types...>> {
  using type = typelist<PushType, Types...>;
};

template <typename PushType, typename TypeList>
using push_front_t = typename push_front<PushType, TypeList>::type;

// ----------------------------------------------

template <typename PushType, typename TypeList>
struct push_back;

template <typename PushType, typename... Types>
struct push_back<PushType, typelist<Types...>> {
  using type = typelist<Types..., PushType>;
};

template <typename PushType, typename TypeList>
using push_back_t = typename push_back<PushType, TypeList>::type;

// ----------------------------------------------

template <typename TypeList>
struct pop_front;

template <typename Head, typename... Tail>
struct pop_front<typelist<Head, Tail...>> {
  using type = typelist<Tail...>;
};

template <typename TypeList>
using pop_front_t = typename pop_front<TypeList>::type;

// ----------------------------------------------

template <typename TypeList>
struct pop_back;

template <typename TypeList>
using pop_back_t = typename pop_back<TypeList>::type;

template <typename TypeList>
struct pop_back
    : push_front<front_t<TypeList>, pop_back_t<pop_front_t<TypeList>>> {};

template <typename SingleType>
struct pop_back<typelist<SingleType>> {
  using type = typelist<>;
};

// ----------------------------------------------

template <size_t N, typename TypeList>
struct nth_element : public nth_element<N - 1, pop_front_t<TypeList>> {};

template <typename TypeList>
struct nth_element<0, TypeList> {
  using type = front_t<TypeList>;
};

template <size_t N, typename TypeList>
using nth_element_t = typename nth_element<N, TypeList>::type;

// ----------------------------------------------

template <typename TypeList>
struct largest_type;

template <typename Head, typename... Tail>
struct largest_type<typelist<Head, Tail...>> {
 private:
  using SubLargestType = typename largest_type<typelist<Tail...>>::type;

 public:
  using type = typename IfThenElse<(sizeof(Head) > sizeof(SubLargestType)),
                                   Head, SubLargestType>::type;
};

template <typename Head>
struct largest_type<typelist<Head>> {
  using type = Head;
};

template <typename TypeList>
using largest_type_t = typename largest_type<TypeList>::type;

// ----------------------------------------------

template <typename TypeList, bool is_empty = is_empty<TypeList>::value>
struct reverse;

template <typename TypeList>
using reverse_t = typename reverse<TypeList>::type;

template <typename TypeList>
struct reverse<TypeList, false>
    : push_back<front_t<TypeList>, reverse_t<pop_front_t<TypeList>>> {};

template <typename TypeList>
struct reverse<TypeList, true> {
  using type = TypeList;
};

// ----------------------------------------------

template <typename List, template <typename, typename> class F, typename I,
          bool = is_empty<List>::value>
struct accumulate;

template <typename List, template <typename, typename> class F, typename I>
struct accumulate<List, F, I, false>
    : public accumulate<pop_front_t<List>, F,
                        typename F<front_t<List>, I>::type> {};

template <typename List, template <typename, typename> class F, typename I>
struct accumulate<List, F, I, true> {
  using type = I;
};

template <typename List, template <typename, typename> class F, typename I>
using accumulate_t = typename accumulate<List, F, I>::type;

// ----------------------------------------------

template <typename TypeList, template <typename> class MetaFun,
          bool = is_empty<TypeList>::value>
struct transform;

template <typename TypeList, template <typename> class MetaFun>
struct transform<TypeList, MetaFun, false>
    : push_front<typename MetaFun<front_t<TypeList>>::type,
                 typename transform<pop_front_t<TypeList>, MetaFun>::type> {};

template <typename TypeList, template <typename> class Metafun>
struct transform<TypeList, Metafun, true> {
  using type = TypeList;
};

template <typename TypeList, template <typename> class MetaFun>
using transform_t = typename transform<TypeList, MetaFun>::type;


}  // namespace lib
