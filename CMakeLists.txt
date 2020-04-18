cmake_minimum_required(VERSION 3.10)
project(OdroidAdafruitSensor
        VERSION 0.0.1
        DESCRIPTION "Odroid Port of Adafruit Unified Sensor Library"
        LANGUAGES CXX C)

include(cmake/Setup.cmake)

add_library(OdroidAdafruitSensor
        SHARED
        src/Adafruit_Sensor.cpp)

target_include_directories(OdroidAdafruitSensor
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include/OdroidAdafruitSensor>)

install(TARGETS OdroidAdafruitSensor
        EXPORT OdroidAdafruitSensorTargets
        RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
        PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}"
        COMPONENT dev)

#add_subdirectory(examples)

# Add all targets to the build-tree export set
export(TARGETS OdroidAdafruitSensor FILE "${PROJECT_BINARY_DIR}/OdroidAdafruitSensorTargets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE OdroidAdafruitSensor)

# Create the OdroidAdafruitSensorConfig.cmake and OdroidAdafruitSensorConfigVersion.cmake files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(cmake/OdroidAdafruitSensorConfig.cmake.in "${PROJECT_BINARY_DIR}/OdroidAdafruitSensorConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${ODROIDADAFRUITSENSOR_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(cmake/OdroidAdafruitSensorConfig.cmake.in "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/OdroidAdafruitSensorConfig.cmake" @ONLY)
# ... for both
configure_file(cmake/OdroidAdafruitSensorConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/OdroidAdafruitSensorConfigVersion.cmake" @ONLY)

# Install the OdroidAdafruitSensorConfig.cmake and OdroidAdafruitSensorConfigVersion.cmake
install(FILES
        "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/OdroidAdafruitSensorConfig.cmake"
        "${PROJECT_BINARY_DIR}/OdroidAdafruitSensorConfigVersion.cmake"
        DESTINATION
        "${INSTALL_CMAKE_DIR}" COMPONENT dev)

install(DIRECTORY include/ DESTINATION ${INSTALL_INCLUDE_DIR})

# Install the export set for use with the install-tree
install(EXPORT OdroidAdafruitSensorTargets
        DESTINATION "${INSTALL_CMAKE_DIR}"
        COMPONENT dev)
