cmake_minimum_required(VERSION 3.5)

project(CookingApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
        main.cpp
        qt/MainWindow.cpp
        qt/MainWindow.h
        qt/MainWindow.ui
        resources.qrc
        recipe/Ingredient.cpp
        recipe/Measure.cpp
        recipe/Recipe.cpp
        scrapper/Scrapper.cpp
        qt/recipe/RecipeCard.cpp
        qt/recipe/RecipeCard.h
        qt/widgets/QClickableImage.h
        qt/widgets/QClickableImage.cpp
        qt/tools/FileDownloader.h
        qt/tools/FileDownloader.cpp
        qt/recipe/RecipeGrid.cpp
        qt/recipe/RecipeGrid.h
        qt/tools/Tools.cpp
        qt/tools/Tools.h
        qt/dialogs/SearchDialog.cpp
        qt/dialogs/SearchDialog.h
        qt/recipe/RecipeDetails.cpp
        qt/recipe/RecipeDetails.h
        qt/dialogs/IngredientsDialog.cpp
        qt/dialogs/IngredientsDialog.h
        qt/widgets/QIconLabel.cpp
        qt/widgets/QIconLabel.h
        recipe/RecipeFavourite.cpp
        recipe/RecipeFavourite.h recipe/Instruction.cpp recipe/Instruction.h)

qt_add_executable(CookingApp
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(CookingApp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Network)

set_target_properties(CookingApp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS CookingApp
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(CookingApp)
endif()
