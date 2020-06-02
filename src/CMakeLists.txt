# задаем набор исходников
set(SOURCES
sudoku_slr.h
sudoku_slr.cpp
)

# создаем статическую библиотеку
add_library(sudoku_slr_lib ${SOURCES})

# добавлем путь к исходникам для возожности подключения библиотеки
target_include_directories(sudoku_slr_lib PUBLIC ${SRC_ROOT_DIR})

# группируем исходники по типу по категориям
source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${SOURCES})

# В solution эта библиотека лежит в simple_project
set_property(TARGET sudoku_slr_lib PROPERTY FOLDER "sudoku_solver")

# включаем в сборку проекnа подпроект с тестами
add_subdirectory(tests)