#include "Screen.h"

#include "Spark/Utility/Config.h"

void Screen::GetSize(float* _w, float* _h) const
{
	*_w = static_cast<float>(m_width);
	*_h = static_cast<float>(m_height);
}

void Screen::Quit()
{
	m_quit = true;
}

void Screen::Open()
{
	m_title = m_config->GetValue<string>("application", "title");
	m_clearColor = m_config->GetValue<Color>("window", "clrCol");

	m_width = m_config->GetValue<int>("window", "width");
	m_height = m_config->GetValue<int>("window", "height");

	InitWindow(m_width, m_height, m_title.c_str());

	if (m_config->GetValue<bool>("window", "isFullscreen"))
	{
		m_width = GetMonitorWidth(GetCurrentMonitor());
		m_height = GetMonitorHeight(GetCurrentMonitor());

		SetWindowSize(m_width, m_height);
		ToggleFullscreen();
	}
}

void Screen::Close()
{
	CloseWindow();
}

Screen::Screen(Config* _config)
	: m_config{ _config }, m_width{ 0 }, m_height{ 0 }, m_clearColor{}, m_quit{ false }
{
}

Screen::~Screen()
{
}

bool Screen::ShouldQuit() const
{
	return m_quit;
}

void Screen::NewFrame() const
{
	BeginDrawing();
	ClearBackground(m_clearColor);
}

void Screen::EndFrame()
{
	EndDrawing();

	if (WindowShouldClose())
		Quit();
}
