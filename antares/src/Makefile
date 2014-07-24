objects-$(CONFIG_LIB_FREEMODBUS)+=mb.o

subdirs-$(CONFIG_LIB_FREEMODBUS)+=ports
subdirs-$(CONFIG_LIB_FREEMODBUS_USE_RTU)+=rtu
subdirs-$(CONFIG_LIB_FREEMODBUS_ASCII)+=ascii
subdirs-$(CONFIG_LIB_FREEMODBUS_TCP)+=tcp
subdirs-$(CONFIG_LIB_FREEMODBUS_USE_FUNCS)+=functions

cflags-$(CONFIG_LIB_FREEMODBUS)+=-I$(ANTARES_INSTALL_DIR)/include/lib/freemodbus
