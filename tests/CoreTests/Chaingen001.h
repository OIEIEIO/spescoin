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
#include "Chaingen.h"

class gen_simple_chain_001: public test_chain_unit_base 
{
public: 
  gen_simple_chain_001();
  bool generate(std::vector<test_event_entry> &events);
  bool verify_callback_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool verify_callback_2(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
};

class one_block: public test_chain_unit_base
{
  CryptoNote::AccountBase alice;
public:
  one_block();
  bool generate(std::vector<test_event_entry> &events);
  bool verify_1(CryptoNote::Core& c, size_t ev_index, const std::vector<test_event_entry> &events);
};
