cmake_minimum_required(VERSION 3.10)
project(luci_interpreter_micro_standalone)

include(${NNAS_ROOT}/infra/onert-micro/utils.cmake)

nnas_find_package(FlatBuffersSource EXACT 2.0 QUIET)
include_directories(${FlatBuffersSource_DIR}/include)

# TODO: fix luci/plan for new luci-micro without luci/IR
add_subdirectory(${NNAS_PROJECT_SOURCE_DIR}/onert-micro/luci-interpreter ${CMAKE_CURRENT_BINARY_DIR}/luci-interpreter)
