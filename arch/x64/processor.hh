#ifndef ARCH_X86_PROCESSOR_H
#define ARCH_X86_PROCESSOR_H

#include <stdint.h>

namespace processor {
    namespace x86 {

	typedef unsigned long ulong;
	typedef uint8_t u8;
	typedef uint16_t u16;
	typedef uint32_t u32;
	typedef uint64_t u64;

	inline ulong read_cr0() {
	    ulong r;
	    asm volatile ("mov %%cr0, %0" : "=r"(r));
	    return r;
	}

	inline void write_cr0(ulong r) {
	    asm volatile ("mov %0, %%cr0" : : "r"(r));
	}

	inline ulong read_cr2() {
	    ulong r;
	    asm volatile ("mov %%cr2, %0" : "=r"(r));
	    return r;
	}

	inline void write_cr2(ulong r) {
	    asm volatile ("mov %0, %%cr2" : : "r"(r));
	}

	inline ulong read_cr3() {
	    ulong r;
	    asm volatile ("mov %%cr3, %0" : "=r"(r));
	    return r;
	}

	inline void write_cr3(ulong r) {
	    asm volatile ("mov %0, %%cr3" : : "r"(r));
	}

	inline ulong read_cr4() {
	    ulong r;
	    asm volatile ("mov %%cr4, %0" : "=r"(r));
	    return r;
	}

	inline void write_cr4(ulong r) {
	    asm volatile ("mov %0, %%cr4" : : "r"(r));
	}

	inline ulong read_cr8() {
	    ulong r;
	    asm volatile ("mov %%cr8, %0" : "=r"(r));
	    return r;
	}

	inline void write_cr8(ulong r) {
	    asm volatile ("mov %0, %%cr8" : : "r"(r));
	}

	struct desc_ptr __attribute__((packed)) {
	    desc_ptr(u16 limit, ulong addr) : limit(limit), addr(addr) {}
	    u16 limit;
	    ulong addr;
	};

	inline void lgdt(const desc_ptr& ptr) {
	    asm volatile ("lgdt %0" : : "m"(ptr));
	}

	inline void sgdt(desc_ptr& ptr) {
	    asm volatile ("sgdt %0" : "=m"(ptr));
	}

	inline void lidt(const desc_ptr& ptr) {
	    asm volatile ("lidt %0" : : "m"(ptr));
	}

	inline void sidt(desc_ptr& ptr) {
	    asm volatile ("sidt %0" : "=m"(ptr));
	}

	inline u16 read_cs() {
	    u16 r;
	    asm volatile ("mov %%cs, %0" : "=rm"(r));
	    return r;
	}

	inline u16 read_ds() {
	    u16 r;
	    asm volatile ("mov %%ds, %0" : "=rm"(r));
	    return r;
	}

	inline void write_ds(u16 r) {
	    asm volatile ("mov %0, %%ds" : : "rm"(r));
	}

	inline u16 read_es() {
	    u16 r;
	    asm volatile ("mov %%es, %0" : "=rm"(r));
	    return r;
	}

	inline void write_es(u16 r) {
	    asm volatile ("mov %0, %%es" : : "rm"(r));
	}

	inline u16 read_fs() {
	    u16 r;
	    asm volatile ("mov %%fs, %0" : "=rm"(r));
	    return r;
	}

	inline void write_fs(u16 r) {
	    asm volatile ("mov %0, %%fs" : : "rm"(r));
	}

	inline u16 read_gs() {
	    u16 r;
	    asm volatile ("mov %%gs, %0" : "=rm"(r));
	    return r;
	}

	inline void write_gs(u16 r) {
	    asm volatile ("mov %0, %%gs" : : "rm"(r));
	}

	inline u16 read_ss() {
	    u16 r;
	    asm volatile ("mov %%ss, %0" : "=rm"(r));
	    return r;
	}

	inline void write_ss(u16 r) {
	    asm volatile ("mov %0, %%ss" : : "rm"(r));
	}

	inline u64 rdmsr(u32 index) {
	    u32 lo, hi;
	    asm volatile ("rdmsr" : "=a"(lo), "=d"(hi) : "c"(index));
	    return lo | ((u64)hi << 32);
	}

	inline void wrmsr(u32 index, u64 data) {
	    u32 lo = data, hi = data >> 32;
	    asm volatile ("wrmsr" : : "c"(index), "a"(lo), "d"(hi));
	}

    };

};

#endif
