# Architecture

Goals: deterministic updates, minimal runtime allocations, clear layering.

Layers
- Core (game mode / loop ownership)
- Training (configurable module API: name, description, complexity, passing score)
- Interaction (VR/desktop pawns; Enhanced Input)
- Procedural (station builder; dynamic mesh ops)

Decisions
- Public headers only expose stable APIs; implementation stays Private.
- Geometry generation done via call‑in‑editor functions to separate authoring from runtime.
- Dependencies centralized in `JobSimulation.Build.cs` (EnhancedInput, UMG/Slate, OpenXR/XRBase, GeometryScriptingCore, ModelingComponents, DynamicMesh).
