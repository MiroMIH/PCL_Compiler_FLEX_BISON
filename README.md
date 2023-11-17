# PCL Compiler

## Overview

This repository contains the source code for a mini-compiler designed to process the PCL (Programming Compilation Language) using FLEX and BISON. The compiler undergoes various stages of compilation, including lexical analysis, syntax-semantic analysis, intermediate code generation, optimization, and ultimately produces 8086 assembly language code.

## Project Structure

### 1. Lexical Analysis with FLEX

The `lexical_analysis` directory houses the FLEX specifications for the lexical analysis phase. Files in this directory define the regular expressions and corresponding actions to tokenize PCL source code.

### 2. Syntax-Semantic Analysis with BISON

The `syntax_semantic_analysis` directory contains the BISON specifications for the syntax-semantic analysis phase. Here, the grammar rules and semantic actions are defined to create a parse tree and perform semantic analysis.

### 3. Intermediate Code Generation

The `intermediate_code_generation` directory is responsible for generating intermediate code from the parsed syntax tree. Quadruplets are produced, forming the basis for subsequent optimization steps.

### 4. Optimization

The `optimization` directory encompasses various optimization techniques applied to the intermediate code. These include copy propagation, expression propagation, redundancy elimination, algebraic simplification, and dead code elimination.

### 5. 8086 Assembly Code Generation

The `assembly_code_generation` directory focuses on converting the optimized intermediate code into 8086 assembly language code. This step is crucial for the final executable output.

### 6. Error Handling

The `error_handling` directory manages the detection and reporting of errors at different stages of compilation. Detailed error messages, including the type of error, line number, column number, and the entity causing the error, are provided.

### 7. Symbol Table Management

Symbol table management, crucial for tracking variables and constants throughout compilation, is implemented in the `symbol_table` directory. This includes parallel processing for efficient handling.

## Language Specifications

The PCL language follows a specific syntax and semantics outlined in the project's documentation. The language supports variable declarations, arrays, data structures, constants, arithmetic, logical and comparison operators, conditions, loops, and more.



Happy coding!
