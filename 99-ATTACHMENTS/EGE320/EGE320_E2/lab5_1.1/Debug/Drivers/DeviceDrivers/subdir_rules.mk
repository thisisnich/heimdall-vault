################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/DeviceDrivers/%.obj: ../Drivers/DeviceDrivers/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'ARM Compiler: "$<"'
	"" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/lab5_1.1" --include_path="/include" --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/lab5_1.1/Drivers/CoreDrivers" --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/lab5_1.1/Drivers/DeviceDrivers" --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/lab5_1.1/Drivers/PeripheralDrivers" --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/lab5_1.1/Libraries" --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/lab5_1.1/Libraries/grlib" --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/lab5_1.1/Libraries/grlib/fonts" --define=ccs="ccs" --define=PART_TM4C129ENCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Drivers/DeviceDrivers/$(basename $(<F)).d_raw" --obj_directory="Drivers/DeviceDrivers" $(GEN_OPTS__FLAG) "$<"
	@echo ' '


