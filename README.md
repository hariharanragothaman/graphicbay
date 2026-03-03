# C-SHOP: A Mall Shopping Simulation

> **A Turbo C++ 3.0 / BGI Graphics project preserved as a historical artifact.**
> This code was written for Borland Turbo C++ on MS-DOS and is not intended to compile on modern compilers.

---

## Table of Contents

- [About](#about)
- [The Compiler](#the-compiler)
- [Architecture](#architecture)
- [Application Flow](#application-flow)
- [Shop Catalog](#shop-catalog)
- [Member & Points System](#member--points-system)
- [Data Storage](#data-storage)
- [Class Hierarchy](#class-hierarchy)
- [Function Reference](#function-reference)
- [Known Issues](#known-issues)
- [Screenshots (Conceptual)](#screenshots-conceptual)
- [How to Run (Historical)](#how-to-run-historical)
- [Authors](#authors)

---

## About

**C-SHOP** is a mall/shopping simulation program built as a school project under the guidance of **Mrs. Kala**. It simulates a multi-store shopping experience with:

- 5 virtual shops (vegetables, hardware, stationery, cafe, books)
- A membership system with file-based persistence
- A loyalty points and discount engine
- A graphical UI rendered using Borland Graphics Interface (BGI)
- Employee management capabilities

The program was written by **Hariharan** and **Abhishek**.

---

## The Compiler

This project targets **Borland Turbo C++ 3.0** (1992), a DOS-based C/C++ compiler and IDE from Borland International.

### Key Facts

| Detail               | Value                                                    |
|-----------------------|----------------------------------------------------------|
| **Product**           | Borland Turbo C++ 3.0                                    |
| **Release Year**      | 1992                                                     |
| **Platform**          | MS-DOS                                                   |
| **Interface**         | Text-mode IDE with integrated debugger                   |
| **Graphics Library**  | BGI (Borland Graphics Interface)                         |
| **Standard**          | Pre-ANSI/ISO C++ (no namespaces, no `std::`, no STL)     |
| **Archive**           | https://winworldpc.com/product/turbo-c/3x                |

### What Makes It Different from Modern C++

Turbo C++ 3.0 predates the first C++ standard (C++98). Code written for it uses patterns that are incompatible with modern compilers:

- **Old-style headers**: `#include <iostream.h>` instead of `#include <iostream>`
- **No namespaces**: `cout` instead of `std::cout`
- **`void main()`**: Non-standard entry point (standard requires `int main()`)
- **`conio.h`**: DOS console I/O (`clrscr()`, `gotoxy()`, `getch()`, `textcolor()`)
- **`graphics.h`**: Borland Graphics Interface for drawing primitives
- **`dos.h`**: Direct DOS interrupt and system calls (`delay()`)
- **`gets()`**: Unsafe input (removed in C11, deprecated long before)
- **Implicit `int` return types**: Functions without explicit return types
- **`goto` statements**: Used for control flow throughout
- **Variable declarations mid-scope**: Turbo C++ handled scoping differently from ISO C++

### BGI (Borland Graphics Interface)

BGI was Borland's proprietary graphics library for DOS. It provided:

- Primitives: `line()`, `circle()`, `arc()`, `rectangle()`, `ellipse()`, `pieslice()`
- Text rendering: `outtextxy()`, `settextstyle()`, `settextjustify()`
- Color control: `setcolor()`, `setbkcolor()`
- Graph initialization: `initgraph()` with driver auto-detection (`DETECT`)
- Screen management: `cleardevice()`, `closegraph()`

The BGI drivers (`.BGI` files) were loaded from a path on disk, typically `C:\TC\BGI`.

---

## Architecture

### High-Level System Diagram

```
┌─────────────────────────────────────────────────────────────────┐
│                        C-SHOP APPLICATION                       │
├─────────────────────────────────────────────────────────────────┤
│                                                                 │
│  ┌──────────┐    ┌──────────────────────────────────────────┐   │
│  │  main()  │───>│          SPLASH SCREEN                   │   │
│  │          │    │  - BGI graphics init                     │   │
│  │          │    │  - Loading bar animation                 │   │
│  │          │    │  - Credits (rotating ellipse animation)  │   │
│  └────┬─────┘    └──────────────────────────────────────────┘   │
│       │                                                         │
│       v                                                         │
│  ┌──────────┐    ┌──────────────────────────────────────────┐   │
│  │  Main    │    │         SHOP MODULES                     │   │
│  │  Menu    │───>│                                          │   │
│  │          │    │  ┌──────────┐  ┌───────────────┐         │   │
│  └────┬─────┘    │  │vegetables│  │   hardware    │         │   │
│       │          │  │ 10 items │  │   7 items     │         │   │
│       │          │  └──────────┘  └───────────────┘         │   │
│       │          │  ┌──────────┐  ┌───────────────┐         │   │
│       │          │  │stationary│  │     cafe      │         │   │
│       │          │  │ 10 items │  │   12 items    │         │   │
│       │          │  └──────────┘  └───────────────┘         │   │
│       │          │  ┌──────────┐                            │   │
│       │          │  │  books   │                            │   │
│       │          │  │ 10 items │                            │   │
│       │          │  └──────────┘                            │   │
│       │          └──────────────────────────────────────────┘   │
│       │                        │                                │
│       │                        v                                │
│       │          ┌──────────────────────────────────────────┐   │
│       │          │           buy()                          │   │
│       │          │  - Select items by index                 │   │
│       │          │  - Specify quantity (max 10)             │   │
│       │          │  - Items added to global cart itm[30]    │   │
│       │          └─────────────────┬────────────────────────┘   │
│       │                            │                            │
│       v                            v                            │
│  ┌──────────────────────────────────────────────────────────┐   │
│  │                    bill()                                │   │
│  │  - Member login / registration                          │   │
│  │  - Offers & point redemption                            │   │
│  │  - Duplicate item merging (check2)                      │   │
│  │  - Tax calculation (2% VAT)                             │   │
│  │  - Final total with discounts                           │   │
│  │  - Points update written to file                        │   │
│  │  - Exit animation                                       │   │
│  └──────────────────────────────────────────────────────────┘   │
│                                                                 │
│  ┌──────────────────────────────────────────────────────────┐   │
│  │                 MEMBER SYSTEM                            │   │
│  │                                                          │   │
│  │  newmem()   - Register new member                       │   │
│  │  info()     - Enter personal information                │   │
│  │  modify()   - Update existing information               │   │
│  │  offers()   - Redeem points / claim bonuses             │   │
│  │  employee() - Admin: view, edit, delete members         │   │
│  │                                                          │   │
│  │  Storage: binary file "Memberz"                         │   │
│  └──────────────────────────────────────────────────────────┘   │
│                                                                 │
└─────────────────────────────────────────────────────────────────┘
```

### Data Flow Diagram

```
  User Input (keyboard)
       │
       v
  ┌─────────┐     ┌─────────────┐     ┌──────────────┐
  │  Shop    │────>│  buy()      │────>│ Global Cart  │
  │ Display  │     │  (item      │     │ itm[30]      │
  │          │     │   selection) │     │ (bill1 array)│
  └─────────┘     └─────────────┘     └──────┬───────┘
                                              │
                                              v
                                      ┌──────────────┐
                                      │   bill()     │
                                      │              │
                   ┌─────────────┐    │  - check2()  │
                   │  "Memberz"  │<──>│  - tax calc  │
                   │  (binary    │    │  - discounts │
                   │   file)     │    │  - points    │
                   └─────────────┘    └──────────────┘
                         ^                    │
                         │                    v
                   ┌─────────────┐      ┌──────────┐
                   │  newmem()   │      │  Screen  │
                   │  info()     │      │  Output  │
                   │  modify()   │      │  (BGI +  │
                   │  employee() │      │   cout)  │
                   └─────────────┘      └──────────┘
```

---

## Application Flow

### Startup Sequence

```
main()
  │
  ├── 1. Initialize BGI graphics (640x480, auto-detect driver)
  ├── 2. Draw mascot character (circle + pieslice + arc primitives)
  ├── 3. Display "WELCOME TO THE C-SHOP!!!"
  ├── 4. Animated loading bar (171px to 470px, with slowdown at 50%)
  ├── 5. Credits screen with rotating ellipse animation
  │      Authors: "Hariharan" and "Abhishek"
  │      (animation runs until keypress)
  ├── 6. Main menu: Shops / Member Zone / Help / Credits / Exit
  │
  └── On exit ──> bill() ──> Goodbye animation (expanding colored arcs)
```

### Menu Navigation

```
MAIN MENU                    SHOP MENU (face())
─────────                    ───────────────────
1. Visit the shops ────────> 1. Veggies
2. Member Zone               2. Hardware World
3. Help                       3. Stationaries
4. Credits                    4. Compsci Cafe
5. Exit                       5. Bookworm
                              6. Member Zone
                              7. Help
                              8. Exit ──────────> bill()
```

---

## Shop Catalog

| Shop            | Items | Products                                                         | Price Range       |
|-----------------|-------|------------------------------------------------------------------|-------------------|
| **Veggies**     | 10    | Potato, Onion, Carrot, Cabbage, Spinach, Ladysfinger, Apple, Mango, Banana, Orange | Rs 20-42 (random) |
| **Hardware World** | 7  | Screw Driver, Hammer, Plier, Floor Jack, Spanner, Springs, Wallgrip | Rs 40-71 (random) |
| **Stationaries** | 10   | Scale, Pencils, Pens, Eraser, Stapler, Whitener, Cellotape, A4 Paper Bundle, Paints, Paintbrush | Rs 10-31 (random) |
| **Compsci Cafe** | 12   | Tea, Coffee, Sandwich, Tomato Soup, Potato Puff, Samosa, Gatorade, Pizza, Cake, Ice Cream, Fruit Juice, Cold Drinks | Rs 20-41 (random) |
| **Book Worm**   | 10    | D.C. Pandey, Tata McGraw-Hill, Resnick Halliday, J.D. Lee, Wren & Martin, S.L. Arora, H.C. Verma, R.D. Sharma, Sumita Arora, R.S. Agarwal | Rs 300-361 (random) |

Prices are randomized each session using `rand()/100 % range + base`.

---

## Member & Points System

### Member Registration

```
New Member
    │
    ├── Choose Member ID (integer)
    │     ├── IDs 101-109: Reserved for employees (password: 13)
    │     └── All other IDs: Regular members
    │
    ├── Starting points: random 10-20
    │
    └── Options after registration:
          ├── View offers
          ├── Enter personal information
          └── Continue shopping
```

### Points & Offers Engine

```
                    ┌──────────────────┐
                    │   OFFERS MENU    │
                    └────────┬─────────┘
                             │
            ┌────────────────┼────────────────┐
            │                │                │
            v                v                v
    ┌───────────────┐ ┌─────────────┐ ┌───────────────┐
    │ Redeem Points │ │ Bonus: +10  │ │ Bonus: +30    │
    │ for Discount  │ │ (if total   │ │ (if buying    │
    │ (Rs 1 per pt) │ │  > Rs 500)  │ │  > 10 items)  │
    └───────────────┘ └─────────────┘ └───────────────┘

    Only ONE offer can be claimed per session.

    Points earned per transaction:
    ┌─────────────────────────────────────┐
    │  points = (final_total / 10) + bp  │
    │  where bp = bonus points (0/10/30) │
    └─────────────────────────────────────┘
```

### Bill Calculation

```
    Subtotal  =  sum of (item price * quantity)
    Tax       =  Subtotal * 2% (VAT)
    Discount  =  Redeemed points (Rs 1 per point)
    ─────────────────────────────────────────────
    Total     =  Subtotal + Tax - Discount
                 (floored at Rs 0)

    Employee purchases (IDs 101-109): Total = Rs 0
```

---

## Data Storage

### Binary File: `Memberz`

Member records are stored as raw binary structs in a flat file called `Memberz` (no extension). Each record is a direct memory dump of the `memberz` struct.

```
┌──────────────────── Memberz file ─────────────────────┐
│                                                        │
│  Record 0:  [memberid][name][age][fname][email]...     │
│  Record 1:  [memberid][name][age][fname][email]...     │
│  Record 2:  [memberid][name][age][fname][email]...     │
│  ...                                                   │
│                                                        │
│  Each record ≈ 208 bytes (sizeof(memberz))             │
│  Read/written with f.read((char*)&obj, sizeof(obj))    │
│                                                        │
└────────────────────────────────────────────────────────┘
```

### Member Record Fields

| Field        | Type      | Size    | Description                         |
|--------------|-----------|---------|-------------------------------------|
| `memberid`   | `int`     | 2 bytes | Unique member identifier            |
| `name`       | `char[]`  | 20      | Member name                         |
| `age`        | `int`     | 2 bytes | Member age                          |
| `fname`      | `char[]`  | 20      | Father's name                       |
| `email`      | `char[]`  | 25      | Email address                       |
| `possession` | `char[]`  | 20      | "Prized possession"                 |
| `heaven`     | `char[]`  | 20      | "Shopping heaven"                   |
| `shoplong`   | `int`     | 2 bytes | Days per week they shop             |
| `budget`     | `int`     | 2 bytes | Weekly shopping budget              |
| `shopfor`    | `char[]`  | 20      | What they shop for                  |
| `addr`       | `char[]`  | 70      | Address                             |
| `points`     | `int`     | 2 bytes | Loyalty points balance              |

*(int is 16-bit in Turbo C++ for DOS)*

---

## Class Hierarchy

```
    ┌──────────────────────────┐
    │         item             │
    │  (base class)            │
    ├──────────────────────────┤
    │  # name[50]     : char   │
    │  # index        : int    │
    │  # quantity     : float  │
    │  # price        : float  │
    ├──────────────────────────┤
    │  + setindex(int)         │
    │  + read(char[])          │
    │  + price1(range, base)   │
    │  + display(int)          │
    │  + retindex() : int      │
    │  + initialize(float)     │
    │  + name1(char[])         │
    │  + retprice() : float    │
    │  + retquantity() : float │
    └────────────┬─────────────┘
                 │
                 │ inherits
                 v
    ┌──────────────────────────┐       ┌─────────────────────────┐
    │         bill1            │       │       memberz           │
    │  (bill entry)            │       │  (struct, no base)      │
    ├──────────────────────────┤       ├─────────────────────────┤
    │  + input(item)           │       │  + memberid   : int     │
    │  + disp(int&)            │       │  + name[20]   : char    │
    │  + check1(bill1&)        │       │  + age        : int     │
    │    (merge duplicates)    │       │  + fname[20]  : char    │
    └──────────────────────────┘       │  + email[25]  : char    │
                                       │  + addr[70]   : char    │
                                       │  + points     : int     │
                                       │  + ...                  │
                                       │  + memberz() (ctor)     │
                                       └─────────────────────────┘
```

---

## Function Reference

| Function       | Returns | Description                                               |
|----------------|---------|-----------------------------------------------------------|
| `main()`       | `void`  | Entry point. Splash screen, loading bar, credits, main menu |
| `face()`       | `int`   | Shop selection menu. Returns 1 (go to bill) or 2 (continue) |
| `vegetables()` | `int`   | Display & sell vegetables (10 items)                       |
| `hardware()`   | `int`   | Display & sell hardware tools (7 items)                    |
| `stationary()` | `int`   | Display & sell stationery (10 items)                       |
| `cafe()`       | `int`   | Display & sell cafe items (12 items)                       |
| `books()`      | `int`   | Display & sell textbooks (10 items)                        |
| `buy()`        | `int`   | Item selection loop. Adds to global cart. Returns 1/2      |
| `bill()`       | `void`  | Member login, bill generation, tax, points, exit animation |
| `newmem()`     | `void`  | Register a new member into the `Memberz` file              |
| `info()`       | `void`  | Enter personal information for current member              |
| `modify()`     | `void`  | Modify existing member information                         |
| `offers()`     | `void`  | Redeem points or claim bonus offers                        |
| `employee()`   | `void`  | Admin panel: view, edit, delete member records             |
| `check2()`     | `void`  | Merge duplicate items in the bill array                    |

### Global State

| Variable    | Type       | Purpose                              |
|-------------|------------|--------------------------------------|
| `itm[30]`   | `bill1[]`  | Shopping cart (max 30 items)          |
| `x`         | `int`      | Current number of items in cart       |
| `mid`       | `int`      | Current member ID (0 = not logged in) |
| `offersct`  | `int`      | Number of offers claimed this session |
| `discount`  | `double`   | Discount from redeemed points         |
| `bp`        | `double`   | Bonus points to be awarded            |

---

## Known Issues

These are authentic bugs in the original code, preserved as-is:

1. **Missing `fstream` variable name** (line ~1035): `fstream ("Memberz",...)` should be `fstream f ("Memberz",...)`. The file stream is created as a temporary and `f` is referenced afterward -- this would fail at runtime.

2. **Typo in animation** (line ~1538): `stangle1+180` should be `stangle+180`. This references an undeclared variable in the credits ellipse animation.

3. **Array out-of-bounds in `cafe()`** (lines ~734-735): `things3` is declared as `item things3[10]` (indices 0-9) but indices 10 and 11 are written to and iterated over (12 items total). This is a buffer overflow.

4. **`delete obj` on stack-allocated array** (line ~561): In `buy()`, the parameter `obj[]` is a stack-allocated array passed by pointer, but `delete obj` is called on it. This is undefined behavior.

5. **Uninitialized `pos` variable**: In several functions, `pos` is used before being assigned when the first record matches the search.

---

## Screenshots (Conceptual)

Since this runs only in a DOS/BGI graphics environment, here is a text representation of what the screens look like:

### Splash Screen
```
┌──────────────────────────────────────────────────────────────────┐
│                                                                  │
│                                              ╭──╮               │
│                                             (    ) ← mascot     │
│                                              ╰──╯  (circles     │
│                                    HELLO!!!   │      + arcs)     │
│                                                                  │
│                                 WELCOME TO THE                   │
│                                                                  │
│                                   C-SHOP!!!                      │
│                                                                  │
│                                                                  │
│                                                                  │
│                                                                  │
│                                                                  │
│                                                                  │
│                                                                  │
│                                                                  │
│                                                                  │
│                  LOADING . . .  ██████████████████████  100%      │
│                                                                  │
│                  PRESS ANY KEY TO CONTINUE                        │
└──────────────────────────────────────────────────────────────────┘
```

### Shop Display
```
┌──────────────────────────────────────────────────────────────────┐
│                         Veggies                                  │
├──────────────────────────────────────────────────────────────────┤
│  Index    Name           Quantity(Kgs)    Price                  │
├──────────────────────────────────────────────────────────────────┤
│  1        Potato         1               Rs 32                  │
│  2        Onion          1               Rs 28                  │
│  3        Carrot         1               Rs 41                  │
│  4        Cabbage        1               Rs 22                  │
│  5        Spinach        1               Rs 35                  │
│  6        Ladysfinger    1               Rs 29                  │
│  7        Apple          1               Rs 38                  │
│  8        Mango          1               Rs 25                  │
│  9        Banana         1               Rs 20                  │
│  10       Orange         1               Rs 33                  │
│                                                                  │
│  What would you like to buy??                                    │
└──────────────────────────────────────────────────────────────────┘
```

---

## How to Run (Historical)

This program requires a Borland Turbo C++ 3.0 environment. It will **not** compile on modern compilers (GCC, Clang, MSVC).

### Option 1: DOSBox + Turbo C++

1. Install [DOSBox](https://www.dosbox.com/)
2. Download Turbo C++ 3.0 from [WinWorld](https://winworldpc.com/product/turbo-c/3x)
3. Mount the Turbo C++ directory in DOSBox
4. Copy `baycode.cpp` to the Turbo C++ directory
5. Open the Turbo C++ IDE and load `baycode.cpp`
6. Compile and run from the IDE (Alt+F9 to compile, Ctrl+F9 to run)
7. Ensure BGI drivers are present at `C:\TC\BGI\`

### Option 2: Original Hardware

Run on actual DOS/Windows 3.x/95 hardware with Turbo C++ installed at `C:\TC\`.

### Note

The BGI driver path is hardcoded as `c:\\tc\\bgi` throughout the source. If your Turbo C++ installation is elsewhere, you'll need to update every `initgraph()` call.

---

## Authors

- **Hariharan**
- **Abhishek**

Built under the guidance of **Mrs. Kala**.

---

## License

This project is preserved for historical and educational reference. No license is specified.

---

*This README was written in 2026 to document a project originally created circa early 2010s, targeting a compiler from 1992. The code is preserved as-is, bugs and all, as a snapshot of a specific era of C++ programming on DOS.*
