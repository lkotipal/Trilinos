// @HEADER
// ***********************************************************************
//
//                           Sacado Package
//                 Copyright (2006) Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// This library is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as
// published by the Free Software Foundation; either version 2.1 of the
// License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301
// USA
// Questions? Contact David M. Gay (dmgay@sandia.gov) or Eric T. Phipps
// (etphipp@sandia.gov).
//
// ***********************************************************************
// @HEADER

#ifndef SACADO_CMATH_HPP
#define SACADO_CMATH_HPP

#include <cmath>        // for most math functions
#include "Sacado_ConfigDefs.h"

namespace Sacado {

  // Replacement for ternary operator, for scalar types that don't implement
  // logical operations that return bool, e.g., a simd scalar type that returns
  // a simd bool.  Sacado overloaded operators use this internally when ever
  // the ternary operator would be used.  It can also be used by client code.
  template <typename Cond, typename T>
  SACADO_INLINE_FUNCTION
  T if_then_else(const Cond cond, const T& a, const T& b) {
    return cond ? a : b;
  }

  // Special version of sqrt(x) that avoids the NaN if x==0 in the derivative.
  // The default implementation just calls the standard sqrt(x).
  template <typename T>
  SACADO_INLINE_FUNCTION
  T safe_sqrt(const T& x) {
    using std::sqrt;
    return sqrt(x);
  }

}

#endif // SACADO_CMATH_HPP
