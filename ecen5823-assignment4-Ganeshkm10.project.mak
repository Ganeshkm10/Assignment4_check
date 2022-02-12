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
# SIMPLICITY_STUDIO_METADATA=eJy9VG1v2jAQ/itRPk40bunLqojSD0AnpiEQgU1TXSHjGOKR2JHtlE6I/75zXiC0rN2kdRIK8nOXuyd3j5+NOxoPP/c6k1kwnI47vcD13dbtUxI7j0xpLsUNds+8U+w6TFAZcrEEYDq5O7nG7m0bKyxaqZI/GDUO/KdMmZ8BhX/IKnHs5mmO01rIOGTKESSxYZIZuWRiF7YJPGZVeEmMmYVzj0LrTHFAbNRHHR9NNVBD37gI5VqjgCdpzCmHxiYLuUSPl7O1VCudEsoQo0xcXjfPT4jWfCkSJszFyScimI5WydkpKlmgWjv0OqHo/xKK9oRaqJhgdaRSLPgyU8TAniqaXbYgWQxTd2IyZ/EBkhJlOjJJ4YU5j4EgRAE2UsY0Ilwcielw9RylMvE0h+rag6inDaHwzGD3/rnX9M692dXFabN51vx4VV9uyDRVPLVc2y1UP1Vfd/A9hbZQKaL85DbcoD8Yfel3+pPvs2Ay7faHs8GwO/2Sy/Z+g915xmPDRe+Jxhm0wK5//9DArmKJfGQhHBck1qyxSwxkpmiRt1NkXQuNlygsxJZMZJjFDF7EbnUD/MEgBx24PkL7JXqDMXYjY1IfofV6XY0Opoi0RqMiyWNUKmYznZJZ/ppRWQHyMD9n1Cv6epqZLPUISGo1m8NS7eS8N7TlLSnNq6VhclC+jWG8+Q64gMHZa69BLMYwVfDwPtgnKvN2W6k+uJ0PqiQOI7F1tw9H1zXqDnYWg/FzkwHkqM3kffdWA2ml2v/BQGzTV6yrbA1J8CstbN+/ZmIHiVU6OMQ+uaYrAHd7LtZgIajEQP0srIOF1+jcSvxq8r/xrT/nEL0Dh+glh71lHcK5zkI2IibalX9PO60zq5lKiRxX6ng46o0n/dxbNjUbhRu/sddBE7CUwEi6+koUJ/MYfATbMDw2W/vc5vfiDYp/WXALZEGlnIV3MC9tfe/B3f4CyAu0WQ===END_SIMPLICITY_STUDIO_METADATA
# END OF METADATA