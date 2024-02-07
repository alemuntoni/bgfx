/*
 * Copyright 2011-2024 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bgfx/blob/master/LICENSE
 */

#include "common.h"
#include "bgfx_utils.h"
#include <entry/input.h>
#include <bx/string.h>
#include "imgui/imgui.h"

#include <string>
#include <bx/file.h>

void cmdCreateWindow(const void* _userData);
void cmdDestroyWindow(const void* _userData);

namespace
{

#define MAX_WINDOWS 8

struct PosColorVertex
{
	float m_x;
	float m_y;
	float m_z;
	uint32_t m_abgr;

	static void init()
	{
		ms_layout
			.begin()
			.add(bgfx::Attrib::Position, 3, bgfx::AttribType::Float)
			.add(bgfx::Attrib::Color0,   4, bgfx::AttribType::Uint8, true)
			.end();
	};

	static bgfx::VertexLayout ms_layout;
};

bgfx::VertexLayout PosColorVertex::ms_layout;

static PosColorVertex s_cubeVertices[8] =
{
	{-1.0f,  1.0f,  1.0f, 0xff000000 },
	{ 1.0f,  1.0f,  1.0f, 0xff0000ff },
	{-1.0f, -1.0f,  1.0f, 0xff00ff00 },
	{ 1.0f, -1.0f,  1.0f, 0xff00ffff },
	{-1.0f,  1.0f, -1.0f, 0xffff0000 },
	{ 1.0f,  1.0f, -1.0f, 0xffff00ff },
	{-1.0f, -1.0f, -1.0f, 0xffffff00 },
	{ 1.0f, -1.0f, -1.0f, 0xffffffff },
};

static const uint16_t s_cubeIndices[36] =
{
	0, 1, 2, // 0
	1, 3, 2,
	4, 6, 5, // 2
	5, 6, 7,
	0, 2, 4, // 4
	4, 2, 6,
	1, 5, 3, // 6
	5, 7, 3,
	0, 4, 1, // 8
	4, 5, 1,
	2, 3, 6, // 10
	6, 3, 7,
};

void savePng(const char* _filePath, uint32_t _width, uint32_t _height, uint32_t _srcPitch, const void* _src, bimg::TextureFormat::Enum _format, bool _yflip)
{
	bx::FileWriter writer;
	bx::Error err;
	if (bx::open(&writer, _filePath, false, &err) )
	{
		bimg::imageWritePng(&writer, _width, _height, _srcPitch, _src, _format, _yflip, &err);
		bx::close(&writer);
	}
}

struct BgfxCallback : public bgfx::CallbackI
{
	virtual ~BgfxCallback()
	{
	}

	virtual void fatal(const char* _filePath, uint16_t _line, bgfx::Fatal::Enum _code, const char* _str) override
	{
		BX_UNUSED(_filePath, _line);

		// Something unexpected happened, inform user and bail out.
		bx::debugPrintf("Fatal error: 0x%08x: %s", _code, _str);

		// Must terminate, continuing will cause crash anyway.
		abort();
	}

	virtual void traceVargs(const char* _filePath, uint16_t _line, const char* _format, va_list _argList) override
	{
		bx::debugPrintf("%s (%d): ", _filePath, _line);
		bx::debugPrintfVargs(_format, _argList);
	}

	virtual void profilerBegin(const char* /*_name*/, uint32_t /*_abgr*/, const char* /*_filePath*/, uint16_t /*_line*/) override
	{
	}

	virtual void profilerBeginLiteral(const char* /*_name*/, uint32_t /*_abgr*/, const char* /*_filePath*/, uint16_t /*_line*/) override
	{
	}

	virtual void profilerEnd() override
	{
	}

	virtual uint32_t cacheReadSize(uint64_t _id) override
	{
		char filePath[256];
		bx::snprintf(filePath, sizeof(filePath), "temp/%016" PRIx64, _id);

		// Use cache id as filename.
		bx::FileReaderI* reader = entry::getFileReader();
		bx::Error err;
		if (bx::open(reader, filePath, &err) )
		{
			uint32_t size = (uint32_t)bx::getSize(reader);
			bx::close(reader);
			// Return size of shader file.
			return size;
		}

		// Return 0 if shader is not found.
		return 0;
	}

