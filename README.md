# CarMonitoringSystem
This project focus on the control and monitoring of automotive systems utilizing the CAN bus protocol. The system features a custom QT-based GUI displayed via HDMI on a Raspberry Pi, which interfaces with an STM32F1 microcontroller for low level data 

## How to build system
You have two options to build this project depending on your target environment:

1. Development build (Debug)
This configuration keeps debug symbols and disables optimization, making it ideal for development and debugging.
``` 
cmake -B build -DCMAKE_BUILD_TYPE=Debug
```
Alternatively, you can run a default build (which usually defaults to Debug or an upoptimized state): 
```
cmake -B build
```

2. Production build (Release)
This configuration enable full optimizations for maximum performance and strips out debug symbols.
```
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

### After configuration the project using one of the commands above, run the following command to compile the systems

```
cmake --build build
```