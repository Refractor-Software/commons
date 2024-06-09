# Types

When possible, prefer to use opaque or standard types instead of
custom structs/unions/enums. This is mainly for de-coupling and
reusability across projects.

# Naming Convention

Long and descriptive names are good.
Use the following naming convention:

```
RFR_MODULE_DEFINE
RfrModuleObject
rfr_module_object_function()
preMyVariable
```

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

Lines should be no more than 120 lines long.
This allows for descriptive names and will still fit on most modern monitors.
Diffs and merges might be a pain in the ass, but we think it will be worth it.

# API Design

Steve Jobs: Start with the user, and work your way back to the technology.

Start from the outside (the API) and work backwards to the implementation.

Ensure that you follow the following five rules of reusable API design, as
outlined by Casey Muratori in *Designing and Evaluating Reusable Components*:

- Granularity (Flexibility vs. Simplicity)
- Redundancy (Convenience vs. Orthogonality)
- Coupling (Less is better)
- Retention (Synchronization vs. Automation)
- Flow Control (Maximum control for the client)

If you follow these rules, your API will be the most stable and powerful
it can be.

Casey's blog post and talk can be found [here](https://caseymuratori.com/blog_0024).
Please listen to it in its entirety to best understand these concepts.