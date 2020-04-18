cmake_minimum_required(VERSION 3.10)
project(OdroidGPIO
        VERSION 0.0.1
        DESCRIPTION "Odroid Port of Adafruit Unified Sensor Library"
        LANGUAGES CXX C)

include(cmake/Setup.cmake)

#add_library(odroidgpio
        #SHARED
        #BasePin.cpp
        #Database.cpp
        #gpio.cpp

        #digital/Pin.cpp
        #digital/digital.cpp
        #pwm/Pin.cpp
        #pwm/pwm.cpp
        #serial/Port.cpp
        #serial/serial.cpp
        #I2C/Device.cpp
        #I2C/I2C.cpp)

#target_link_libraries(odroidgpio
        #PUBLIC wiringPi
        #Threads::Threads rt crypt)

#target_include_directories(odroidgpio
        #PUBLIC
        #$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        #$<INSTALL_INTERFACE:include/OdroidGPIO>
        #PRIVATE
        #${CMAKE_CURRENT_SOURCE_DIR}/include)

#install(TARGETS odroidgpio
        #EXPORT OdroidGPIOTargets
        #RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
        #LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT shlib
        #PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}"
        #COMPONENT dev)


#add_subdirectory(examples)

# Add all targets to the build-tree export set
export(TARGETS odroidgpio FILE "${PROJECT_BINARY_DIR}/OdroidGPIOTargets.cmake")

# Export the package for use from the build-tree
# (this registers the build-tree with a global CMake-registry)
export(PACKAGE OdroidGPIO)

# Create the OdroidGPIOConfig.cmake and OdroidGPIOConfigVersion.cmake files
file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}" "${INSTALL_INCLUDE_DIR}")
# ... for the build tree
set(CONF_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}" "${PROJECT_BINARY_DIR}")
configure_file(cmake/OdroidGPIOConfig.cmake.in "${PROJECT_BINARY_DIR}/OdroidGPIOConfig.cmake" @ONLY)
# ... for the install tree
set(CONF_INCLUDE_DIRS "\${ODROIDGPIO_CMAKE_DIR}/${REL_INCLUDE_DIR}")
configure_file(cmake/OdroidGPIOConfig.cmake.in "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/OdroidGPIOConfig.cmake" @ONLY)
# ... for both
configure_file(cmake/OdroidGPIOConfigVersion.cmake.in "${PROJECT_BINARY_DIR}/OdroidGPIOConfigVersion.cmake" @ONLY)

# Install the OdroidGPIOConfig.cmake and OdroidGPIOConfigVersion.cmake
install(FILES
        "${PROJECT_BINARY_DIR}/${CMAKE_FILES_DIRECTORY}/OdroidGPIOConfig.cmake"
        "${PROJECT_BINARY_DIR}/OdroidGPIOConfigVersion.cmake"
        DESTINATION
        "${INSTALL_CMAKE_DIR}" COMPONENT dev)

install(DIRECTORY include/ DESTINATION ${INSTALL_INCLUDE_DIR})

# Install the export set for use with the install-tree
install(EXPORT OdroidGPIOTargets
        DESTINATION "${INSTALL_CMAKE_DIR}"
        COMPONENT dev)
