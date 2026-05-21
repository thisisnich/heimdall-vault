################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Arm Compiler - building file: "$<"'
	"" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/Users/Nicholas Dubs/Documents/Obsidian/heimdall-vault/99-ATTACHMENTS/EGE320/EGE320_E2/Lab3a" --include_path="/include" --define=ccs="ccs" --define=PART_TM4C129ENCPDT -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


