#pragma once

namespace lib {

template <typename T> struct identity { using type = T; };

template <bool Cond, typename TrueType, typename FalseType>
struct IfThenElse : identity<TrueType> {};

template <typename TrueType, typename FalseType>
struct IfThenElse<false, TrueType, FalseType> : identity<FalseType> {};

} // namespace lib