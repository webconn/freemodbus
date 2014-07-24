objects-$(CONFIG_LIB_FREEMODBUS_USE_RTU)+=mbrtu.o

ifeq ($(CONFIG_LIB_FREEMODBUS_RTU_CUSTOM_CRC),n) # TODO: check
	objects-$(CONFIG_LIB_FREEMODBUS_USE_RTU)+=mbcrc.o
endif
