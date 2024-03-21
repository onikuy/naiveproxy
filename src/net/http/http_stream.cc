// Copyright 2023 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/http/http_stream.h"

namespace net {

std::optional<quic::QuicErrorCode> HttpStream::GetQuicErrorCode() const {
  return std::nullopt;
}

std::optional<quic::QuicRstStreamErrorCode>
HttpStream::GetQuicRstStreamErrorCode() const {
  return std::nullopt;
}

}  // namespace net
