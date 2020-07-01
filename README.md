# INTRO

dll delay load example

delay load dll in subdirectory by using function `SetDllDirectory`

# BUILD

using msvc compiler with cmake, build target `deploy`

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