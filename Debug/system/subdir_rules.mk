################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
system/platform_osal.obj: ../system/platform_osal.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages/ti/drv/qmss" --include_path="D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages/ti/drv/cppi" --include_path="D:/Program/Texas/MCSDK/imglib_c66x_3_1_1_0/inc" -g --define=C66_PLATFORMS --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --preproc_with_compile --preproc_dependency="system/platform_osal.pp" --obj_directory="system" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

system/resourcemgr.obj: ../system/resourcemgr.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C6000 Compiler'
	"D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 --include_path="D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/include" --include_path="D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages/ti/drv/qmss" --include_path="D:/Program/Texas/MCSDK/pdk_C6678_1_1_2_6/packages/ti/drv/cppi" --include_path="D:/Program/Texas/MCSDK/imglib_c66x_3_1_1_0/inc" -g --define=C66_PLATFORMS --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far --preproc_with_compile --preproc_dependency="system/resourcemgr.pp" --obj_directory="system" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


