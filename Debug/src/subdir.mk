################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Aspect.cpp \
../src/Aspects.cpp \
../src/Engine.cpp \
../src/Entities.cpp \
../src/Entity.cpp \
../src/EntityMgr.cpp \
../src/Functions.cpp \
../src/GameMgr.cpp \
../src/GfxMgr.cpp \
../src/Globals.cpp \
../src/InputMgr.cpp \
../src/Mgr.cpp \
../src/main.cpp 

OBJS += \
./src/Aspect.o \
./src/Aspects.o \
./src/Engine.o \
./src/Entities.o \
./src/Entity.o \
./src/EntityMgr.o \
./src/Functions.o \
./src/GameMgr.o \
./src/GfxMgr.o \
./src/Globals.o \
./src/InputMgr.o \
./src/Mgr.o \
./src/main.o 

CPP_DEPS += \
./src/Aspect.d \
./src/Aspects.d \
./src/Engine.d \
./src/Entities.d \
./src/Entity.d \
./src/EntityMgr.d \
./src/Functions.d \
./src/GameMgr.d \
./src/GfxMgr.d \
./src/Globals.d \
./src/InputMgr.d \
./src/Mgr.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/esantiago/Downloads/As4/inc" -I/usr/local/include/OGRE -I/usr/local/include/OGRE/Overlay -I/usr/include/ois -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


