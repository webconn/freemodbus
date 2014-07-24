cflags-y+=-DCONFIG_LIB_FREEMODBUS_PORT_RTS_PORT=$(call unquote,$(CONFIG_LIB_FREEMODBUS_PORT_RTS_PORT_Q))

objects-$(CONFIG_LIB_FREEMODBUS_PORT_OPTCRC)+=mbcrc.o
objects-y+=portevent.o portserial.o porttimer.o

cflags-$(CONFIG_LIB_FREEMODBUS)+=-I$(ANTARES_INSTALL_DIR)/include/lib/freemodbus
