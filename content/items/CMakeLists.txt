add_library(items
        bite.h
        bite.cpp
        potion.cpp
        potion.h
        staff_red.cpp
        staff_red.h
        knife.cpp
        knife.h
        chest.cpp
        chest.h
        axe.cpp
        axe.h
        shapeshift_potion.cpp
        shapeshift_potion.h
        teleport_potion.cpp
        teleport_potion.h
)

target_include_directories(items PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(items PUBLIC engine events)
