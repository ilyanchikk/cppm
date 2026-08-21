add_executable(indexapp
  main.cpp
  logger.h
  logger.cpp
  searcherFiles.cpp
  searcherFiles.h
  textHandler.h
  textHandler.cpp
)
target_link_libraries(indexapp PRIVATE BD)