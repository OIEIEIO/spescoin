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
#include <limits>

namespace CryptoNote {
namespace parameters {

const uint32_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 155;
const uint32_t CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW         = 12;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// MONEY_SUPPLY - total number coins to be generated
const uint64_t MONEY_SUPPLY                                  = UINT64_C(18446744073709551615);
const size_t MIN_MIXIN                          = 0;
const uint8_t MANDATORY_MIXIN_BLOCK_VERSION     = 0;
const uint32_t MIXIN_START_HEIGHT                          = 0;
const uint32_t MANDATORY_TRANSACTION                          = 0;
const uint32_t KILL_HEIGHT                          = 0;
const uint64_t TAIL_EMISSION_REWARD                          = 0;
const size_t CRYPTONOTE_COIN_VERSION                          = 0;
const uint32_t ZAWY_DIFFICULTY_BLOCK_INDEX                 = 30;
const uint8_t ZAWY_DIFFICULTY_DIFFICULTY_BLOCK_VERSION   = 3;
const uint32_t ZAWY_DIFFICULTY_LAST_BLOCK                 = 0;
const uint64_t ZAWY_DIFFICULTY_MIN                 = 0;
const uint32_t ZAWY_LWMA_DIFFICULTY_BLOCK_INDEX                 = 0;
const uint32_t ZAWY_LWMA_DIFFICULTY_LAST_BLOCK                 = 0;
const uint64_t ZAWY_LWMA_DIFFICULTY_MIN                 = 0;
const size_t ZAWY_LWMA_DIFFICULTY_N                 = 0;
const uint32_t ZAWY_LWMA2_DIFFICULTY_BLOCK_INDEX                 = 0;
const uint32_t ZAWY_LWMA2_DIFFICULTY_LAST_BLOCK                 = 0;
const uint64_t ZAWY_LWMA2_DIFFICULTY_MIN                 = 0;
const size_t ZAWY_LWMA2_DIFFICULTY_N                 = 0;
const uint32_t BUGGED_ZAWY_DIFFICULTY_BLOCK_INDEX                 = 0;
const uint32_t POW_CRYPTONIGHT_V7_BLOCK_INDEX                 = 0;
const uint32_t POW_CRYPTONIGHT_V7_LAST_BLOCK                 = 0;
//const uint32_t POW_CRYPTONIGHT_V7_BLOCK_INDEX                 = 215700;
//const uint32_t POW_CRYPTONIGHT_V7_LAST_BLOCK                 = UINT32_MAX;
const unsigned EMISSION_SPEED_FACTOR                         = 25;
const uint64_t GENESIS_BLOCK_REWARD                          = UINT64_C(1844674407370955300);
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2  = 20000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1  = 10000;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 10;
const uint64_t MINIMUM_FEE                                   = UINT64_C(1000000);
const uint64_t DEFAULT_DUST_THRESHOLD                        = UINT64_C(1000000);
const uint64_t MAX_TRANSACTION_SIZE_LIMIT                          = 250000;
const uint64_t DEFAULT_FEE                          = MINIMUM_FEE;

const uint64_t DIFFICULTY_TARGET                             = 100; // seconds
const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;
const size_t   DIFFICULTY_WINDOW                                = 17;
const size_t   DIFFICULTY_WINDOW_V1                          = 864;
const size_t   DIFFICULTY_WINDOW_V2                          = 864;
const size_t   DIFFICULTY_CUT                                = 0;  // timestamps to cut after sorting
const size_t   DIFFICULTY_CUT_V1                             = 60;
const size_t   DIFFICULTY_CUT_V2                             = 60;
const size_t   DIFFICULTY_LAG                                = 0;  // !!!
const size_t   DIFFICULTY_LAG_V1                             = 15;
const size_t   DIFFICULTY_LAG_V2                             = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        = 100000;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX                = 0;
const uint32_t UPGRADE_HEIGHT_V2                                = 1;
const uint32_t UPGRADE_HEIGHT_V3                                = 30;
const unsigned UPGRADE_VOTING_THRESHOLD                      = 90;               // percent
const uint32_t UPGRADE_VOTING_WINDOW                         = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
const uint32_t UPGRADE_WINDOW                                = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY;  // blocks
static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.bin";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.bin";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

const char     CRYPTONOTE_NAME[]                             = "spescoin";

const uint8_t  TRANSACTION_VERSION_1                         =  1;
const uint8_t  TRANSACTION_VERSION_2                         =  2;
const uint8_t  CURRENT_TRANSACTION_VERSION                   =  TRANSACTION_VERSION_1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MAJOR_VERSION_2                         =  2;
const uint8_t  BLOCK_MAJOR_VERSION_3                         =  3;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;
const uint8_t  BLOCK_MINOR_VERSION_1                         =  1;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  500000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  4500;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  50000;

const int      P2P_DEFAULT_PORT                              =  55491;
const int      RPC_DEFAULT_PORT                              =  55490;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  50;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 256 * 1024 * 1024; // 256 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 32;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 1000000000;      // 100000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 450;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds

const uint32_t  P2P_FAILED_ADDR_FORGET_SECONDS                  = (60*60);     //1 hour
const uint32_t  P2P_IP_BLOCKTIME                                 = (60*60*24);  //24 hour
const uint32_t  P2P_IP_FAILS_BEFORE_BLOCK                       = 10;
const uint32_t  P2P_IDLE_CONNECTION_KILL_INTERVAL               = (5*60); //5 minutes

const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "";

const char* const SEED_NODES[] = { "68.183.124.243:55491", "165.22.243.173:55491" };


struct CheckpointData {
  uint32_t index;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
  {3000,  "bc93ec52e9b79b4bd31da53f5eda21671bdc941b781cb04228a5b6c350c1b426"},
  {4001,  "56ffc69f7c6104a5a3c39fbfefc6fced45762271826caa7b191bbf4e4f5f8113"},
  {5002,  "58fb8b7e83df11b6a18f50a5a7e72d1f3531dfe4695d528c7600cb6abd067204"},
  {7003, "bf4696573ae9aacf9291a47648588cdfc9a7ae9258b85d4867de25b52b663520"},
  {10100, "163bc1f4fc8d2cd8913c3ed2244107dc612e286a42e41cbd02a177890d0da423"},
  {13201, "deb31f67f3f3d794c3e78dae422a7cd901365d9f8cb307c2a4b28506e70deb20"},
  {15520, "5b6c69387e9263473706da792dad2c0414178a5ecb107885f481b25f31b6def5"},
  {17805, "f93c268272998b8280a73836e7ca403b1abbf8d74e20f67dcbfa3f710124c8bb"},
  {20500, "06444ec5de10f3b480b9c9d8b7df6c39511ae5d7ad8d9199d09cf34cdc5e94cd"},
  {23790, "d57ebf436698784ef1cd71cc167e7d40a662c86fac009ea98046be8373d28f76"},
  {26900, "1b59645aa6cd1babb4346664cdf85ef554bf9373c6515b3303a3589190ae4fef"},
  {29899, "088d2f2f6303dea26f47b91d8b32a33ff7e8475a71cabdf49b88c155a222126b"},
  {30010, "e7490343c5ff621474f0be995965b5f7167a433842311234ee16489b279a0dfe"},
  {32900, "d709860d1735532112fe49c3fb622570644dcbcf55b1bc309f6afefd05bb8664"},
  {36000, "a7725eae3e4a71048062d2e8a077cee53ad622bcfba52c8f7cc3f2710902212f"},
  {38900, "31cfda5c98005c2032886b5a12bbb94fcd3804c95c1ddcd5f52600551f1a05c3"},
  {40000, "0a48a24f6585b8706e455af602e84ac17722998ac23a5531fcf352acfcffc34e"},
  {42500, "a5bb462ee8f8c25f8c3fe8e9dfdec1093e5ff4baa7f5f75ab35c68b08b53c01a"},
  {45000, "dd33b8ab7bdae4ba8e0a2b11c0ffc406ebeefedfd0f72a18912fd3ad59d723aa"},
  {48500, "6a95cd7ebc8fd55232a9396e83f08f4bb3157ca0e1475059a0b1e92d3db0c941"},
  {50250, "795c0b82596e525e6a35d039f26e0868110d4f61f27988fbea40b34083e2f7b4"},
  {54900, "7f59c5cac4d722beeda276e9b0b058877ac537673ed5e157693ebd6d66fc8172"},
  {58712, "9d17dd12c9c04314f382b6bdbac7b0e5c2e07c9ef6d32b4003e2c2aa6251f788"},
  {61200, "c2440aaeaa102b7813e3ede43bdaf161de03929247de6647c217d1d556ac9af0"},
  {65000, "b45cdca8ee6e78e726f0edb611719e8f97edab546f144eaba1df0eb2e49cf095"},
  {68900, "251a291f7d7172495e985af2a47c3e8407c3b2af8d0221bda5243fe22b6090e3"},
  {72130, "0c51ffe2395a0057f935ee5414dd07de68f9fee7c1325df6e33601a39a3f0ae7"},
  {75000, "0da2b2579760144af24c336bbef037e66625972f2672931d6f30c3ba17847ffe"},
  {79000, "961ea97e0def907752da97c32cb20a3f097a05384a7caebe36c2c5034495e177"},
  {83500, "efa985456ef9a32bc0ada888177aefca8f40c721179a1054fe5a582758c65371"},
  {86700, "a265bf06003f462d4e2373104a978f4a4e68774a9fb569ef95ed0f7f48ae6c2c"},
  {89690, "f8a9117bb0e466a56d608aec2d5f598534ff50725bab68e9bba9550f3bebb104"},
  {93500, "77419ba9e43d8fd87dddeccdcd4b5a980643ad8ba4862a87c2128bec365e8116"},
  {96890, "a85dda2cf098feed65cce77aadc307fb0790e3c417048d981f53565d7121b2e5"},
  {100000, "2048c6e582c5a8cf8971eb2b7af6f58b5a9c63166ba0e6d9ba9220f9e2c91ed4"},
  {102900, "a84137f6ae1623989e3e7599edeec5b8906668340c70ca032aded66a26295c82"},
  {106900, "c41e1d121630dccde6ed6ec9f4b29ec9786c405c5ebb4d2dc6d0a6c411f87d63"},
  {113980, "1cae7ed76aeed29815d6541e39b7846313a0cdda268dc939fea3e61c4ee18515"},
  {120000, "78d8f79edbdb7a54c0b4d0d88ad0add2b3f4d69fbc0ab32886863c64cb98627e"},
  {125000, "a1af3a446b4781521a95049c9bd64f35cd791d333773cc9c8ad39d4d526cc658"},
  {135000, "c8f0a42b3dd92c23cda8531fdc0fb1cbd12368360db476271a680d6bbceaad88"},
  {145000, "5be94c387c17b68bded094d4ad9893c6f788c967d0292a5ce702e33c0529805b"},
  {150000, "2af53cdd7caa6aa1450a754d27b3c9bb59ea0c5239c9557d18314833d437b237"},
  {155000, "289676e57f4c7e25f665ed293b3e2d14bbcb89e9dc0f328ddd15ae78677ed09f"},
  {158000, "1e985f7adcf3b918da6abf57ed64be577ee03fc2adf4e5aed186415df35fe421"},
  {163500, "cd9f8a6c09fc575bf105eb02cb9de6682b6a90e909ec841f3ae58823454044d6"},
  {165100, "703812c10d854aeb5dec519b1b47245a8a573f03748af4be19e09086cb566015"},
  {166900, "93194e82cd0333ec64ca445fe238c9c62ef8db022040887ae70885d056fc68ee"},
  {168000, "018a64513a53e912f51c1d2502ea1ea7f1f31daece91e2b79fcd3dde4b12ff8b"},
  {169000, "af255a48b858aee2663b5377d429783ce6dee1583e091f58a540a8c25cb6b5ed"},
  {169500, "efc07bfca901fd6b157fdd0fdbede38ac572041885919cb8eb6ad7e717858adf"},
  {170000, "18babfd40798ec0af838f88537df34d006e020136b827ee368839c1036d8b526"},
  {170086, "a437d984a50148b72106ea7e17dfbe2a9bef40abf92d5330bb69df46a6b5b5c5"},
  {170460, "fa3ea5eb3f9d40223ed2029fcbd3b55984b062eee94e0603d1dccc79c2ada96a"},
  {170901, "8acdd7f9cf088eabf8fab461bbd6ff41539cdc37ae6781b95edec705077b6cec"},
  {171400, "65aa476aea075937e64e104e1c3bccba3151bfd88bf6be68e847831668459903"},
  {172000, "c5107021ce92df358d0d23aa2b09708d688d22b4777e1131b37552fd2b41ef2e"},
  {172500, "7b18a3347f7603ed64d4c4d738c91e78bb283f731e319e5e6c7e3c8b88cb4965"},
  {173000, "957ed92b4d9b3a618c9cfeeae6308bd5826005876a4464576d2e8b880a0b0303"},
  {173500, "cf6d400fe72e10114b6e3c1124d7c2fea70a72c918d178afb21e9341ff5a820d"},
  {174000, "56aefd67c653f6aeb41f8e6347e37ee82dd2f8e85cae1458a4ced402fdb05605"},
  {174500, "197e2c6b03bd15454a0a61a9aa453a4456770a1f27a4098b10f4dcbb1af0b825"},
  {175000, "4e89f860e65b9b1a0237b0c2009bf6cadd55d9364b40dc7e42f617d3a24e2d91"},
  {176000, "e7817102c712cb494c25193c24dedbf7cf29a87b86a17f624913d5ae8be7795c"},
  {178000, "82942778cf9c0e13d34ce1b71ed6c8918c8d82f4049c47643d89c23d978563ba"},
  {180000, "aeded1d9f6859e9c01dca7da7537a9446d7e0e26af33658c2b32060f38f19054"},
  {182000, "1d39a0a46f82089ef08c0a7060c5a7cf0535eed4faa8d57ec830f8edb9459ea8"},
  {186000, "2e0dc4e83c63070ec77ad8fc1095522f4161fdb5a154893b76b1403bc0f908fa"},
  {189000, "af09d6f90617b7b5bd6b94a925ce2498654cded79efb3698de7bb1ad5c37273b"},
  {195000, "b9874b968fffbe8fcaf63e5f766a4853fc7bb47eda9cf5a9c387bf1d80eabf61"},
  {200000, "4b371cd2a81bbf4a313910c14e0a92c16526b0058adc10a0739c1ad5e237fa22"},
  {210000, "cba14a23edd6f688a086dc3d06b18704bb7435aef9b0bdd76339d68b13066b4c"},
  {220000, "763d0393874a9a977dae81eca940ef6ef3eb08232696826def49ad4fbaa96820"},
  {230000, "da5b4c94206a5968da765ea1d550caa215af5c34cecb3dd6513f5ee352c3866d"},
  {240000, "6a95f2251caf48e8d56d1037d2710e13def3d31b66d199bb55bb06f648089214"},
  {250000, "2f32a2613721493d5a0f06020ee3e4e7270864cdaace3585521b7626be6da982"},
  {270000, "ab566451ca48808779a74259b9a2598c006e050d70d655aca6a7fbf02d3f007d"},
  {290000, "33793b9db3586539270d243466287f2bdbd87c9f285da47fee38e53e0f7bab86"},
  {300000, "c92fa1020cb57ecd1191f79f7c1c046a84b33eb72350a3c424da19c88389de9c"},
  {320000, "52cbf436e3ddc190fc7d25a47fd1d66c6768f6be3b72c26f4aa7d6cdd8b2abdb"},
  {340000, "64c9e6afb820c260937e47090b55a1ca4cf2cb719d2b4619c1697d4ac2987594"},
  {360000, "324edd6cceaa1e8e1f572d1b096c08161162b1235b3ec9d5d3115bffaab2dd98"},
  {370100, "88ed50b79d6f2f786902f4cbde4e4ccda7b25df9388a2764408ff8b12471ccc1"},
  };

} // CryptoNote

#define ALLOW_DEBUG_COMMANDS



