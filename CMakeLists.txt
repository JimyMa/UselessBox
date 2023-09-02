project(RS_Decoder C CXX)

include_directories(${PROJECT_SOURCE_DIR})


file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/csrc/decode/*.cpp
    ${PROJECT_SOURCE_DIR}/csrc/GF256/*.cpp
)

add_library(rs_decoder SHARED ${SOURCES})


# pybind11
find_package(PythonLibs 3 REQUIRED)
set(Python3_INCLUDE_DIRS ${PYTHON_INCLUDE_DIRS})
set(Python3_LIBRARIES ${PYTHON_LIBRARIES})
include_directories(${Python3_INCLUDE_DIRS})

set(PYBIND_PATH ${PROJECT_SOURCE_DIR}/thirdparty/pybind11)
add_subdirectory(${PYBIND_PATH})
include_directories(${PYBIND_PATH}/include)

file(GLOB CPP2PY_SRC
    csrc/cpp2py/*.cpp
)
add_library(rs_decoder_py SHARED ${CPP2PY_SRC})
set_target_properties(rs_decoder_py PROPERTIES PREFIX "${PYTHON_MODULE_PREFIX}"
                                       SUFFIX "${PYTHON_MODULE_EXTENSION}")
target_link_libraries(rs_decoder_py rs_decoder)

