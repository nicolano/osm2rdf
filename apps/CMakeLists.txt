# Copyright 2020, University of Freiburg
# Authors: Axel Lehmann <lehmann@cs.uni-freiburg.de>.

# This file is part of osm2rdf.
#
# osm2rdf is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# osm2rdf is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with osm2rdf.  If not, see <https://www.gnu.org/licenses/>.

add_executable(osm2rdf osm2rdf.cpp)
target_link_libraries(osm2rdf PRIVATE osm2rdf_library spatialjoin-dev pb_util)

add_executable(osm2rdf-stats osm2rdf-stats.cpp)
target_link_libraries(osm2rdf-stats PRIVATE osm2rdf_library spatialjoin-dev pb_util)

if (IPO_SUPPORTED)
    message(STATUS "IPO / LTO enabled")
    set_property(TARGET osm2rdf PROPERTY INTERPROCEDURAL_OPTIMIZATION TRUE)
else ()
    message(STATUS "IPO / LTO not supported: <${error}>")
endif ()
