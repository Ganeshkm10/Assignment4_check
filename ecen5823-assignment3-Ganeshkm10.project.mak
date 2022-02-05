####################################################################
# Automatically-generated file. Do not edit!                       #
# Makefile Version 10                                              #
####################################################################

BASE_SDK_PATH = C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/gecko_sdk_suite/v3.2
UNAME:=$(shell uname -s | sed -e 's/^\(CYGWIN\).*/\1/' | sed -e 's/^\(MINGW\).*/\1/')
ifeq ($(UNAME),MINGW)
# Translate "C:/super" into "/C/super" for MinGW make.
SDK_PATH := /$(shell echo $(BASE_SDK_PATH) | sed s/://)
endif
SDK_PATH ?= $(BASE_SDK_PATH)
COPIED_SDK_PATH ?= 

# This uses the explicit build rules below
PROJECT_SOURCE_FILES =

C_SOURCE_FILES   += $(filter %.c, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cpp, $(PROJECT_SOURCE_FILES))
CXX_SOURCE_FILES += $(filter %.cc, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.s, $(PROJECT_SOURCE_FILES))
ASM_SOURCE_FILES += $(filter %.S, $(PROJECT_SOURCE_FILES))
LIB_FILES        += $(filter %.a, $(PROJECT_SOURCE_FILES))

C_DEFS += \

ASM_DEFS += \

INCLUDES += \
 -Iautogen

GROUP_START =-Wl,--start-group
GROUP_END =-Wl,--end-group

PROJECT_LIBS = \

LIBS += $(GROUP_START) $(PROJECT_LIBS) $(GROUP_END)

LIB_FILES += $(filter %.a, $(PROJECT_LIBS))

C_FLAGS += \

CXX_FLAGS += \

ASM_FLAGS += \

LD_FLAGS += \


####################################################################
# SDK Build Rules                                                  #
####################################################################
$(OUTPUT_DIR)/project/autogen/gatt_db.o: autogen/gatt_db.c
	@echo 'Building autogen/gatt_db.c'
	@mkdir -p $(@D)
	$(ECHO)$(CC) $(CFLAGS) -c -o $@ autogen/gatt_db.c
CDEPS += $(OUTPUT_DIR)/project/autogen/gatt_db.d
OBJS += $(OUTPUT_DIR)/project/autogen/gatt_db.o

# Automatically-generated Simplicity Studio Metadata
# Please do not edit or delete these lines!
# SIMPLICITY_STUDIO_METADATA=eJy9VO9v2jAQ/VeifJzauIW1qyJKPwCdmIpABDZNdYWMY4hHYke2Uzoh/ved8wNCy9pNWiehIL+73L3cPb+NOxoPv/Q6k1kwnI47vcD13dbNUxI7j0xpLsU1ds+9M+w6TFAZcrEEYDq5Pb3C7k0bKyxaqZI/GDUO/KdMmZ8BhX/IKnHs5mmO01rIOGTKESSxYZIZuWRiF7YJPGZVeEmMmYVzj0LrTHFAbNRHHR9NNVBD37gI5VqjgCdpzCmHxiYLuUSPF7O1VCudEsoQo0xcXDWap0RrvhQJE6Z5+pkIpqNVcn6GShao1g69Tij6v4SiPaEWKiZYHakUC77MFDGwp4pmly1IFsPUnZjMWXyApESZjkxSeGHOYyAIUYCNlDGNCBdHYjpcPUepTDzNobr2IOppQyg8M9i93/QaXtObXX48azTOG58u68sNmaaKp5Zru4Xqp+rrDr6n0BYqRZSf3BM36A9Gd/1Of/J9Fkym3f5wNhh2p3e5bO832FUskY8sxK6/ILFmJ9idZzw2XPSeaJxBU4jcP+zhQGaKFuhOkXUtnLxEYSG2QCLDLGbwInarG+APBjnowPUR2i/Ra4yxGxmT+git1+tqdDBFpDUaFUkeo1Ixm+mUzPLXjMoKkIf5OaNe0dfTzGSpR0BSq9kclmon572hLW9JaV4tDZOD8m0M4813wAWMyV57DWIxhqmCh/fBPlGZt9tK9cHtfFAlcRiJrbt9OLquUXewsxiMn5sMIEdtJu+7txpIK9X+DwZim75iXWVrSIJfaWH7/jUTO0is0sEh9sk1XQG423OxBgtBJQbqZ2EdLLxG51biV5P/jW/9OYfoHThELznsLesQznUWshEx0a78e9ppnVnNVErkuFLHw1FvPOnn3rKp2Sjc+I29DpqA0wRG0tVXojiZx+Aj2Ibhsdna5za/F29Q/MuCWyALKuUsvIV5aet7D+72F6//tFM==END_SIMPLICITY_STUDIO_METADATA
# END OF METADATA