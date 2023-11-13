#!/bin/bash -exu
set -o pipefail
# unset the toolchain env to avoid the chicken-egg problem...
unset GOROOT

mkdir -p .devcontainer/toolchain

GOROOT=$(bazel run \
    --ui_event_filters=-info,-stdout,-stderr \
    --noshow_progress \
    @go_sdk//:bin/go \
    -- env GOROOT)
ln -fs $GOROOT .devcontainer/toolchain
echo -n 'export PATH=$GOROOT/bin:$PATH' >> $HOME/.zshrc
