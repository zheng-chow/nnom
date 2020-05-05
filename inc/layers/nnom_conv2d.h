/*
 * Copyright (c) 2018-2020
 * Jianjia Ma, Wearable Bio-Robotics Group (WBR)
 * majianjia@live.com
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2020-05-03     Jianjia Ma   The first version
 */

#ifndef __NNOM_CONV2D_H__
#define __NNOM_CONV2D_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "nnom.h"
#include "nnom_layers.h"
#include "nnom_local.h"
#include "nnom_tensor.h"


// child layers parameters
typedef struct _nnom_conv2d_layer_t
{
	nnom_layer_t super;
	nnom_3d_shape_t kernel;
	nnom_3d_shape_t stride;
	nnom_3d_shape_t pad;
	nnom_3d_shape_t dilation;
	nnom_padding_t padding_type;
	uint32_t filter_mult; 							// filter size (for conv) or multilplier (for depthwise)

	nnom_tensor_t *weight; // how about using tensor to store weights and bias?
	nnom_tensor_t *bias;
} nnom_conv2d_layer_t;

// a machine interface for configuration
typedef struct _nnom_conv2d_config_t
{
	nnom_layer_config_t super;
	nnom_qtype_t qtype; 	//quantisation type(per channel or per layer)
	nnom_tensor_t *weight;
	nnom_tensor_t *bias;
	int8_t *output_shift;   // not sure if we need that
	uint32_t filter_size;  
	int8_t kernel_size[2];
	int8_t stride_size[2];
	int8_t padding_size[2];
	int8_t dilation_size[2];
	nnom_padding_t padding;
} nnom_conv2d_config_t;


nnom_layer_t *Conv2D(uint32_t filters, nnom_3d_shape_t k, nnom_3d_shape_t s, nnom_padding_t pad_type,
					 const nnom_weight_t *w, const nnom_bias_t *b);

nnom_layer_t *conv2d_s(nnom_conv2d_config_t *config);




#ifdef __cplusplus
}
#endif

#endif /* __NNOM_CONV2D_H__ */
