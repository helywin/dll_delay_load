# INTRO

dll delay load example

delay load dll in subdirectory by using function `SetDllDirectory`

# BUILD

run `x64 Native Tools Command Prompt for VS 201x` in start menu to setup msvc compiler environment

cd to project dir

run these commands:

```batch
md build
cd build
cmake .. -G"Ninja"
ninja deploy
```

# RESULT

ordinary result:

```
MyDll DLL_PROCESS_ATTACH
press ENTER to continue...

begin
MyDll constructor
new
MyDll func
end
MyDll DLL_PROCESS_DETACH
```

delay load result:

```
press ENTER to continue...

begin
MyDll DLL_PROCESS_ATTACH
MyDll constructor
new
MyDll func
end
MyDll DLL_PROCESS_DETACH
```