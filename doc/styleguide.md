# Naming Convention

Long and descriptive names are good.
Use the following naming convention:

```
RFR_MODULE_DEFINE
RfrModuleObject
rfr_module_object_function()
preMyVariable
```

The only exception to this is the Vector Math library, whose functions
generally ~~~~resemble assembly instructions.

Variable prefixes vary by context:
- `loc` for local variables
- `in` for function input parameters
- `out` for function output parameters
- `inout` for function input and output parameters
- `gbl` for globals (these should also be `static` and not externally visible)

Consistent names are also important:
- `array` for arrays of things
- `type` for enumerations
- `node` for nodes in a system (not linked lists)
- `list` for linked lists (don't use these though)
- `entity` for any generic networked thing
- `handle` for opaque data structures (e.g. void pointers)
- `func` for function pointers or functions intended for use as function pointers
- `internal` for functions internal to a module
- `i` `j` `k` for integer counters for loops (and only this)
- `f` for temporary floats

# Functions

Long functions are good.
Sequential code is easier to read than function hopping.
Write code that actually does something.
Managers, controllers, and handlers are a red flag.

# Line Limit

Lines should be no more than 110 lines long.
This allows for descriptive names and will still fit on most modern monitors.

# API Design

Steve Jobs: Start with the user, and work your way back to the technology.

Start from the outside (the API) and work backwards to the implementation.