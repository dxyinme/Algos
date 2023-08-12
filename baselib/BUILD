cc_library(
  name = "baselib",
  srcs = [],
  hdrs = [
    "log.hpp",
    "minitest.hpp",
    "baselib.hpp",
    "minibench.hpp",
  ],
  visibility = ["//visibility:public"]
)

cc_binary(
  name = "log_test",
  srcs = [
    "log_test.cc",
  ],
  deps = [
    ":baselib"
  ]
)