static const uint8_t vs_font_basic_glsl[361] =
{
	0x56, 0x53, 0x48, 0x01, 0x01, 0x83, 0xf2, 0xe1, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, // VSH.....attribut
	0x65, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x61, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, // e vec4 a_color0;
	0x0a, 0x61, 0x74, 0x74, 0x72, 0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, // .attribute vec2 
	0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x61, 0x74, 0x74, 0x72, // a_position;.attr
	0x69, 0x62, 0x75, 0x74, 0x65, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x61, 0x5f, 0x74, 0x65, 0x78, // ibute vec4 a_tex
	0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, // coord0;.varying 
	0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x76, // vec4 v_color0;.v
	0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x76, 0x5f, 0x74, 0x65, // arying vec4 v_te
	0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, // xcoord0;.uniform
	0x20, 0x6d, 0x61, 0x74, 0x34, 0x20, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, //  mat4 u_modelVie
	0x77, 0x50, 0x72, 0x6f, 0x6a, 0x3b, 0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, // wProj;.void main
	0x20, 0x28, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x74, 0x6d, 0x70, //  ().{.  vec4 tmp
	0x76, 0x61, 0x72, 0x5f, 0x31, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, // var_1;.  tmpvar_
	0x31, 0x2e, 0x7a, 0x77, 0x20, 0x3d, 0x20, 0x76, 0x65, 0x63, 0x32, 0x28, 0x30, 0x2e, 0x30, 0x2c, // 1.zw = vec2(0.0,
	0x20, 0x31, 0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, //  1.0);.  tmpvar_
	0x31, 0x2e, 0x78, 0x79, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, // 1.xy = a_positio
	0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x67, 0x6c, 0x5f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, // n;.  gl_Position
	0x20, 0x3d, 0x20, 0x28, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, //  = (u_modelViewP
	0x72, 0x6f, 0x6a, 0x20, 0x2a, 0x20, 0x74, 0x6d, 0x70, 0x76, 0x61, 0x72, 0x5f, 0x31, 0x29, 0x3b, // roj * tmpvar_1);
	0x0a, 0x20, 0x20, 0x76, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x20, 0x3d, // .  v_texcoord0 =
	0x20, 0x61, 0x5f, 0x74, 0x65, 0x78, 0x63, 0x6f, 0x6f, 0x72, 0x64, 0x30, 0x3b, 0x0a, 0x20, 0x20, //  a_texcoord0;.  
	0x76, 0x5f, 0x63, 0x6f, 0x6c, 0x6f, 0x72, 0x30, 0x20, 0x3d, 0x20, 0x61, 0x5f, 0x63, 0x6f, 0x6c, // v_color0 = a_col
	0x6f, 0x72, 0x30, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x00,                                           // or0;.}...
};
static const uint8_t vs_font_basic_dx9[335] =
{
	0x56, 0x53, 0x48, 0x01, 0x01, 0x83, 0xf2, 0xe1, 0x01, 0x00, 0x0f, 0x75, 0x5f, 0x6d, 0x6f, 0x64, // VSH........u_mod
	0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x09, 0x01, 0x00, 0x00, 0x04, 0x00, // elViewProj......
	0x2c, 0x01, 0x00, 0x03, 0xfe, 0xff, 0xfe, 0xff, 0x23, 0x00, 0x43, 0x54, 0x41, 0x42, 0x1c, 0x00, // ,.......#.CTAB..
	0x00, 0x00, 0x57, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfe, 0xff, 0x01, 0x00, 0x00, 0x00, 0x1c, 0x00, // ..W.............
	0x00, 0x00, 0x00, 0x81, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x02, 0x00, // ......P...0.....
	0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, // ......@.......u_
	0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x03, 0x00, // modelViewProj...
	0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x76, 0x73, // ..............vs
	0x5f, 0x33, 0x5f, 0x30, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, 0x20, 0x28, // _3_0.Microsoft (
	0x52, 0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x43, // R) HLSL Shader C
	0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x39, 0x2e, 0x32, 0x39, 0x2e, 0x39, 0x35, 0x32, // ompiler 9.29.952
	0x2e, 0x33, 0x31, 0x31, 0x31, 0x00, 0x1f, 0x00, 0x00, 0x02, 0x0a, 0x00, 0x00, 0x80, 0x00, 0x00, // .3111...........
	0x0f, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x0f, 0x90, 0x1f, 0x00, // ................
	0x00, 0x02, 0x05, 0x00, 0x00, 0x80, 0x02, 0x00, 0x0f, 0x90, 0x1f, 0x00, 0x00, 0x02, 0x00, 0x00, // ................
	0x00, 0x80, 0x00, 0x00, 0x0f, 0xe0, 0x1f, 0x00, 0x00, 0x02, 0x0a, 0x00, 0x00, 0x80, 0x01, 0x00, // ................
	0x0f, 0xe0, 0x1f, 0x00, 0x00, 0x02, 0x05, 0x00, 0x00, 0x80, 0x02, 0x00, 0x0f, 0xe0, 0x05, 0x00, // ................
	0x00, 0x03, 0x00, 0x00, 0x0f, 0x80, 0x01, 0x00, 0xe4, 0xa0, 0x01, 0x00, 0x55, 0x90, 0x04, 0x00, // ............U...
	0x00, 0x04, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x00, 0xe4, 0xa0, 0x01, 0x00, 0x00, 0x90, 0x00, 0x00, // ................
	0xe4, 0x80, 0x02, 0x00, 0x00, 0x03, 0x00, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0xe4, 0x80, 0x03, 0x00, // ................
	0xe4, 0xa0, 0x01, 0x00, 0x00, 0x02, 0x01, 0x00, 0x0f, 0xe0, 0x00, 0x00, 0xe4, 0x90, 0x01, 0x00, // ................
	0x00, 0x02, 0x02, 0x00, 0x0f, 0xe0, 0x02, 0x00, 0xe4, 0x90, 0xff, 0xff, 0x00, 0x00, 0x00,       // ...............
};
static const uint8_t vs_font_basic_dx11[1300] =
{
	0x56, 0x53, 0x48, 0x01, 0x01, 0x83, 0xf2, 0xe1, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, // VSH.............
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xb0, 0x09, 0x0f, 0x75, 0x5f, 0x6d, 0x6f, // ............u_mo
	0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x09, 0x00, 0xe0, 0x08, 0x04, // delViewProj.....
	0x00, 0xe0, 0x04, 0x44, 0x58, 0x42, 0x43, 0x3e, 0x63, 0x6d, 0xe7, 0x1c, 0x45, 0xb5, 0xff, 0x98, // ...DXBC>cm..E...
	0x06, 0x5a, 0xa2, 0x6d, 0x6a, 0xd4, 0x00, 0x01, 0x00, 0x00, 0x00, 0xe0, 0x04, 0x00, 0x00, 0x05, // .Z.mj...........
	0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x78, 0x02, 0x00, 0x00, 0xe8, 0x02, 0x00, 0x00, 0x5c, // ...4...x........
	0x03, 0x00, 0x00, 0x64, 0x04, 0x00, 0x00, 0x52, 0x44, 0x45, 0x46, 0x3c, 0x02, 0x00, 0x00, 0x01, // ...d...RDEF<....
	0x00, 0x00, 0x00, 0x48, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, // ...H............
	0x04, 0xfe, 0xff, 0x00, 0x91, 0x00, 0x00, 0x08, 0x02, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, // ...........<....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x24, 0x47, 0x6c, 0x6f, 0x62, // ...........$Glob
	0x61, 0x6c, 0x73, 0x00, 0xab, 0xab, 0xab, 0x3c, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x00, 0x00, 0x60, // als....<.......`
	0x00, 0x00, 0x00, 0xb0, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, // ...............P
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, // ................
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6c, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10, // .......l........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5c, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, // ...............x
	0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, // ... ...@........
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x90, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x40, // ...........`...@
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9b, // ................
	0x01, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa4, // ................
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xb4, 0x01, 0x00, 0x00, 0xa0, 0x08, 0x00, 0x00, 0x40, // ...............@
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, // ................
	0x01, 0x00, 0x00, 0xe0, 0x08, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x80, // .......@........
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd0, 0x01, 0x00, 0x00, 0x20, 0x09, 0x00, 0x00, 0x40, // ........... ...@
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe1, // ................
	0x01, 0x00, 0x00, 0x60, 0x09, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, // ...`...@........
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xed, 0x01, 0x00, 0x00, 0xa0, 0x09, 0x00, 0x00, 0x04, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, // ...............u
	0x5f, 0x76, 0x69, 0x65, 0x77, 0x52, 0x65, 0x63, 0x74, 0x00, 0xab, 0x01, 0x00, 0x03, 0x00, 0x01, // _viewRect.......
	0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, 0x5f, 0x76, 0x69, 0x65, // ...........u_vie
	0x77, 0x54, 0x65, 0x78, 0x65, 0x6c, 0x00, 0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x00, 0xab, 0x03, // wTexel.u_view...
	0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x75, // ...............u
	0x5f, 0x76, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, // _viewProj.u_mode
	0x6c, 0x00, 0xab, 0x03, 0x00, 0x03, 0x00, 0x04, 0x00, 0x04, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, // l.......... ....
	0x00, 0x00, 0x00, 0x75, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x00, 0x75, // ...u_modelView.u
	0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x00, 0x75, // _modelViewProj.u
	0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x56, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x58, 0x00, // _modelViewProjX.
	0x75, 0x5f, 0x76, 0x69, 0x65, 0x77, 0x50, 0x72, 0x6f, 0x6a, 0x58, 0x00, 0x75, 0x5f, 0x61, 0x6c, // u_viewProjX.u_al
	0x70, 0x68, 0x61, 0x52, 0x65, 0x66, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, // phaRef..........
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4d, 0x69, 0x63, 0x72, 0x6f, 0x73, 0x6f, 0x66, 0x74, // .......Microsoft
	0x20, 0x28, 0x52, 0x29, 0x20, 0x48, 0x4c, 0x53, 0x4c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, //  (R) HLSL Shader
	0x20, 0x43, 0x6f, 0x6d, 0x70, 0x69, 0x6c, 0x65, 0x72, 0x20, 0x39, 0x2e, 0x32, 0x39, 0x2e, 0x39, //  Compiler 9.29.9
	0x35, 0x32, 0x2e, 0x33, 0x31, 0x31, 0x31, 0x00, 0xab, 0xab, 0xab, 0x49, 0x53, 0x47, 0x4e, 0x68, // 52.3111....ISGNh
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, // ...........P....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, // ................
	0x0f, 0x00, 0x00, 0x56, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, // ...V............
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x00, 0x00, // ..........._....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0f, // ................
	0x0f, 0x00, 0x00, 0x43, 0x4f, 0x4c, 0x4f, 0x52, 0x00, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, // ...COLOR.POSITIO
	0x4e, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0x4f, 0x53, 0x47, 0x4e, 0x6c, // N.TEXCOORD.OSGNl
	0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x50, 0x00, 0x00, 0x00, 0x00, // ...........P....
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, // ................
	0x00, 0x00, 0x00, 0x5c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, // ................
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x62, 0x00, 0x00, 0x00, 0x00, // ...........b....
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x0f, // ................
	0x00, 0x00, 0x00, 0x53, 0x56, 0x5f, 0x50, 0x4f, 0x53, 0x49, 0x54, 0x49, 0x4f, 0x4e, 0x00, 0x43, // ...SV_POSITION.C
	0x4f, 0x4c, 0x4f, 0x52, 0x00, 0x54, 0x45, 0x58, 0x43, 0x4f, 0x4f, 0x52, 0x44, 0x00, 0xab, 0x53, // OLOR.TEXCOORD..S
	0x48, 0x44, 0x52, 0x00, 0x01, 0x00, 0x00, 0x40, 0x00, 0x01, 0x00, 0x40, 0x00, 0x00, 0x00, 0x59, // HDR....@...@...Y
	0x00, 0x00, 0x04, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x92, 0x00, 0x00, 0x00, 0x5f, // ...F. ........._
	0x00, 0x00, 0x03, 0xf2, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x03, 0x32, // ..........._...2
	0x10, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x5f, 0x00, 0x00, 0x03, 0xf2, 0x10, 0x10, 0x00, 0x02, // ......._........
	0x00, 0x00, 0x00, 0x67, 0x00, 0x00, 0x04, 0xf2, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, // ...g.... .......
	0x00, 0x00, 0x00, 0x65, 0x00, 0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x65, // ...e.... ......e
	0x00, 0x00, 0x03, 0xf2, 0x20, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x02, 0x01, // .... ......h....
	0x00, 0x00, 0x00, 0x38, 0x00, 0x00, 0x08, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x56, // ...8...........V
	0x15, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8f, // .......F. ......
	0x00, 0x00, 0x00, 0x32, 0x00, 0x00, 0x0a, 0xf2, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, // ...2...........F
	0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8e, 0x00, 0x00, 0x00, 0x06, 0x10, 0x10, 0x00, 0x01, // . ..............
	0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0xf2, // ...F............
	0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x0e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x46, //  ......F.......F
	0x8e, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x91, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x05, 0xf2, // . .........6....
	0x20, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x46, 0x1e, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, //  ......F.......6
	0x00, 0x00, 0x05, 0xf2, 0x20, 0x10, 0x00, 0x02, 0x00, 0x00, 0x00, 0x46, 0x1e, 0x10, 0x00, 0x02, // .... ......F....
	0x00, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x01, 0x53, 0x54, 0x41, 0x54, 0x74, 0x00, 0x00, 0x00, 0x06, // ...>...STATt....
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ................
	0x00, 0x00, 0x00, 0x00,                                                                         // ....
};
