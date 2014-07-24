objects-$(CONFIG_LIB_FREEMODBUS_USE_RTU)+=mbrtu.o

ifneq ($(CONFIG_LIB_FREEMODBUS_RTU_CUSTOM_CRC),y)
	objects-$(CONFIG_LIB_FREEMODBUS_USE_RTU)+=mbcrc.o
endif

cflags-$(CONFIG_LIB_FREEMODBUS)+=-I$(ANTARES_INSTALL_DIR)/include/lib/freemodbus
