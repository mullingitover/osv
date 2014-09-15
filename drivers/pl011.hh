/*
 * Copyright (C) 2014 Huawei Technologies Duesseldorf GmbH
 *
 * This work is open source software, licensed under the terms of the
 * BSD license as described in the LICENSE file in the top-level directory.
 */

#ifndef PL011_HH
#define PL011_HH

#include "console-driver.hh"
#include "exceptions.hh"

namespace console {

class PL011_Console : public console_driver {
public:
    virtual void write(const char *str, size_t len);
    virtual void flush();
    virtual bool input_ready();
    virtual char readch();

    void set_base_addr(u64 addr);
    u64 get_base_addr();

private:
    virtual void dev_start();
    virtual const char *thread_name() { return "pl011-input"; }
    unsigned int irqid;
    static void irq_handler(struct interrupt_desc *desc);
};

}

#endif /* PL011_HH */
