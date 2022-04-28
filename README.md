# Europe, "The Final Countdown", YouTube, https://youtu.be/9jK-NcRmVcw

This program will require you to implement two classes and pass the test cases.

## Requirements
- In the file `CMakeLists.txt`, substitute your WSUID for the placeholder in the following line:
`set(wsuid a222a222)`
- Fill out the comment blocks in `src/Shelf.cpp` and `src/Book.cpp`.
- You will implement the `Shelf` class in `src/Shelf.cpp`. See `include/Shelf.hpp` for the required
functions.
- You will implement the `Book` class in `src/Book.cpp`. See `include/Book.hpp` for the required
functions.
- The program takes no input.
- You may declare any extra class member data or functions that you want/need.
- **REMINDER:** This is an exam. All questions should be directed to the GTA or myself.

## Sample Run
```
❯ ./build/a222a222_final
===============================================================================
All tests passed (41 assertions in 2 test cases)
```

## Hints
- This project is set up to get a little closer to what a larger C++ project could look like.
    - But just a little.
    - Don't let the layout spook you.
- As far as the code you need to write, there are no surprises.
- To compile your code, you'll need cmake, which is provided in the container.
    - Instructions to build your code in CLI
        - Navigate to the root of your repository
        - `cmake -S . -B build`
            - This will tell cmake to create a directory called build and place its configuration
            and generated files there.
            - This step scans the system for the appropriate tools and builds a script that contains
            the instructions to build your program. It will likely be a ninja.build, which uses the
            tool ninja. Typically, you'd get a makefile, that uses the tool make, but the container
            is configured to use ninja by default (Recall that the container uses my personal setup).
            - cmake can generate VS solutions, or XCode projects as well. It's all system-dependent.
            - To better match the GitHub pull request, the command used there is:
            `cmake -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_CXX_FLAGS="-Wall -Wextra -std=c++17" -S . -B build`
                - This command will work in the container, it's less likely to work if you set up
                something different. In that case, use the first command.
        - `cmake --build build`
            - This tells cmake to actually compile your project.
            - This is the only command you need to run to re-compile.
        - Your binary executable should be in the `build` directory.
    - Instructions to build your code in VS Code
        - Ensure that VS Code is in the container.
        - Once the container is set up, you should get drop-down at the top of the window asking you
        to choose a kit.
            - Choose the Clang kit.
            - If you accidentally click away the drop-down, you can choose the kit from the bottom
            bar.
        - Simply click the 'Build' button on the bottom bar to compile your code.
            - Your binary executable should be in the `build-vscode` directory.

## Reminders
- There are no late submissions for the exam.
- Remember to fill out the comment blocks in `Book.cpp` & `Shelf.cpp`.
- Remember to substitute your WSUID in `CMakeLists.txt`.
- After pushing your code, do check the details of pull request.
