// Copyright (c) 2012-2018, The CryptoNote developers, The Bytecoin developers, SpesCoin dev's
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// SpesCoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with SpesCoin.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <cstddef>
#include <cstdint>

namespace CryptoNote {
class ICryptoNoteProtocolObserver;

class ICryptoNoteProtocolQuery {
public:
  virtual bool addObserver(ICryptoNoteProtocolObserver* observer) = 0;
  virtual bool removeObserver(ICryptoNoteProtocolObserver* observer) = 0;

  virtual uint32_t getObservedHeight() const = 0;
  virtual size_t getPeerCount() const = 0;
  virtual bool isSynchronized() const = 0;
};

} //namespace CryptoNote
