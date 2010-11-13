// Copyright 2010 Google Inc.
// Modified by Yuji Kaneda
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//      http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// ------------------------------------------------------------------------

// Include either tr1/unordered_map.h or ext/hash_map.h
// and create a derived class so we can specialize its hash function.

#ifndef _UTILITIES_HASH_MAP_
#define _UTILITIES_HASH_MAP_

//#include "config.h"

/* the name of <hash_set> */
#define HASH_MAP_CLASS unordered_map

/* the location of <hash_map> */
#define HASH_MAP_H <tr1/unordered_map>

/* the namespace of hash_map/hash_set */
#define HASH_NAMESPACE std::tr1

/* define if the compiler has hash_map */
#define HAVE_HASH_MAP 1

#ifdef HASH_MAP_H
#include HASH_MAP_H
#else
#error Configuration problem, HASH_MAP_H not defined; wrong config.h included?
#endif



namespace SzlHash {


#ifndef _UTILITIES_HASH_SET_
template <typename Key>
struct hash : HASH_NAMESPACE::hash<Key> {
};
#endif


template <typename Key, typename Data,
          typename HashFcn = hash<Key>,
          typename EqualKey = std::equal_to<Key> >
struct hash_map : HASH_NAMESPACE::HASH_MAP_CLASS<Key, Data, HashFcn, EqualKey> {
  typedef HASH_NAMESPACE::HASH_MAP_CLASS<Key, Data, HashFcn, EqualKey> Super;
  hash_map() { }
  hash_map(int n) : Super(n) { }
};


}  // namespace SzlHash


using SzlHash::hash_map;


#endif  //  _UTILITIES_HASH_MAP_