/*
 *  Copyright (C) 2015 Adrien Vergé
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _HDLC_H
#define _HDLC_H

#include <stdint.h>
#include <sys/types.h>
#include <stdlib.h>

/*
 * These macros are used to help decide how much to malloc before encoding or
 * decoding. They over-evaluate the output size so it is sure the output will
 * fit.
 */
#define estimated_encoded_size(ppp_pkt_len)	(9 + 2 * (ppp_pkt_len))
#define estimated_decoded_size(hdlc_frm_len)	(hdlc_frm_len)

ssize_t hdlc_encode(uint8_t *frame, size_t frmsize,
		    uint8_t *packet, size_t pktsize);

ssize_t hdlc_find_frame(uint8_t *buffer, size_t bufsize, off_t *start);

ssize_t hdlc_decode(uint8_t *frame, size_t frmsize,
		    uint8_t *packet, size_t pktsize);

#endif