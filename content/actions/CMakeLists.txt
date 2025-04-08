add_library(actions
        rest.h
        rest.cpp
        move.cpp
        move.h
        closedoor.cpp
        closedoor.h
        opendoor.cpp
        opendoor.h
        wander.cpp
        wander.h
)

target_include_directories(actions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(actions PUBLIC engine events)
