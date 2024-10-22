#ifdef USE_SDK
	#include "wooting-analog-wrapper.h"

	#pragma comment(lib, "wooting_analog_wrapper.lib")
	#pragma comment(lib, "Userenv.lib")
	#pragma comment(lib, "ntdll.lib")
	#pragma comment(lib, "Bcrypt.lib")
	#pragma comment(lib, "Ws2_32.lib")
	#pragma comment(lib, "Advapi32.lib")
#else
	#include <AnalogueKeyboard.hpp>
#endif

#define WOOTINGANALOGSDK_API extern "C" __declspec(dllexport)

WOOTINGANALOGSDK_API bool wooting_kbd_connected()
{
	return true; // ¯\_(ツ)_/¯
}

WOOTINGANALOGSDK_API void wooting_set_disconnected_cb(void(*cb)())
{
	// ¯\_(ツ)_/¯
}

#ifdef USE_SDK
	static bool inited = false;
#else
	static soup::AnalogueKeyboard akbd;
	static uint8_t most_recent_data[32];
	static unsigned int most_recent_data_length = 0;
#endif

extern uint8_t hid_to_wooting_scancode_map[256];

WOOTINGANALOGSDK_API int wooting_read_full_buffer(uint8_t data[], unsigned int byte_length)
{
#ifdef USE_SDK
	if (!inited) [[unlikely]]
	{
		(void)wooting_analog_initialise();
		inited = true;
	}
#endif

	unsigned int length = byte_length >> 1;
	if (length > 16)
	{
		length = 16;
	}

#ifdef USE_SDK
	unsigned short scancodes[16];
	float values[16];
	int n = wooting_analog_read_full_buffer(scancodes, values, 16);
	if (n < 0 || n >= 16)
	{
		return 0;
	}

	if (n > length)
	{
		n = length;
	}

	for (int i = 0; i != n; ++i)
	{
		uint8_t mapped_scancode = 255;
		if (scancodes[i] < 256)
		{
			mapped_scancode = hid_to_wooting_scancode_map[scancodes[i]];
		}
		data[i * 2 + 0] = mapped_scancode;
		data[i * 2 + 1] = static_cast<uint8_t>(values[i] * 255.0f);
	}
	return n;
#else
	if (!akbd.hid.isValid()) [[unlikely]]
	{
		for (auto& a : soup::AnalogueKeyboard::getAll())
		{
			akbd = std::move(a);
			break;
		}
		if (!akbd.hid.isValid()) [[unlikely]]
		{
			return 0;
		}
	}

	if (akbd.isPoll() || akbd.hid.hasReport())
	{
		unsigned int i = 0;
		for (const auto& key : akbd.getActiveKeys())
		{
			if (i == length) [[unlikely]]
			{
				break;
			}

			data[i * 2 + 0] = hid_to_wooting_scancode_map[key.getHidScancode()]; static_assert(sizeof(decltype(key.getHidScancode())) == 1);
			data[i * 2 + 1] = static_cast<uint8_t>(key.fvalue * 255.0f);
			++i;
		}
		memcpy(most_recent_data, data, i * 2);
		most_recent_data_length = i;
		return i;
	}
	else
	{
		unsigned int i = most_recent_data_length;
		if (i > length)
		{
			i = length;
		}
		memcpy(data, most_recent_data, i * 2);
		return i;
	}
#endif
}

#define WOOTING_RGB_ROWS 6
#define WOOTING_RGB_COLS 21
#define NOKEY 255

static uint8_t scan_index_array[WOOTING_RGB_ROWS][WOOTING_RGB_COLS] = {
	{ 0, NOKEY, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 107, 108, 109, 110 },
	{ 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 61, 106, 105, 104, 103 },
	{ 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 62, 102, 101, 100, 99 },
	{ 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 45, 60, NOKEY, NOKEY, NOKEY, 98, 97, 96, NOKEY },
	{ 64, 87, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, NOKEY, 75, NOKEY, 63, NOKEY, 90, 91, 92, 93 },
	{ 80, 81, 82, NOKEY, NOKEY, NOKEY, 83, NOKEY, NOKEY, NOKEY, 84, 85, 86, 79, 76, 77, 78, NOKEY, 95, 94, NOKEY }
};

WOOTINGANALOGSDK_API uint8_t wooting_read_analog(uint8_t row, uint8_t column)
{
	if (row < WOOTING_RGB_ROWS && column < WOOTING_RGB_COLS) [[likely]]
	{
		const uint8_t requested_scan_code = scan_index_array[row][column];
		if (requested_scan_code != 255) [[likely]]
		{
			uint8_t data[32];
			int n = wooting_read_full_buffer(data, sizeof(data));
			for (int i = 0; i != n; ++i)
			{
				if (data[i * 2 + 0] == requested_scan_code)
				{
					return data[i * 2 + 1];
				}
			}
		}
	}
	return 0;
}
