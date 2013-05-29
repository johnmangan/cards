project(CARDS)
cmake_minimum_required(VERSION 2.8)

#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

#SQLite Build
set (SQLITE_SOURCE_DIR sqlite/cpp_prototype)

# SQLITE
set (SOURCES ${SQLITE_SOURCE_DIR}/sqlite3.c)
set (HEADERS ${SQLITE_SOURCE_DIR}/sqlite3.h)
include_directories(${SQLITE_SOURCE_DIR})

add_library (sqlite3-shared SHARED ${SOURCES} ${HEADERS})
target_link_libraries(sqlite3-shared) 
set_target_properties(sqlite3-shared PROPERTIES OUTPUT_NAME sqlite3)

#add_library (sqlite3-static STATIC ${SOURCES} ${HEADERS})
#target_link_libraries(sqlite3-static pthread dl)
#set_target_properties(sqlite3-static PROPERTIES OUTPUT_NAME sqlite3)

#add_executable(sqlite3-shell ${SQLITE_SOURCE_DIR}/shell.c ${SOURCES} ${HEADERS})
#target_link_libraries(sqlite3-shell pthread dl)
#set_target_properties(sqlite3-shell PROPERTIES OUTPUT_NAME sqlite3)


set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/../cmake)

set(MODULE_INTERFACES_PATH ${CMAKE_SOURCE_DIR}/modules)
set(IMPLEMENTATION_HEADER_PATH ${CMAKE_SOURCE_DIR}/include)
set(IMPLEMENTATION_SOURCE_PATH ${CMAKE_SOURCE_DIR}/src)
set(UNIT_TEST_SOURCE_PATH ${CMAKE_SOURCE_DIR}/test)

set (EXTERNAL_MODULE_INTERFACES
    ${MODULE_INTERFACES_PATH}/DescriptionInterface.h
    ${MODULE_INTERFACES_PATH}/QueryInterface.h
)

set (INTERNAL_MODULE_INTERFACES
    ${MODULE_INTERFACES_PATH}/AccessManager.h
    ${MODULE_INTERFACES_PATH}/AssetLocator.h
    ${MODULE_INTERFACES_PATH}/AssetMetadataMapping.h
    ${MODULE_INTERFACES_PATH}/AssetTag.h
    ${MODULE_INTERFACES_PATH}/MetadataTag.h
    ${MODULE_INTERFACES_PATH}/RankedSearch.h
)

set (IMPLEMENTATION_HEADERS
    ${IMPLEMENTATION_HEADER_PATH}/AccessManagerImpl.h
    ${IMPLEMENTATION_HEADER_PATH}/AssetLocatorMemoryImpl.h
    ${IMPLEMENTATION_HEADER_PATH}/AssetLocatorDatabase.h
    ${IMPLEMENTATION_HEADER_PATH}/AssetLocatorDatabaseImpl.h
    ${IMPLEMENTATION_HEADER_PATH}/AssetLocatorSQLLiteDatabase.h
    ${IMPLEMENTATION_HEADER_PATH}/AssetTagImpl.h
    ${IMPLEMENTATION_HEADER_PATH}/DescriptionInterfaceImpl.h
    ${IMPLEMENTATION_HEADER_PATH}/MetadataTagImpl.h
    ${IMPLEMENTATION_HEADER_PATH}/QueryInterfaceImpl.h
    ${IMPLEMENTATION_HEADER_PATH}/RankedSearchImpl.h
)

set (IMPLEMENTATION_SOURCES
    ${IMPLEMENTATION_SOURCE_PATH}/AccessManagerImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/AssetLocatorMemoryImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/AssetTagImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/DescriptionInterfaceImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/MetadataTagImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/QueryInterfaceImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/RankedSearchImpl.cpp
)

set (IMPLEMENTATION_SOURCES
    ${IMPLEMENTATION_SOURCE_PATH}/AccessManagerImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/AssetLocatorDatabaseImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/AssetLocatorMemoryImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/AssetLocatorSQLLiteDatabase.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/AssetTagImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/DescriptionInterfaceImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/MetadataTagImpl.cpp
    ${IMPLEMENTATION_SOURCE_PATH}/QueryInterfaceImpl.cpp
)

set (UNIT_TEST_SOURCE
    ${UNIT_TEST_SOURCE_PATH}/main.cpp
)

include_directories(${CMAKE_SOURCE_DIR}
    ${MODULE_INTERFACES_PATH}
    ${IMPLEMENTATION_HEADER_PATH}
)

add_library (cards SHARED
    ${EXTERNAL_MODULE_INTERFACES}
    ${INTERNAL_MODULE_INTERFACES}
    ${IMPLEMENTATION_HEADERS}
    ${IMPLEMENTATION_SOURCES}
)

add_executable (unit_test 
	${UNIT_TEST_SOURCE}
	${EXTERNAL_MODULE_INTERFACES}
        ${INTERNAL_MODULE_INTERFACES}
        ${IMPLEMENTATION_HEADERS}
)

target_link_libraries (unit_test cards sqlite3-shared pthread dl)

# I am sure there is a better way to do this...
set (INSTALL_LIBDIR "lib")
if (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")
    set (INSTALL_LIBDIR "lib64")
endif (${CMAKE_SYSTEM_PROCESSOR} STREQUAL "x86_64")

# install the library
install (TARGETS cards
    DESTINATION ${CMAKE_INSTALL_PREFIX}/${INSTALL_LIBDIR}
)

# install the headers
install (FILES ${EXTERNAL_INTERFACES}
    DESTINATION ${SMAKE_INSTALL_PREFIX}/include
)

