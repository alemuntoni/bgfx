$output v_color0

/*
 * Copyright 2011-2026 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "../common/common.sh"
#include "bgfx_compute.sh"

BUFFER_RO(points, vec2, 0);
BUFFER_RO(colors, uint, 1);

vec4 uintABGRToVec4Color(uint color)
{
    return vec4(
	    float(color & uint(0x000000FF)) / 255.0,
		float((color & uint(0x0000FF00)) >> uint(8)) / 255.0,
		float((color & uint(0x00FF0000)) >> uint(16)) / 255.0,
		float((color & uint(0xFF000000)) >> uint(24)) / 255.0);
}

void main()
{
    gl_Position = vec4(points[gl_VertexID], 0.0, 1.0);
	v_color0 = uintABGRToVec4Color(colors[gl_VertexID]);
}
