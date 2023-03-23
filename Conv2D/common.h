
/*
* Copyright 2021 Xilinx, Inc.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#pragma once

#include "ap_axi_sdata.h"
#include "hls_stream.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_IMAGE_WIDTH     1920
#define MAX_IMAGE_HEIGHT    1080

#define FILTER_V_SIZE		11
#define FILTER_H_SIZE		11
#define MAX_COEFFS          FILTER_V_SIZE * FILTER_H_SIZE

#ifndef MIN
#define MIN(a,b) ((a<b)?a:b)
#endif
#ifndef MAX
#define MAX(a,b) ((a<b)?b:a)
#endif

#define CONV_2D_MIN 0
#define CONV_2D_MAX 32767

typedef ap_axiu<16, 0, 0, 0> pix_out_t;
typedef signed short         pix_t;

typedef unsigned char      		U8;
typedef unsigned short     		U16;
typedef unsigned int       		U32;

typedef signed char        		I8;
typedef signed short       		I16;
typedef signed int         		I32;

void Filter2D(
		const float              coeffs[FILTER_V_SIZE][FILTER_H_SIZE],
		float		             factor,
		short                    bias,
		unsigned short           width,
		unsigned short           height,
		unsigned short           stride,
        hls::stream<pix_t,2>    &input_stream,
        hls::stream<pix_out_t>  &output_stream);
		// const unsigned char *src,
		// unsigned char       *dst);


extern "C" {

  void Filter2DKernel(
		const float             *coeffs,
		float                    factor,
		short                    bias,
		unsigned short           width,
		unsigned short           height,
		unsigned short           stride,
        hls::stream<pix_t,2>    &input_stream,
        hls::stream<pix_out_t>  &output_stream);
		// const unsigned char *src,
		// unsigned char       *dst);

}
