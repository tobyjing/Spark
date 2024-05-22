#pragma once

#include <Spark/Common.h>
#include <raylib/raylib.h>

class Config;

class Screen
{
	friend class Application;

public:
	Screen(const Screen&) = delete;
	Screen(Screen&&) = delete;

public:
	void GetSize(float* _w, float* _h) const;
	void Quit();
	void Open();
	void Close();

public:
	Screen& operator=(const Screen&) = delete;
	Screen& operator=(Screen&&) = delete;

private:
	Config* m_config;
	int m_width;
	int m_height;

	string m_title;
	Color m_clearColor;

	bool m_quit;

private:
	Screen(Config* _config);
	~Screen();

	bool ShouldQuit() const;

	void NewFrame() const;
	void EndFrame();

private:

};
