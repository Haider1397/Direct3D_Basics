# Direct3D_Basics

A C++ educational project demonstrating fundamental Direct3D 11 graphics programming concepts. This project provides a minimal but complete framework for rendering graphics using the DirectX API.

## Project Overview

**Direct3D_Basics** is a Windows-based graphics application built with Direct3D 11. It serves as a learning resource for understanding the core concepts of modern graphics API usage, including device initialization, shader compilation, vertex buffer management, and basic rendering pipeline setup.

## Features

- **Graphics Device Management**: Abstracted Direct3D 11 device and context handling
- **Shader Compilation**: Runtime shader compilation supporting vertex and pixel shaders
- **Graphics Pipeline State**: Encapsulated pipeline state management
- **Vertex Buffer Support**: Vertex buffer creation and management
- **Swap Chain Management**: Double-buffered rendering with DXGI integration
- **Device Context**: Rendering context for executing drawing commands
- **Error Handling**: Comprehensive exception-based error handling
- **Logging System**: Built-in logging for debugging and diagnostics

## Architecture

The project is organized into several key components:

### Core Components

#### `GraphicsDevice`
- **Purpose**: Central graphics resource factory and Direct3D device manager
- **Key Responsibilities**:
  - Create swap chains for rendering targets
  - Create device contexts for command recording
  - Compile shaders (vertex and pixel shaders)
  - Create graphics pipeline states
  - Create vertex buffers
  - Execute command lists
- **Located in**: `DX3D/Source/DX3D/Graphics/GraphicsDevice.h/cpp`

#### `DeviceContext`
- **Purpose**: Rendering context for recording graphics commands
- **Key Responsibilities**:
  - Clear and set render targets
  - Set graphics pipeline states
  - Set vertex buffers
  - Configure viewport dimensions
  - Issue draw calls (e.g., triangle lists)
- **Located in**: `DX3D/Source/DX3D/Graphics/DeviceContext.h/cpp`

#### `GraphicsEngine`
- **Purpose**: High-level graphics rendering engine
- **Key Responsibilities**:
  - Initialize graphics device and context
  - Compile and manage shaders
  - Create graphics pipeline states
  - Create vertex buffers
  - Orchestrate rendering operations
- **Located in**: `DX3D/Source/DX3D/Graphics/GraphicsEngine.h/cpp`

#### `SwapChain`
- **Purpose**: Manages the DXGI swap chain and backbuffer rendering
- **Key Responsibilities**:
  - Initialize DXGI swap chain
  - Manage render target views
  - Present rendered frames
  - Handle backbuffer reloading
- **Located in**: `DX3D/Source/DX3D/Graphics/SwapChain.h/cpp`

#### `VertexBuffer`
- **Purpose**: GPU vertex data storage and management
- **Stores**: Vertex position data (currently stores Vec3 positions)
- **Used in**: Rendering geometry

#### `Game`
- **Purpose**: Main application class and game loop controller
- **Key Responsibilities**:
  - Initialize graphics engine and display
  - Manage the main game loop
  - Handle application lifetime
- **Located in**: `DX3D/Include/DX3D/Game/Game.h`

#### `Display`
- **Purpose**: Window management and swap chain integration
- **Creates**: Application window and associates swap chain
- **Located in**: `DX3D/Source/DX3D/Game/Display.cpp`

## Rendering Pipeline

The basic rendering flow works as follows:

1. **Initialization Phase**:
   - Create graphics device
   - Create device context
   - Compile vertex and pixel shaders
   - Create graphics pipeline state
   - Create vertex buffer with triangle vertices

2. **Rendering Phase** (each frame):
   - Clear backbuffer (red background)
   - Set active pipeline state
   - Set viewport dimensions
   - Set vertex buffer
   - Draw triangle list (3 vertices forming a triangle)
   - Execute command list
   - Present rendered frame

## Default Rendering

The project renders a simple white triangle against a red background. The triangle vertices are defined as:
- Vertex 1: (-0.5, -0.5, 0.0) - Bottom left
- Vertex 2: (0.0, 0.5, 0.0) - Top center
- Vertex 3: (0.5, -0.5, 0.0) - Bottom right

## Key Data Structures

### Configuration Descriptors

- **GraphicsEngineDesc**: Configuration for graphics engine initialization
- **GraphicsDeviceDesc**: Configuration for graphics device creation
- **SwapChainDesc**: Swap chain parameters (window handle, size)
- **ShaderCompileDesc**: Shader compilation parameters (source, entry point, type)
- **GraphicsPipelineStateDesc**: Pipeline state configuration (vertex + pixel shaders)
- **VertexBufferDesc**: Vertex buffer parameters (data, size, stride)
- **GameDesc**: Game initialization parameters (window size, log level)

## Building the Project

### Requirements
- Windows OS
- Visual Studio with C++ support
- DirectX SDK or Windows SDK (includes Direct3D 11)
- Windows 10 or later

### Build Instructions

1. Open `DirectXGame.sln` in Visual Studio
2. Build the solution (Build → Build Solution)
3. Run the executable

The project uses MSBuild project files (`.vcxproj`) for compilation.

## Entry Point

The application entry point is in `Game/main.cpp`:

```cpp
int main()
{
    try
    {
        dx3d::Game game({ {1280,720}, dx3d::Logger::LogLevel::Info });
        game.run();
    }
    catch (const std::runtime_error&)
    {
        return EXIT_FAILURE;
    }
    catch (const std::invalid_argument&)
    {
        return EXIT_FAILURE;
    }
    catch (const std::exception&)
    {
        return EXIT_FAILURE;
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
