cmake_minimum_required( VERSION 3.2 )

project( ui VERSION 0.1.0 LANGUAGES C )
set( CMAKE_C_STANDARD          11 )
set( CMAKE_C_STANDARD_REQUIRED ON )
set( CMAKE_C_EXTENSIONS        OFF )

if( WIN32 )
    set( CMAKE_C_VISIBILITY_PRESET hidden )
    set( CMAKE_VISIBILITY_INLINES_HIDDEN ON )
endif()

enable_testing()

set( LIB_NAME ${PROJECT_NAME} )

# where to look first for modules, before ${CMAKE_ROOT}/Modules/ is checked
set( ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../.. )
set( DEMO_DIR ${ROOT}/demo )
set( INC_DIR ${ROOT}/inc )
set( SRC_DIR ${ROOT}/src )
set( TEST_DIR ${ROOT}/test )

include( CTest )
include( FetchContent )
include( ${CMAKE_CURRENT_SOURCE_DIR}/Custom.cmake )
include( ${CMAKE_CURRENT_SOURCE_DIR}/FileLists.cmake )

################################################################################
# fetch
################################################################################

fetchcontent_declare(
    clingo
    GIT_REPOSITORY "https://github.com/aiq/clingo"
    GIT_TAG "fbcfd1f018cecdb8cab92ab62a2fa2fd050aa4f8"
    SOURCE_SUBDIR "mk/cmake"
)

fetchcontent_makeavailable( clingo )

fetchcontent_declare(
   raylib
   GIT_REPOSITORY https://github.com/raysan5/raylib.git
   GIT_TAG master
)
fetchcontent_makeavailable( raylib )

################################################################################
# build - make
################################################################################
add_library( ${LIB_NAME} SHARED ${SRC_FILES} )
set_default_flags( ${LIB_NAME} )
target_include_directories( ${LIB_NAME} PUBLIC ${INC_DIR} PRIVATE ${SRC_DIR} )
if( WIN32 )
    target_link_libraries( ${LIB_NAME} clingo raylib )
else()
    target_link_libraries( ${LIB_NAME} PUBLIC m clingo raylib )
endif()

set( TEST_INC_DIRS ${INC_DIR} ${SRC_DIR} )
if( WIN32 )
    set( TEST_LINK_LIBS ${LIB_NAME} clingo )
else()
    set( TEST_LINK_LIBS ${LIB_NAME} m clingo )
endif()
add_tests( "${TEST_FILES}" "${TEST_INC_DIRS}" "${TEST_LINK_LIBS}" )

set( DEMO_INC_DIRS ${INC_DIR} ${SRC_DIR} ${DEMO_DIR} )
if( WIN32 )
   set( DEMO_LINK_LIBS ${LIB_NAME} raylib )
else()
   set( DEMO_LINK_LIBS ${LIB_NAME} m raylib )
endif()
add_demos( "${DEMO_FILES}" "${DEMO_INC_DIRS}" "${DEMO_LINK_LIBS}" )