	virtual bool cacheRead(uint64_t _id, void* _data, uint32_t _size) override
	{
		char filePath[256];
		bx::snprintf(filePath, sizeof(filePath), "temp/%016" PRIx64, _id);

		// Use cache id as filename.
		bx::FileReaderI* reader = entry::getFileReader();
		bx::Error err;
		if (bx::open(reader, filePath, &err) )
		{
			// Read shader.
			uint32_t result = bx::read(reader, _data, _size, &err);
			bx::close(reader);

			// Make sure that read size matches requested size.
			return result == _size;
		}

		// Shader is not found in cache, needs to be rebuilt.
		return false;
	}

	virtual void cacheWrite(uint64_t _id, const void* _data, uint32_t _size) override
	{
		char filePath[256];
		bx::snprintf(filePath, sizeof(filePath), "temp/%016" PRIx64, _id);

		// Use cache id as filename.
		bx::FileWriterI* writer = entry::getFileWriter();
		bx::Error err;
		if (bx::open(writer, filePath, false, &err) )
		{
			// Write shader to cache location.
			bx::write(writer, _data, _size, &err);
			bx::close(writer);
		}
	}

	virtual void screenShot(const char* _filePath, uint32_t _width, uint32_t _height, uint32_t _pitch, const void* _data, uint32_t /*_size*/, bool _yflip) override
	{
		char temp[1024];

		// Save screen shot as PNG.
		bx::snprintf(temp, BX_COUNTOF(temp), "%s.png", _filePath);
		savePng(temp, _width, _height, _pitch, _data, bimg::TextureFormat::BGRA8, _yflip);
	}

	virtual void captureBegin(uint32_t _width, uint32_t _height, uint32_t /*_pitch*/, bgfx::TextureFormat::Enum /*_format*/, bool _yflip) override
	{
	}

	virtual void captureEnd() override
	{
	}

	virtual void captureFrame(const void* _data, uint32_t /*_size*/) override
	{
	}
};

class ExampleWindows : public entry::AppI
{
public:
	ExampleWindows(const char* _name, const char* _description, const char* _url)
		: entry::AppI(_name, _description, _url)
	{
	}

	void init(int32_t _argc, const char* const* _argv, uint32_t _width, uint32_t _height) override
	{
		Args args(_argc, _argv);

		m_width  = _width;
		m_height = _height;
		m_debug  = BGFX_DEBUG_TEXT;
		m_reset  = BGFX_RESET_VSYNC;

		bgfx::Init init;
		init.type     = args.m_type;
		init.vendorId = args.m_pciId;
		init.platformData.nwh  = entry::getNativeWindowHandle(entry::kDefaultWindowHandle);
		init.platformData.ndt  = entry::getNativeDisplayHandle();
		init.platformData.type = entry::getNativeWindowHandleType();
		init.resolution.width  = m_width;
		init.resolution.height = m_height;
		init.resolution.reset  = m_reset;
		init.callback  = &m_callback;  // custom callback handler
		bgfx::init(init);

		const bgfx::Caps* caps = bgfx::getCaps();
		bool swapChainSupported = 0 != (caps->supported & BGFX_CAPS_SWAP_CHAIN);

		if (swapChainSupported)
		{
			m_bindings = (InputBinding*)bx::alloc(entry::getAllocator(), sizeof(InputBinding)*3);
			m_bindings[0].set(entry::Key::KeyC, entry::Modifier::None, 1, cmdCreateWindow,  this);
			m_bindings[1].set(entry::Key::KeyD, entry::Modifier::None, 1, cmdDestroyWindow, this);
			m_bindings[2].end();

			inputAddBindings("22-windows", m_bindings);
		}
		else
		{
			m_bindings = NULL;
		}

		// Enable m_debug text.
		bgfx::setDebug(m_debug);

		// Set view 0 clear state.
		bgfx::setViewClear(0
			, BGFX_CLEAR_COLOR|BGFX_CLEAR_DEPTH
			, 0x303030ff
			, 1.0f
			, 0
			);

		// Create vertex stream declaration.
		PosColorVertex::init();

		// Create static vertex buffer.
		m_vbh = bgfx::createVertexBuffer(
			  // Static data can be passed with bgfx::makeRef
			  bgfx::makeRef(s_cubeVertices, sizeof(s_cubeVertices) )
			, PosColorVertex::ms_layout
			);

		// Create static index buffer.
		m_ibh = bgfx::createIndexBuffer(
			// Static data can be passed with bgfx::makeRef
			bgfx::makeRef(s_cubeIndices, sizeof(s_cubeIndices) )
			);

		// Create program from shaders.
		m_program = loadProgram("vs_cubes", "fs_cubes");

		m_timeOffset = bx::getHPCounter();

		bx::memSet(m_fbh, 0xff, sizeof(m_fbh) );

		imguiCreate();
	}

