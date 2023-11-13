load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
load("@bazel_gazelle//:def.bzl", "gazelle")

buildifier(
    name = "buildifier",
)

# gazelle:prefix github.com/junlong-gao/recreations
gazelle(name = "gazelle")

gazelle(
    name = "gazelle-update-repos",
    args = [
        "-from_file=go.mod",
        "-to_macro=deps.bzl%go_dependencies",
        "-prune",
        "-build_file_proto_mode=disable_global",
    ],
    command = "update-repos",
)
