include_directories(${PROJECT_SOURCE_DIR}/include)

AVR_ADD_LIBRARY(boardlib board.c)
AVR_ADD_LIBRARY(gpiolib gpio.c)
AVR_ADD_LIBRARY(tasterlib taster.c)
AVR_ADD_LIBRARY(intlib interrupt_setup.c)
AVR_ADD_LIBRARY(ledlib led.c)

AVR_ADD_EXECUTABLE(main main.c)
AVR_TARGET_LINK_LIBRARIES(main boardlib gpiolib tasterlib intlib ledlib)