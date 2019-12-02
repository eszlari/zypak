// Copyright 2019 Endless Mobile, Inc.
// Portions copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "base/base.h"
#include "base/unique_fd.h"

#include <optional>
#include <sys/types.h>
#include <vector>

#include <nickle.h>

std::optional<pid_t> HandleFork(nickle::Reader* reader, std::vector<unique_fd> fds);