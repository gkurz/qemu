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

#include "qemu/osdep.h"
#include "proxy-marshal.h"
#include "9p-iov-marshal.h"

ssize_t proxy_unmarshal(struct iovec *in_sg, size_t offset, const char *fmt,
                        ...)
{
    int i;
    ssize_t copied = 0;
    size_t old_offset = offset;
    va_list ap;

    va_start(ap, fmt);
    for (i = 0; fmt[i]; i++) {
        copied = v9fs_iov_vunmarshal_one(in_sg, 1, &offset, 0, fmt[i], &ap);
        if (copied < 0) {
            break;
        }
        offset += copied;
    }
    va_end(ap);

    return copied < 0 ? copied : offset - old_offset;
}

ssize_t proxy_marshal(struct iovec *out_sg, size_t offset, const char *fmt, ...)
{
    int i;
    ssize_t copied = 0;
    size_t old_offset = offset;
    va_list ap;

    va_start(ap, fmt);
    for (i = 0; fmt[i]; i++) {
        copied = v9fs_iov_vmarshal_one(out_sg, 1, &offset, 0, fmt[i], &ap);
        if (copied < 0) {
            break;
        }
        offset += copied;
    }
    va_end(ap);

    return copied < 0 ? copied : offset - old_offset;
}
