// Copyright 2019 Endless Mobile, Inc.
// Portions copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#pragma once

#include "base/base.h"

#include <optional>

class Env {
public:
  // Get the requested environment variable, returning an empty optional on failure.
  static std::optional<std::string_view> Get(std::string_view name);
  // Get the requested environment variable, aborting on failure.
  static std::string_view Require(std::string_view name);
  // Sets the given environment variable.
  static void Set(std::string_view name, std::string_view value, bool overwrite = true);

  static constexpr std::string_view kZypakBin = "ZYPAK_BIN";
  static constexpr std::string_view kZypakLib = "ZYPAK_LIB";
};