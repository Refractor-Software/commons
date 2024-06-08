# Refractor Commons

### System Requirements

- Dual-core CPU with AVX (x64) or NEON (ARM64) support
  - Our math library is entirely designed around vector math, and will not
    operate without AVX or NEON. Attempting to use the library will result
    in crashes.