#include <stdio.h>
#include <dlfcn.h>

int main() {
  void *lib_handle;
  int (*api_function)();

  // Load the shared library
  lib_handle = dlopen("/home/hasini/Desktop/TEE/Verification/TEE/verification/formal/tdx/tdx-module-v1.0.01.01/bin/release/libtdx.so",RTLD_GLOBAL| RTLD_NOW);
  if (!lib_handle) {
    fprintf(stderr, "Error: %s\n", dlerror());
    return 1;
  }

  // Get the function pointer from the library
  api_function = dlsym(lib_handle, "test_print");
  if (!api_function) {
    fprintf(stderr, "Error: %s\n", dlerror());
    dlclose(lib_handle);
    return 1;
  }

  // Call the function from the library
  int result = api_function();
  printf("Result: %d\n", result);

  // Unload the library
  dlclose(lib_handle);

  return 0;
}