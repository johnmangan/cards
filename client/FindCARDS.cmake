FIND_PATH(CARDS_INCLUDE_DIR QueryInterfaceImpl.h
  PATHS
  $ENV{CARDS_HOME}
  NO_DEFAULT_PATH
    PATH_SUFFIXES include
)

FIND_PATH(CARDS_INCLUDE_DIR QueryInterfaceImpl.h
  PATHS
  /usr/local/include
  /usr/include
)

FIND_PATH(CARDS_MODULES_DIR QueryInterface.h
  PATHS
  $ENV{CARDS_HOME}
  NO_DEFAULT_PATH
    PATH_SUFFIXES modules
)

FIND_PATH(CARDS_MODULES_DIR QueryInterface.h
  PATHS
  /usr/local/modules
  /usr/modules
)

FIND_LIBRARY(CARDS_LIBRARY 
  NAMES libcards
  PATHS
    $ENV{CARDS_HOME}
    NO_DEFAULT_PATH
    PATH_SUFFIXES lib64 lib
)

FIND_LIBRARY(SQLITE_LIBRARY
  NAMES sqlite3
  PATHS
    $ENV{CARDS_HOME}
    NO_DEFAULT_PATH
    PATH_SUFFIXES lib64 lib
)

SET(CARDS_FOUND "NO")
IF(CARDS_LIBRARY AND CARDS_INCLUDE_DIR AND CARDS_MODULES_DIR)
  SET(CARDS_FOUND "YES")
ENDIF(CARDS_LIBRARY AND CARDS_INCLUDE_DIR AND CARDS_MODULES_DIR)
