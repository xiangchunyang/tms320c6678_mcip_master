#
_XDCBUILDCOUNT = 
ifneq (,$(findstring path,$(_USEXDCENV_)))
override XDCPATH = D:/Program/Texas/MCSDK/ipc_1_24_03_32/packages;D:/Program/Texas/MCSDK/ndk_2_24_03_35/packages;D:/Program/Texas/MCSDK/bios_6_33_06_50/packages;D:/Program/Texas/MCSDK/mcsdk_2_01_02_06;D:/Program/Texas/MCSDK/imglib_c66x_3_1_1_0/packages;D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages;D:/Program/Texas/MCSDK/uia_2_00_05_50/packages;D:/Program/Texas/MCSDK/mcsdk_2_01_02_06/demos;D:/Program/Texas/CCSv6.1.2/ccsv6/ccs_base
override XDCROOT = D:/Program/Texas/MCSDK/xdctools_3_23_04_60
override XDCBUILDCFG = ./config.bld
endif
ifneq (,$(findstring args,$(_USEXDCENV_)))
override XDCARGS = 
override XDCTARGETS = 
endif
#
ifeq (0,1)
PKGPATH = D:/Program/Texas/MCSDK/ipc_1_24_03_32/packages;D:/Program/Texas/MCSDK/ndk_2_24_03_35/packages;D:/Program/Texas/MCSDK/bios_6_33_06_50/packages;D:/Program/Texas/MCSDK/mcsdk_2_01_02_06;D:/Program/Texas/MCSDK/imglib_c66x_3_1_1_0/packages;D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages;D:/Program/Texas/MCSDK/uia_2_00_05_50/packages;D:/Program/Texas/MCSDK/mcsdk_2_01_02_06/demos;D:/Program/Texas/CCSv6.1.2/ccsv6/ccs_base;D:/Program/Texas/MCSDK/xdctools_3_23_04_60/packages;..
HOSTOS = Windows
endif
