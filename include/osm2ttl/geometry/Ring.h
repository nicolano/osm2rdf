// Copyright 2020, University of Freiburg
// Authors: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

// This file is part of osm2ttl.
//
// osm2ttl is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// osm2ttl is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with osm2ttl.  If not, see <https://www.gnu.org/licenses/>.

#ifndef OSM2TTL_GEOMETRY_RING_H_
#define OSM2TTL_GEOMETRY_RING_H_

#include "boost/geometry/geometries/geometries.hpp"
#include "boost/serialization/nvp.hpp"
#include "boost/serialization/vector.hpp"
#include "osm2ttl/geometry/Location.h"

namespace osm2ttl::geometry {
typedef boost::geometry::model::ring<osm2ttl::geometry::Location> Ring;
}  // namespace osm2ttl::geometry

inline bool operator==(const osm2ttl::geometry::Ring& lhs,
                       const osm2ttl::geometry::Ring& rhs) noexcept {
  if (lhs.size() != rhs.size()) {
    return false;
  }
  for (size_t i = 0; i < lhs.size(); ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

inline bool operator!=(const osm2ttl::geometry::Ring& lhs,
                       const osm2ttl::geometry::Ring& rhs) noexcept {
  return !(lhs == rhs);
}

namespace boost::serialization {
template <class Archive>
void serialize(Archive& ar, osm2ttl::geometry::Ring& m,
               [[maybe_unused]] const unsigned int version) {
  ar& boost::serialization::make_nvp(
      "locations", static_cast<std::vector<osm2ttl::geometry::Location>&>(m));
}
}  // namespace boost::serialization

#endif  // OSM2TTL_GEOMETRY_POLYGON_H_
