# Types

When possible, prefer to use opaque or standard types instead of
custom structs/unions/enums. This is mainly for de-coupling and
reusability across projects.

# Naming Convention

Long and descriptive names are good.
Use the following naming convention:

```
#define RFR_MODULE_DEFINE
struct rfr_module_object_t
RfrModuleObjectFunction()
PreMyVariableSuf
```

Variable prefixes vary by context:
- `Loc` for local variables
- `In` for function input parameters
- `Out` for function output parameters
- `InOut` for function input and output parameters
- `Gbl` for globals (these should also be `static` and not externally visible)
    - If API design forces you to place a global in a header (please don't),
    prefix with `Rfr` as well (`RfrGbl`)

Consistent names are also important:
- `Array` for arrays of things (e.g. `object* pInObjectArray`)
- `Type` for enumerations
- `Node` for nodes in a system (not linked lists)
- `List` for linked lists (don't use these though)
- `Entity` for any generic networked thing
- `Handle` for opaque data structures (e.g. void pointers)
- `Func` for function pointers or functions intended for use as function pointers
- `Internal` for functions internal to a module
- `i` `j` `k` for integer counters for loops (and only this)
- `f` for temporary floats (e.g. `double fLocTemporary`)
- `p` for pointers (e.g. `object* pInObject`)
- `ref` for references (e.g. `object& InObjectRef`)
    - References are just syntactic sugar for a `*const` with benefits, so this
    is important to make the indirection readable inside, for example, a deeply
    nested function heirarchy

# Functions

- Long functions are good
- Sequential code is easier to read than function hopping
- Write code that actually does something
  - Managers, controllers, and handlers are a red flag
- For functions accepting an input and output buffer (a `src` and a `dst`), place
  `dst` first and `src` second
    - Example: `void UpdateObjects(object* pOutDstArray, object* pInSrcArray, ...)`
    - This is for consistency with C standard library APIs
- Consider using structs for input and output data for better packing and cache
line performance

# Line Limit

- Lines should be no more than 120 lines long.
    - This allows for descriptive names while still fitting on most modern
    widescreen monitors. After all, you spend more time reading your code than
    the compiler does.
    - Diffs and merges might be a pain in the ass (most will recommend a limit
    of 80 lines for this reason), but we think it is acceptable because of the
    longer and more descriptive names.

# API Design

Start from the outside (the API) and work backwards to the implementation.

Abide by the five elements of reusable API design, as outlined by Casey Muratori
in *Designing and Evaluating Reusable Components*:

- Granularity (Flexibility vs. Simplicity)
- Redundancy (Convenience vs. Orthogonality)
- Coupling (Less is better)
- Retention (Synchronization vs. Automation)
- Flow Control (Maximum control for the client)

These elements ensure a stable, long-lasting API.

Casey's blog post and talk can be found [here](https://caseymuratori.com/blog_0024).
Please listen to it in its entirety to best understand these concepts.