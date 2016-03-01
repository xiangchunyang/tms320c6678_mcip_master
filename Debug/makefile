################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3

GEN_OPTS__FLAG := --cmd_file="configPkg/compiler.opt"
GEN_CMDS__FLAG := -l"configPkg/linker.cmd"

ORDERED_OBJS += \
"./mcip_imgproc.obj" \
"./mcip_master_main.obj" \
"./system/platform_osal.obj" \
"./system/resourcemgr.obj" \
$(GEN_CMDS__FLAG) \
-l"libc.a" \
-l"imglib.ae66" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include system/subdir_vars.mk
-include subdir_rules.mk
-include system/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
mcip_master.out \

EXE_OUTPUTS__QUOTED += \
"mcip_master.out" \

BIN_OUTPUTS += \
mcip_master.hex \

BIN_OUTPUTS__QUOTED += \
"mcip_master.hex" \


# All Target
all:
	@$(MAKE) --no-print-directory main-build

# Main-build Target
main-build: mcip_master.out

# Tool invocations
mcip_master.out: $(OBJS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C6000 Linker'
	"D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/bin/cl6x" -mv6600 --abi=eabi -O3 -g --define=C66_PLATFORMS --display_error_number --diag_warning=225 --mem_model:const=far --mem_model:data=far -z -m"mcip_master.out" --heap_size=0x100000 -i"D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/lib" -i"D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/include" -i"D:/Program/Texas/MCSDK/imglib_c66x_3_1_1_0/lib" --reread_libs --warn_sections --xml_link_info="mcip_master_linkInfo.xml" --rom_model -o "mcip_master.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

mcip_master.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C6000 Hex Utility'
	"D:/Program/Texas/CCSv6.1.2/ccsv6/tools/compiler/ti-cgt-c6000_8.0.3/bin/hex6x"  -o "mcip_master.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)$(GEN_FILES__QUOTED)$(BIN_OUTPUTS__QUOTED)$(GEN_OPTS__QUOTED)$(GEN_CMDS__QUOTED)
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-$(RM) "mcip_imgproc.pp" "mcip_master_main.pp" "system\platform_osal.pp" "system\resourcemgr.pp" 
	-$(RM) "mcip_imgproc.obj" "mcip_master_main.obj" "system\platform_osal.obj" "system\resourcemgr.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: main-build

-include ../makefile.targets

