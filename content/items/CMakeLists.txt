add_library(items
        bite.h
        bite.cpp
        potion.cpp
        potion.h
        staff_red.cpp
        staff_red.h
        knife.cpp
        knife.h
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
