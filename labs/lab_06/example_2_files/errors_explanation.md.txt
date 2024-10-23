Step 4.
	The error undefined reference to `hello(int)` occurs because:
		- In 'main.cpp', the function 'hello' is declared but not defined. The compiler expects to find the implementation when it tries to link the program.
		- In 'f.cpp', the function 'hello' is only declared, and there's no corresponding definition provided, resulting in the linker being unable to resolve the reference to 'hello' used in 'main.cpp'.
Step 6.
	The error undefined reference to `hello(int)` occurs because 'main.cpp' contains a call to the 'hello' function but does not have a definition for it. The linker can't resolve the reference.
Step 8.
	The error undefined reference to `hello(int)` occurs because the 'static' keyword restricts the visibility of the 'hello' function to the 'f.cpp' file only. Therefore, when 'main.cpp' tries to link to the 'hello' function, it cannot find it since the 'hello' function is not visible outside 'f.cpp'.
Step 10.
	This works because the 'hello' function is now defined within 'main.cpp', and it's marked as 'static', which means it can be called only within 'main.cpp'. There are no unresolved references, so the compilation succeeds.
Step 11.
	If you were to compile both 'main.cpp' and 'f.cpp' with the 'hello' function defined as 'static' in both files:
		- Each file will have its own copy of the 'hello' function because 'static' functions have internal linkage. This means that even though both files have a function named 'hello', they are considered separate functions by the linker.
		- Therefore, you would end up with two separate copies of the 'hello' function in the final executable if both files were compiled together.