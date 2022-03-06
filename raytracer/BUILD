
## Replace workspace_name and dir_path as per your setup.
load("@com_grail_bazel_compdb//:defs.bzl", "compilation_database")
load("@com_grail_bazel_output_base_util//:defs.bzl", "OUTPUT_BASE")


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

compilation_database(
    name = "compdb",
    targets = [
        ":raytracer",
    ],
    output_base = OUTPUT_BASE,
)
