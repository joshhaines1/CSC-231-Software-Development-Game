add_library(events
  updatefov.cpp
        hit.cpp
        hit.h
        die.cpp
        die.h
        thrust.cpp
        thrust.h
        raise.cpp
        raise.h
        swing.cpp
        swing.h
)

target_include_directories(events PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(events PUBLIC engine)
