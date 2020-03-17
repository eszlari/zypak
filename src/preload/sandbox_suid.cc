// Copyright 2019 Endless Mobile, Inc.
// Portions copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/base.h"
#include "declare_override.h"
#include "sandbox_path.h"

#include <sys/stat.h>

// Pretend that chrome-sandbox is a setuid binary.

DECLARE_OVERRIDE(int, __xstat64, int ver, const char* path, struct stat64* buf) {
  auto original = LoadOriginal();

  int result = original(ver, path, buf);
  if (SandboxPath::instance()->sandbox_path().empty() && SandboxPath::LooksLikeSandboxPath(path)) {
    buf->st_uid = 0;
    buf->st_mode |= S_ISUID;

    SandboxPath::instance()->set_sandbox_path(path);
  }

  return result;
}
