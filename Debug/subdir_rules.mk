################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
configPkg/linker.cmd: ../mcip_master.cfg
	@echo 'Building file: $<'
	@echo 'Invoking: XDCtools'
	"D:/Program/Texas/MCSDK/xdctools_3_23_04_60/xs" --xdcpath="D:/Program/Texas/MCSDK/ipc_1_24_03_32/packages;D:/Program/Texas/MCSDK/ndk_2_24_03_35/packages;D:/Program/Texas/MCSDK/bios_6_33_06_50/packages;D:/Program/Texas/MCSDK/mcsdk_2_01_02_06;D:/Program/Texas/MCSDK/imglib_c66x_3_1_1_0/packages;D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages;D:/Program/Texas/MCSDK/uia_2_00_03_43/packages;D:/Program/Texas/MCSDK/mcsdk_2_01_02_06/demos;D:/Program/Texas/CCSv6.1.2/ccsv6/ccs_base;" xdc.tools.configuro -o configPkg -t ti.targets.elf.C66 -p demos.image_processing.ipc.evmc6678l.platform -r debug -c "D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3" "$<"
	@echo 'Finished building: $<'
	@echo ' '

configPkg/compiler.opt: | configPkg/linker.cmd
configPkg/: | configPkg/linker.cmd

mcip_master_main.obj: ../mcip_master_main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages/ti/drv/qmss" --include_path="D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages/ti/drv/cppi" --include_path="D:/Program/Texas/MCSDK/imglib_c66x_3_1_1_0/inc" -g --define=C66_PLATFORMS --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --preproc_with_compile --preproc_dependency="mcip_master_main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