	virtual int shutdown() override
	{
		imguiDestroy();

		for (uint32_t ii = 0; ii < MAX_WINDOWS; ++ii)
		{
			if (bgfx::isValid(m_fbh[ii]) )
			{
				bgfx::destroy(m_fbh[ii]);
			}
		}

		inputRemoveBindings("22-windows");
		bx::free(entry::getAllocator(), m_bindings);

		// Cleanup.
		bgfx::destroy(m_ibh);
		bgfx::destroy(m_vbh);
		bgfx::destroy(m_program);

		// Shutdown bgfx.
		bgfx::shutdown();

		return 0;
	}

	bool update() override
	{
		m_frame++;

		if (!entry::processWindowEvents(m_state, m_debug, m_reset) )
		{
			entry::MouseState mouseState = m_state.m_mouse;

			if (isValid(m_state.m_handle) )
			{
				if (0 == m_state.m_handle.idx)
				{
					m_width  = m_state.m_width;
					m_height = m_state.m_height;
				}
				else
				{
					uint8_t viewId = (uint8_t)m_state.m_handle.idx;
					entry::WindowState& win = m_windows[viewId];

					if (win.m_nwh    != m_state.m_nwh
					|| (win.m_width  != m_state.m_width
					||  win.m_height != m_state.m_height) )
					{
						// When window changes size or native window handle changed
						// frame buffer must be recreated.
						if (bgfx::isValid(m_fbh[viewId]) )
						{
							bgfx::destroy(m_fbh[viewId]);
							m_fbh[viewId].idx = bgfx::kInvalidHandle;
						}

						win.m_nwh    = m_state.m_nwh;
						win.m_width  = m_state.m_width;
						win.m_height = m_state.m_height;

						if (NULL != win.m_nwh)
						{
							m_fbh[viewId] = bgfx::createFrameBuffer(win.m_nwh, uint16_t(win.m_width), uint16_t(win.m_height) );
						}
						else
						{
							win.m_handle.idx = UINT16_MAX;
						}
					}
				}
			}

			imguiBeginFrame(mouseState.m_mx
				,  mouseState.m_my
				, (mouseState.m_buttons[entry::MouseButton::Left  ] ? IMGUI_MBUT_LEFT   : 0)
				| (mouseState.m_buttons[entry::MouseButton::Right ] ? IMGUI_MBUT_RIGHT  : 0)
				| (mouseState.m_buttons[entry::MouseButton::Middle] ? IMGUI_MBUT_MIDDLE : 0)
				,  mouseState.m_mz
				, uint16_t(m_width)
				, uint16_t(m_height)
				);

			showExampleDialog(this);

			imguiEndFrame();

			const bx::Vec3 at  = { 0.0f, 0.0f,   0.0f };
			const bx::Vec3 eye = { 0.0f, 0.0f, -35.0f };

			float view[16];
			bx::mtxLookAt(view, eye, at);

			float proj[16];
			bx::mtxProj(proj, 60.0f, float(m_width)/float(m_height), 0.1f, 100.0f, bgfx::getCaps()->homogeneousDepth);

			bgfx::setViewTransform(0, view, proj);
			bgfx::setViewRect(0, 0, 0, uint16_t(m_width), uint16_t(m_height) );
			// This dummy draw call is here to make sure that view 0 is cleared
			// if no other draw calls are submitted to view 0.
			bgfx::touch(0);

			std::string base_path = "temp/";

			if (m_frame % 300 == 0) {
				uint32_t cnt = m_frame / 300;

				std::string filename = base_path + "frame_" + std::to_string(cnt) + "_0";

				bgfx::FrameBufferHandle fbh = BGFX_INVALID_HANDLE;
				bgfx::requestScreenShot(fbh, filename.c_str());
			}

			// Set view and projection matrix for view 0.
			for (uint8_t ii = 1; ii < MAX_WINDOWS; ++ii)
			{
				bgfx::setViewTransform(ii, view, proj);
				bgfx::setViewFrameBuffer(ii, m_fbh[ii]);

				if (!bgfx::isValid(m_fbh[ii]) )
				{
					// Set view to default viewport.
					bgfx::setViewRect(ii, 0, 0, uint16_t(m_width), uint16_t(m_height) );
					bgfx::setViewClear(ii, BGFX_CLEAR_NONE);
				}
				else
				{
					bgfx::setViewRect(ii, 0, 0, uint16_t(m_windows[ii].m_width), uint16_t(m_windows[ii].m_height) );
					bgfx::setViewClear(ii
						, BGFX_CLEAR_COLOR|BGFX_CLEAR_DEPTH
						, 0x303030ff
						, 1.0f
						, 0
						);

					if (m_frame % 300 == 0) {
						uint32_t cnt = m_frame / 300;

						std::string filename = base_path + "frame_" + std::to_string(cnt) + "_" + std::to_string(ii);

						bgfx::requestScreenShot(m_fbh[ii], filename.c_str());
					}
				}
			}

			int64_t now = bx::getHPCounter();
			float time = (float)( (now-m_timeOffset)/double(bx::getHPFrequency() ) );

			if (NULL != m_bindings)
			{
				bgfx::dbgTextPrintf(0, 1, 0x2f, "Press 'c' to create or 'd' to destroy window.");
			}
			else
			{
				bool blink = uint32_t(time*3.0f)&1;
				bgfx::dbgTextPrintf(0, 0, blink ? 0x4f : 0x04, " Multiple windows is not supported by `%s` renderer. ", bgfx::getRendererName(bgfx::getCaps()->rendererType) );
			}

			uint32_t count = 0;

			// Submit 11x11 cubes.
			for (uint32_t yy = 0; yy < 11; ++yy)
			{
				for (uint32_t xx = 0; xx < 11; ++xx)
				{
					float mtx[16];
					bx::mtxRotateXY(mtx, time + xx*0.21f, time + yy*0.37f);
					mtx[12] = -15.0f + float(xx)*3.0f;
					mtx[13] = -15.0f + float(yy)*3.0f;
					mtx[14] = 0.0f;

					// Set model matrix for rendering.
					bgfx::setTransform(mtx);

					// Set vertex and index buffer.
					bgfx::setVertexBuffer(0, m_vbh);
					bgfx::setIndexBuffer(m_ibh);

					// Set render states.
					bgfx::setState(BGFX_STATE_DEFAULT);

					// Submit primitive for rendering.
					bgfx::submit(count%MAX_WINDOWS, m_program);
					++count;
				}
			}

			// Advance to next frame. Rendering thread will be kicked to
			// process submitted rendering primitives.
			bgfx::frame();

			return true;
		}

		return false;
	}

