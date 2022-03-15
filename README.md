
# ServedSpicy Serial Library

This is the shared library used by the webserver <br>
of the **ServedSpicy** configurator to send serial <br>
data to the machine controller.

## Requirements

To compile the library / test binaries you will need **GCC**.

This library uses `libserial`.

```sh
sudo apt install libserial-dev
```

## Building

The library can be build by executing [`Build`][Script Build].

1. Open a terminal in the projects root directory.

2. Start building with:

    ```sh
    Tools/Build
    ```

## Testing

### C++

Execute the **[C++][Script C++]** test script by:

1. Connecting an `Arduino UNO`.

2. Opening a terminal in the projects root directory.

3. Start the test with:

    ```sh
    Tools/C++
    ```

### Deno

Execute the **[Deno][Script Deno]** integration test script by:

1. Connecting an `Arduino UNO`.

2. Opening a terminal in the projects root directory.

3. Start the test with:

    ```sh
    Tools/Deno
    ```


[Script Build]: ./Tools/Build
[Script C++]: ./Tools/C++
[Script Deno]: ./Tools/Deno
