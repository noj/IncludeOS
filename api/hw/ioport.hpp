// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef HW_IOPORT_HPP
#define HW_IOPORT_HPP

#include <common>
#include <arch.hpp>

namespace hw {

  /** Receive a byte from port.
      @param port : The port number to receive from
  */
  static inline uint8_t inb(int port)
  {
    int ret;
#if defined(ARCH_x86)
    asm volatile ("xorl %eax,%eax");
    asm volatile ("inb %%dx,%%al":"=a" (ret):"d"(port));
#else
#error "inb() not implemented for selected arch"
#endif
    return ret;
  }

  /** Send a byte to port.
      @param port : The port to send to
      @param data : One byte of data to send to @param port
  */
  static inline void outb(int port, uint8_t data) {
#if defined(ARCH_x86)
    asm volatile ("outb %%al,%%dx"::"a" (data), "d"(port));
#else
#error "outb() not implemented for selected arch"
#endif
  }

  /** Receive a word from port.
      @param port : The port number to receive from
  */
  static inline uint16_t inw(int port)
  {
    int ret;
#if defined(ARCH_x86)
    asm volatile ("xorl %eax,%eax");
    asm volatile ("inw %%dx,%%ax":"=a" (ret):"d"(port));
#else
#error "inw() not implemented for selected arch"
#endif
    return ret;
  }

  /** Send a word to port.
      @param port : The port to send to
      @param data : One word of data to send to @param port
  */
  static inline void outw(int port, uint16_t data) {
#if defined(ARCH_x86)
    asm volatile ("outw %%ax,%%dx"::"a" (data), "d"(port));
#else
#error "outw() not implemented for selected arch"
#endif
  }

  /** Receive a double-word from port.
      @param port : The port number to receive from
  */
  static inline uint32_t inl(int port)
  {
    uint32_t ret;
#if defined(ARCH_x86)
    //asm volatile ("xorl %eax,%eax");
    asm volatile ("inl %%dx,%%eax":"=a" (ret):"d"(port));
#else
#error "inw() not implemented for selected arch"
#endif
    return ret;
  }

  /** Send a double-word to port.
      @param port : The port to send to
      @param data : Double-word of data
  */
  static inline void outl(int port, uint32_t data) {
#if defined(ARCH_x86)
    asm volatile ("outl %%eax,%%dx"::"a" (data), "d"(port));
#else
#error "outw() not implemented for selected arch"
#endif
  }

} //< namespace hw

#endif // HW_IOPORT_HPP
