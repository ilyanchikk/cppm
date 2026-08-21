find_package(Qt6 REQUIRED COMPONENTS Core Sql)

add_library(BD STATIC
    dbManager.h
    dbManager.cpp
)

target_link_libraries(BD Qt6::Core Qt6::Sql)


target_include_directories(BD PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