	void createWindow()
	{
		entry::WindowHandle handle = entry::createWindow(rand()%1280, rand()%720, 640, 480);
		if (entry::isValid(handle) )
		{
			char str[256];
			bx::snprintf(str, BX_COUNTOF(str), "Window - handle %d", handle.idx);
			entry::setWindowTitle(handle, str);
			m_windows[handle.idx].m_handle = handle;
		}
	}

	void destroyWindow()
	{
		for (uint32_t ii = 0; ii < MAX_WINDOWS; ++ii)
		{
			if (bgfx::isValid(m_fbh[ii]) )
			{
				bgfx::destroy(m_fbh[ii]);
				m_fbh[ii].idx = bgfx::kInvalidHandle;

				// Flush destruction of swap chain before destroying window!
				bgfx::frame();
				bgfx::frame();
			}

			if (entry::isValid(m_windows[ii].m_handle) )
			{
				entry::destroyWindow(m_windows[ii].m_handle);
				m_windows[ii].m_handle.idx = UINT16_MAX;
				return;
			}
		}
	}

	BgfxCallback  m_callback;

	entry::WindowState m_state;

	uint32_t m_width;
	uint32_t m_height;
	uint32_t m_debug;
	uint32_t m_reset;

	bgfx::VertexBufferHandle m_vbh;
	bgfx::IndexBufferHandle m_ibh;
	bgfx::ProgramHandle m_program;

	entry::WindowState m_windows[MAX_WINDOWS];
	bgfx::FrameBufferHandle m_fbh[MAX_WINDOWS];

	InputBinding* m_bindings;

	int64_t m_timeOffset;

	uint32_t m_frame = 0;
};

} // namespace

ENTRY_IMPLEMENT_MAIN(
	  ExampleWindows
	, "22-windows"
	, "Rendering into multiple windows."
	, "https://bkaradzic.github.io/bgfx/examples.html#windows"
	);

void cmdCreateWindow(const void* _userData)
{
	( (ExampleWindows*)_userData)->createWindow();
}

void cmdDestroyWindow(const void* _userData)
{
	( (ExampleWindows*)_userData)->destroyWindow();
}
