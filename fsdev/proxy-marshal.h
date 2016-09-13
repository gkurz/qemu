/*
 * 9p Proxy marshal
 *
 * Copyright IBM, Corp. 2016
 *
 * Author: Greg Kurz <groug@kaod.org>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or
 * (at your option) any later version.
 *
 * See the COPYING file in the top-level directory for details.
 *
 */

#ifndef QEMU_PROXY_MARSHAL_H
#define QEMU_PROXY_MARSHAL_H

ssize_t proxy_unmarshal(struct iovec *in_sg, size_t offset, const char *fmt,
                        ...);
ssize_t proxy_marshal(struct iovec *out_sg, size_t offset, const char *fmt, ...);

#endif
