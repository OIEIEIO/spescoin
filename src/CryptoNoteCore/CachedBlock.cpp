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

#include "CachedBlock.h"
#include <Common/Varint.h>
#include "CryptoNoteConfig.h"
#include "CryptoNoteTools.h"

using namespace Crypto;
using namespace CryptoNote;

CachedBlock::CachedBlock(const BlockTemplate& block) : block(block) {
}

const BlockTemplate& CachedBlock::getBlock() const {
  return block;
}

const Crypto::Hash& CachedBlock::getTransactionTreeHash() const {
  if (!transactionTreeHash.is_initialized()) {
    std::vector<Crypto::Hash> transactionHashes;
    transactionHashes.reserve(block.transactionHashes.size() + 1);
    transactionHashes.push_back(getObjectHash(block.baseTransaction));
    transactionHashes.insert(transactionHashes.end(), block.transactionHashes.begin(), block.transactionHashes.end());
    transactionTreeHash = Crypto::Hash();
    Crypto::tree_hash(transactionHashes.data(), transactionHashes.size(), transactionTreeHash.get());
  }

  return transactionTreeHash.get();
}

const Crypto::Hash& CachedBlock::getBlockHash() const {
  if (!blockHash.is_initialized()) {
    BinaryArray blockBinaryArray = getBlockHashingBinaryArray();
    if (BLOCK_MAJOR_VERSION_2 <= block.majorVersion) {
      const auto& parentBlock = getParentBlockHashingBinaryArray(false);
      blockBinaryArray.insert(blockBinaryArray.end(), parentBlock.begin(), parentBlock.end());
    }

    blockHash = getObjectHash(blockBinaryArray);
  }

  return blockHash.get();
}

const Crypto::Hash& CachedBlock::getBlockLongHash(cn_context& cryptoContext, uint32_t variant) const {
  if (!blockLongHash.is_initialized()) {
    if (block.majorVersion == BLOCK_MAJOR_VERSION_1) {
      const auto& rawHashingBlock = getBlockHashingBinaryArray();
      blockLongHash = Hash();
      cn_slow_hash(cryptoContext, rawHashingBlock.data(), rawHashingBlock.size(), blockLongHash.get(), variant);
    } else if (block.majorVersion >= BLOCK_MAJOR_VERSION_2) {
      const auto& rawHashingBlock = getParentBlockHashingBinaryArray(true);
      blockLongHash = Hash();
      cn_slow_hash(cryptoContext, rawHashingBlock.data(), rawHashingBlock.size(), blockLongHash.get(), variant);
    } else {
      throw std::runtime_error("Unknown block major version.");
    }
  }

  return blockLongHash.get();
}

const Crypto::Hash& CachedBlock::getAuxiliaryBlockHeaderHash() const {
  if (!auxiliaryBlockHeaderHash.is_initialized()) {
    auxiliaryBlockHeaderHash = getObjectHash(getBlockHashingBinaryArray());
  }

  return auxiliaryBlockHeaderHash.get();
}

const BinaryArray& CachedBlock::getBlockHashingBinaryArray() const {
  if (!blockHashingBinaryArray.is_initialized()) {
    blockHashingBinaryArray = BinaryArray();
    auto& result = blockHashingBinaryArray.get();
    if (!toBinaryArray(static_cast<const BlockHeader&>(block), result)) {
      blockHashingBinaryArray.reset();
      throw std::runtime_error("Can't serialize BlockHeader");
    }

    const auto& treeHash = getTransactionTreeHash();
    result.insert(result.end(), treeHash.data, treeHash.data + 32);
    auto transactionCount = Common::asBinaryArray(Tools::get_varint_data(block.transactionHashes.size() + 1));
    result.insert(result.end(), transactionCount.begin(), transactionCount.end());
  }

  return blockHashingBinaryArray.get();
}

const BinaryArray& CachedBlock::getParentBlockBinaryArray(bool headerOnly) const {
  if (headerOnly) {
    if (!parentBlockBinaryArrayHeaderOnly.is_initialized()) {
      auto serializer = makeParentBlockSerializer(block, false, true);
      parentBlockBinaryArrayHeaderOnly = BinaryArray();
      if (!toBinaryArray(serializer, parentBlockBinaryArrayHeaderOnly.get())) {
        parentBlockBinaryArrayHeaderOnly.reset();
        throw std::runtime_error("Can't serialize parent block header.");
      }
    }

    return parentBlockBinaryArrayHeaderOnly.get();
  } else {
    if (!parentBlockBinaryArray.is_initialized()) {
      auto serializer = makeParentBlockSerializer(block, false, false);
      parentBlockBinaryArray = BinaryArray();
      if (!toBinaryArray(serializer, parentBlockBinaryArray.get())) {
        parentBlockBinaryArray.reset();
        throw std::runtime_error("Can't serialize parent block.");
      }
    }

    return parentBlockBinaryArray.get();
  }
}

const BinaryArray& CachedBlock::getParentBlockHashingBinaryArray(bool headerOnly) const {
  if (headerOnly) {
    if (!parentBlockHashingBinaryArrayHeaderOnly.is_initialized()) {
      auto serializer = makeParentBlockSerializer(block, true, true);
      parentBlockHashingBinaryArrayHeaderOnly = BinaryArray();
      if (!toBinaryArray(serializer, parentBlockHashingBinaryArrayHeaderOnly.get())) {
        parentBlockHashingBinaryArrayHeaderOnly.reset();
        throw std::runtime_error("Can't serialize parent block header for hashing.");
      }
    }

    return parentBlockHashingBinaryArrayHeaderOnly.get();
  } else {
    if (!parentBlockHashingBinaryArray.is_initialized()) {
      auto serializer = makeParentBlockSerializer(block, true, false);
      parentBlockHashingBinaryArray = BinaryArray();
      if (!toBinaryArray(serializer, parentBlockHashingBinaryArray.get())) {
        parentBlockHashingBinaryArray.reset();
        throw std::runtime_error("Can't serialize parent block for hashing.");
      }
    }

    return parentBlockHashingBinaryArray.get();
  }
}

uint32_t CachedBlock::getBlockIndex() const {
  if (!blockIndex.is_initialized()) {
    if (block.baseTransaction.inputs.size() != 1) {
      blockIndex = 0;
    } else {
      const auto& in = block.baseTransaction.inputs[0];
      if (in.type() != typeid(BaseInput)) {
        blockIndex = 0;
      } else {
        blockIndex = boost::get<BaseInput>(in).blockIndex;
      }
    }
  }

  return blockIndex.get();
}
