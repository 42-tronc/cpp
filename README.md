# C++

## General requirements

- Compile with: `c++`
- Flags: `-std=c++98 -Wall -Wextra -Werror`

Exercice folders should be `ex00`, `ex01`, etc.


- Classes names use `PascalCase`.
- Classes files use `PascalCase.hpp`, `PascalCase.cpp` or `PascalCase.tpp`.

Every output message must end with a newline character `\n` or `std::endl`.

No external libraries:
- C++11
- Boost libraries
- *printf(), *alloc(), free()
- using namespace
- friend
- containers (vector, list, map, etc.)
- algorithms (anything that requires `<algorithm>`)
- no inline functions (except for templates)

Allowed to use the STL in modules 8 and 9 only.

From module 2 to 9, clases must be designed in the Orthodox Canonical Form, except when specified otherwise.

You should be able to include your header independently of the order of inclusion, they need to include all the necessary headers to compile.
However, you must avoid double inclusion by using include guards (`#ifndef`).

You can add additional files to your project if you need to, but you must include the mandatory files.

If the example shows a requirement, it is mandatory, even if it is not specified in the subject.

When allocating **memory** by using `new` or `new[]`, you must free it with `delete` or `delete[]`.


## Module 00


## Module 06

### ex00
`./convert 47hello`
`./convert 47.`
`./convert 47.f`
`./convert 47ff`
`./convert inff`
`./convert infff`
`./convert +inff`
`./convert -inff`
`./convert nan`
`./convert nanf`
`./convert "bjr"`
`./convert 0`
`./convert ""`
`./convert`
