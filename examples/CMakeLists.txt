cmake_minimum_required(VERSION 3.8.2)

project(examples)

# Inherit common definitions and dependencies
include(../cmake/CMakeInclude.txt)

if(NOT TARGET utils_lib)
	find_package(utils_lib CONFIG REQUIRED)
	message(">> Found Package: utils_lib")
endif()

link_libraries(utils_lib)

add_executable("cin"                   "src/core/io/input/cin.cpp")
add_executable("cin+getline"           "src/core/io/input/cin+getline.cpp")
add_executable("fscanf"                "src/core/io/input/fscanf.cpp")
add_executable("fscanf+fgets"          "src/core/io/input/fscanf+fgets.cpp")

add_executable("cout"                  "src/core/io/output/cout.cpp")
add_executable("fprintf"               "src/core/io/output/fprintf.cpp")
add_executable("type-limits"           "src/core/io/output/type-limits.cpp")

add_executable("iterate-string"        "src/core/iterate-string.cpp")
add_executable("iterate-vector"        "src/core/iterate-vector.cpp")
add_executable("reverse-struct"        "src/core/reverse-struct.cpp")

add_executable("iterator-1"            "src/core/iterator-1/Algorithm.cpp" "src/core/iterator-1/AlgorithmIterator.cpp" "src/core/iterator-1/main.cpp")
add_executable("iterator-2"            "src/core/iterator-2/Algorithm.cpp" "src/core/iterator-2/AlgorithmIterator.cpp" "src/core/iterator-2/main.cpp")
add_executable("iterator-3"            "src/core/iterator-1/Algorithm.cpp" "src/core/iterator-1/AlgorithmIterator.cpp" "src/core/iterator-3/main.cpp")

add_executable("node-graph"            "src/node/graph/Node.cpp" "src/node/graph/Edge.cpp" "src/node/graph/Dijkstra.cpp" "src/node/graph/main.cpp")

add_executable("object"                "src/utils/object.cpp")
add_executable("string-split"          "src/utils/string-split.cpp")
add_executable("string-trim"           "src/utils/string-trim.cpp")

add_executable("Array"                 "src/various/Array.cpp")
add_executable("Dijkstra"              "src/various/Dijkstra.cpp")
add_executable("Pack"                  "src/various/Pack.cpp")
add_executable("PassReturn"            "src/various/PassReturn.cpp")
add_executable("ReturnCopyMove"        "src/various/ReturnCopyMove.cpp")
add_executable("TreeNode"              "src/various/TreeNode.cpp")
