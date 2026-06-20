

/*
 * Copyright 2011-2026 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "../common/common.sh"
#include "bgfx_compute.sh"

uniform vec4 u_topology;

# define line_strip bool(u_topology.x > 0.0)

BUFFER_RO(vertexPosBuffer, vec2, 0); // vertices

void main()
{
    uint linesWidth = 4u; // line width in pixels

    uint lineIndex = gl_VertexID / 6u;
	uint localVertex = gl_VertexID % 6u;

    // useIndices tells whether we need indirect indexing to fetch vertex pos
	// lines or line strip topology affects how we index into the vertex buffer
	uint vertexIndex0 = line_strip ? lineIndex : lineIndex * 2u;
	uint vertexIndex1 = line_strip ? lineIndex + 1u : lineIndex * 2u + 1u;

    // Fetch the two endpoints of this line
	vec2 p0 = vertexPosBuffer[vertexIndex0];
	vec2 p1 = vertexPosBuffer[vertexIndex1];

    // Quad expansion: map localVertex (0-5) to quad corners and UVs
	// Triangle 1: verts 0, 1, 2
	// Triangle 2: verts 3, 4, 5
	const vec2 offsets[6] = {
	    vec2(-1.0, -1.0), vec2(-1.0,  1.0), vec2( 1.0, -1.0),
		vec2( 1.0, -1.0), vec2(-1.0,  1.0), vec2( 1.0,  1.0)
	};

    vec2 offset = offsets[localVertex];
	vec2 uv = offset * 0.5 + 0.5; // UV coordinates in [0,1]

    // Compute line direction in screen space
	vec2 screenDir = p1 - p0;
	float screenDirLen = length(screenDir);

    // Avoid division by zero for degenerate lines
	if (screenDirLen > 0.0001) {
	    // Compute normal (perpendicular) to the line direction
		vec2 T = screenDir / screenDirLen;  // Tangent
		vec2 N = vec2(-T.y, T.x);           // Normal (90° rotation)

        // Position along the line (uv.x: 0 = p0, 1 = p1)
		vec2 linePos = mix(p0, p1, uv.x);

        // Side offset (-1 = one side, 1 = other side)
		float side = 2.0 * uv.y - 1.0;

        // Width is in pixels, screen coordinates are also in pixels
		// So we can apply the offset directly in screenspace
		vec2 offsetScreen = N * (0.5 * linesWidth) * side;

        // Final position in screenspace
		vec2 finalPos = linePos + offsetScreen;

        // Convert from screen space (0..1 relative to viewRect) to clip space (-1..1)
		gl_Position = vec4(
		    (finalPos.x - u_viewRect.x) / u_viewRect.z * 2.0 - 1.0,
			1.0 - (finalPos.y - u_viewRect.y) / u_viewRect.w * 2.0,
			0.0,
			1.0);
	} else {
	    // Degenerate line: render as a point at p0
		gl_Position = vec4(
		    (p0.x - u_viewRect.x) / u_viewRect.z * 2.0 - 1.0,
			1.0 - (p0.y - u_viewRect.y) / u_viewRect.w * 2.0,
			0.0,
			1.0);
	}
}
