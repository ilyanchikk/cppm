find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(searchapp
    main.cpp
    mainwindow.h
    mainwindow.cpp
	mainwindow.ui
        dbform.cpp
        dbform.h
        dbform.ui
        dbviewall.cpp
        dbviewall.h
        dbviewall.ui
)

target_link_libraries(searchapp PRIVATE BD Qt6::Widgets)
