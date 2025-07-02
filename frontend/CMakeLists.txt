include_directories(
    ${PROJECT_SOURCE_DIR}/login
    ${PROJECT_SOURCE_DIR}/register
    ${PROJECT_SOURCE_DIR}/Home
    ${PROJECT_SOURCE_DIR}/Fetch
    ${PROJECT_SOURCE_DIR}/Activity
)
cmake_minimum_required(VERSION 3.16)
project(BugTracking)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "/Users/arnav/Qt/6.9.0/macos")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network Gui)

add_executable(BugTracking
    login/login.cpp
    login/login_window.h
    login/login.ui

    register/main.cpp
    register/registration.cpp
    register/registration_window.h
    register/registration.ui

    Home/home.cpp
    Home/createbug.ui
    Home/home_window.h

    Senior_developer/dialogue.ui
    Senior_developer/s_developer.cpp
    Senior_developer/s_developer.h
    Senior_developer/s_developer.ui

    Senior_Tester/assign_dialogue.ui
    Senior_Tester/feature_dialogue.ui
    Senior_Tester/s_tester.cpp
    Senior_Tester/s_tester.ui
    Senior_Tester/s_tester.h
)

target_link_libraries(
    BugTracking
    Qt6::Core 
    Qt6::Widgets 
    Qt6::Network
    Qt6::Gui
    )

# Set macOS .icns app icon
set(MACOSX_BUNDLE_ICON_FILE Bug.icns)
set_source_files_properties(../icons/Bug.icns PROPERTIES MACOSX_PACKAGE_LOCATION "Resources")
target_sources(BugTracking PRIVATE ../icons/Bug.icns)

# Ensure app is bundled on macOS
set_target_properties(BugTracking PROPERTIES
    MACOSX_BUNDLE TRUE
)