################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ALU.cpp \
../src/ALUsimulator.cpp \
../src/CTAMemory.cpp \
../src/IllegalArgumentException.cpp \
../src/Memory.cpp \
../src/RegisterSet.cpp 

OBJS += \
./src/ALU.o \
./src/ALUsimulator.o \
./src/CTAMemory.o \
./src/IllegalArgumentException.o \
./src/Memory.o \
./src/RegisterSet.o 

CPP_DEPS += \
./src/ALU.d \
./src/ALUsimulator.d \
./src/CTAMemory.d \
./src/IllegalArgumentException.d \
./src/Memory.d \
./src/RegisterSet.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


