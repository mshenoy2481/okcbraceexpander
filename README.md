# okcbraceexpander
Bash brace expander

How to use:
1. Unzip the repo or clone it from https://github.com/mshenoy2481/okcbraceexpander
2. cd to okcbraceexpander
3. Run `make -f okc.mk`
    * To clean the task/objs, run `make -f okc.mk clean`
    * The default compiler is CXX. You can override the compiler using `export COMPILER={Compiler-name}`
4. Check if the task `okc_be.tsk` is built under the current directory (okcbraceexpander)
5. Run `python test_cases.py` to run all the test cases.
    * The script is simple, so should work with any version of python.
6. Alternatively, you can run `./okc_be.tsk`. This will present a prompt on which you can enter an expression to test it.