find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

add_library(graphics
  graphics.cpp
  sprite.cpp
  animatedsprite.cpp
)

target_include_directories(graphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(graphics PUBLIC util SDL2::SDL2 SDL2_image::SDL2_image)
