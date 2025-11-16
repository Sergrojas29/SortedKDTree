# Project Name: **KD-Tree & Directional Graph Library**

> **Note:** This project is a modern recreation and expansion of a university KD-Tree project, now developed as a modular **C++ DLL library** intended for integration into larger desktop applications.

---

## **Table of Contents**
- [Overview](#overview)
- [Features](#features)
- [Planned Capabilities](#planned-capabilities)
- [Project Structure](#project-structure)
- [Build & Setup](#build--setup)
- [Usage Examples](#usage-examples)
- [Testing](#testing)
- [Performance Notes](#performance-notes)
- [Future Development (Desktop Tool + React/Tauri UI)](#future-development-desktop-tool--reacttauri-ui)
- [License](#license)

---

## **Overview**
This library provides:
- A **2D KD-Tree** implementation.
- A **3D KD-Tree** implementation.
- A **Nearest Neighbor Directional Graph** builder for spatial relationships.

Designed for:
- Real-time geometric queries
- Scene analysis
- Point-cloud operations
- Robotics spatial mapping
- Visual tooling + analytics

---

## **Features**
### ✅ Completed
- Modern C++ 23 codebase
- Header-only friendly structure (optional)
- Efficient k-dimensional partitioning
- Configurable distance metrics
- DLL exportable interfaces

### 🧪 Testing
- Built using **GoogleTest**
- Automatic CI test integration planned

### 🏗 Build System
- **CMake** based configuration
- Cross-platform compatibility (Windows / Linux / Mac)

---

## **Planned Capabilities**
- Directed nearest-neighbor graph construction
- Optional weights and filtering on edges
- Serialization support for point sets and trees
- GPU-accelerated spatial distance computations (optional future)

---

## **Project Structure**
```
<project_root>/
│
├─ CMakeLists.txt            # Root build file
├─ /src                      # Source code
│   ├─ kdtree2d.cpp
│   ├─ kdtree3d.cpp
│   ├─ graph_nn.cpp
│   └─ ...
│
├─ /include                  # Public headers (DLL API exposure)
│   ├─ kdtree2d.hpp
│   ├─ kdtree3d.hpp
│   ├─ graph_nn.hpp
│   └─ export.hpp            # DLL export macros
│
├─ /tests                    # Google Test suite
│   ├─ test_kdtree2d.cpp
│   ├─ test_kdtree3d.cpp
│   └─ test_graph.cpp
│
└─ /assets                   # Graphics / diagrams / logos (Placeholder)
```

> **TODO:** Insert architecture diagrams, visual KD-Tree splitting demo, nearest neighbor graph illustration.

---

## **Build & Setup**
```
mkdir build
cd build
cmake ..
cmake --build .
```

DLL output will be located in:
```
/build/bin/
```

---

## **Usage Examples**
> // Placeholder for real examples

```
#include <kdtree2d.hpp>

KDTree2D tree(points);
auto nearest = tree.nearest({x, y});
```

```
#include <graph_nn.hpp>

auto graph = NNGraph(points);
```

---

## **Summary Tables**
| Component | Dimensionality | Purpose | Complexity |
|----------|----------------|---------|------------|
| KDTree2D | 2D Points      | Spatial queries | O(log n) avg |
| KDTree3D | 3D Points      | Point cloud / geometry | O(log n) avg |
| NNGraph  | Any dim        | Nearest-neighbor directional edges | Build: O(n log n) |

---

## **Testing**
Run full test suite:
```
ctest
```

All tests are located in `/tests` directory.

---

## **Performance Notes**
- Balanced construction recommended for optimal lookup
- Works best when data distribution is reasonably uniform
- Consider batching insertions and rebuilds rather than incremental inserts

---

## **Future Development (Desktop Tool + React/Tauri UI)**
This library is intended to serve as the computational backend for a future **desktop visualization tool**:

### **Planned Desktop Stack**
| Layer | Technology |
|------|------------|
| UI | React + Tailwind |
| App Shell | Tauri (Rust) |
| Backend DLL | This C++ library |
| Message Bridge | Tauri FFI or Rust -> C++ bindings |

### Tentative Features:
- Visual KD-Tree partition animation
- Interactive nearest-neighbor graph visualizer
- 3D point-cloud workspace
- Serialization import/export (JSON / binary)

---

## **License**
TBD

---

### **Credits & Acknowledgements**
- Inspired by prior academic work and spatial data structure research.

---

> *End of README Placeholder — Ready for refinement and branding integration.*

