Lib to parse the string names of enums in c. This is util to take the enum names as string to be used on c code.

Example:

```c
typedef enum{
  NAME1 = 0,
  NAME2,
  NAME3 = 10,
  NAME4,
}test_e;
```

The lib_parse_enum return a list with the strings on defined enum order.
```
char **test_list = lib_parse_enum("test_e", "path of the file .c or .h")

test_list[0] : Return the string "NAME1"

test_list[1] : Return the string "NAME2"

test_list[3] : Return the string ""

test_list[10] : Return the string "Name3"

test_list[11] : Return the string "Name4"
```

To run the example:

1. Create a build directory:
    ```bash
    mkdir build
    ```

2. Change to the newly created directory:
    ```bash
    cd build
    ```

3. Configure CMake:
    ```bash
    cmake ..
    ```

4. Build the project:
    ```bash
    make
    ```

5. Run the `test_parse_enum`:
    ```bash
    ./test_parse_enum
    ```

