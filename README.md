Inmstructions: Each algorithm is in separate branches. The randomised algorithm is in the branch, Gordon while the deterministic algorithm is in the branch, Dylan. As the name of the branches implies, Gordon wrote the randomised algorithm while Dylan wrote the deterministic algorithm.

The project can be opened with visual studio community 2022 via the .sln file. The C++ standard used has to be C++17 or newer in order for gtest to function.

The terminal is not used to run the code, rather the IDE's run button is used.

If Dylan's Testing it may be because it was setup using VS Insider (2026), make sure:
- Solution's Platform Toolset is not below Visual Studio 2022 (v143)
- Solution's C++ Language Standard is ISO C++ 17 (should work), though I set it up to use C++ 20
<img width="791" height="500" alt="image" src="https://github.com/user-attachments/assets/6e0f3eeb-bd1f-427f-8fb1-4ea44db6932f" />

- test.cpp file uses C++ Language Standard ISO C++ 17 or higher, though I set it up to use C++ 20

<img width="799" height="542" alt="image" src="https://github.com/user-attachments/assets/941499fe-414d-4ad9-9a1d-d180ab141811" />
