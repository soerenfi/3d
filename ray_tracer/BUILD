cc_library(
    name = "libraytracer",
    srcs = ["src/main.cc"],
    hdrs = glob(["src/*.h"]),
)

cc_binary(
    name = "raytracer",
    srcs = ["src/main.cc"],
    deps = [":libraytracer"],
)
