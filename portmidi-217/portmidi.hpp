#pragma once
#include <dynalizer/dynalizer.hpp>
#include <portmidi.h>
#include <stdexcept>

#define PORTMIDI_WRAP_INIT(Fun)                                   \
m_sym_ ## Fun = m_lib.symbol<decltype(::Fun)*>(# Fun);           \
if(!m_sym_ ## Fun)                                               \
    throw std::runtime_error("Invalid symbol lookup: Fun");

#define PORTMIDI_WRAP_FUNCTION(Fun, PrettyFun)                    \
public:                                                          \
template<typename... Args>                                       \
auto PrettyFun(Args&&... args) -> decltype(auto)                 \
{                                                                \
  return m_sym_ ## Fun(std::forward<Args>(args)...);             \
}                                                                \
private:                                                         \
  decltype(::Fun)* m_sym_ ## Fun{};


class portmidi
{
public:
  explicit portmidi(const char* filepath)
    : m_lib{filepath}
  {
  
  PORTMIDI_WRAP_INIT(Pm_Initialize)
  PORTMIDI_WRAP_INIT(Pm_Terminate)
  PORTMIDI_WRAP_INIT(Pm_HasHostError)
  PORTMIDI_WRAP_INIT(Pm_GetErrorText)
  PORTMIDI_WRAP_INIT(Pm_GetHostErrorText)
  PORTMIDI_WRAP_INIT(Pm_CountDevices)
  PORTMIDI_WRAP_INIT(Pm_GetDefaultInputDeviceID)
  PORTMIDI_WRAP_INIT(Pm_GetDefaultOutputDeviceID)
  PORTMIDI_WRAP_INIT(Pm_GetDeviceInfo)
  PORTMIDI_WRAP_INIT(Pm_OpenInput)
  PORTMIDI_WRAP_INIT(Pm_OpenOutput)
  PORTMIDI_WRAP_INIT(Pm_SetFilter)
  PORTMIDI_WRAP_INIT(Pm_SetChannelMask)
  PORTMIDI_WRAP_INIT(Pm_Abort)
  PORTMIDI_WRAP_INIT(Pm_Close)
  PORTMIDI_WRAP_INIT(Pm_Synchronize)
  PORTMIDI_WRAP_INIT(Pm_Read)
  PORTMIDI_WRAP_INIT(Pm_Poll)
  PORTMIDI_WRAP_INIT(Pm_Write)
  PORTMIDI_WRAP_INIT(Pm_WriteShort)
  PORTMIDI_WRAP_INIT(Pm_WriteSysEx)

  }

  static auto& instance() {
    static portmidi c;
    return c;
  }
  
  PORTMIDI_WRAP_FUNCTION(Pm_Initialize, initialize)
  PORTMIDI_WRAP_FUNCTION(Pm_Terminate, terminate)
  PORTMIDI_WRAP_FUNCTION(Pm_HasHostError, has_host_error)
  PORTMIDI_WRAP_FUNCTION(Pm_GetErrorText, get_error_text)
  PORTMIDI_WRAP_FUNCTION(Pm_GetHostErrorText, get_host_error_text)
  PORTMIDI_WRAP_FUNCTION(Pm_CountDevices, count_devices)
  PORTMIDI_WRAP_FUNCTION(Pm_GetDefaultInputDeviceID, get_default_input_device_id)
  PORTMIDI_WRAP_FUNCTION(Pm_GetDefaultOutputDeviceID, get_default_output_device_id)
  PORTMIDI_WRAP_FUNCTION(Pm_GetDeviceInfo, get_device_info)
  PORTMIDI_WRAP_FUNCTION(Pm_OpenInput, open_input)
  PORTMIDI_WRAP_FUNCTION(Pm_OpenOutput, open_output)
  PORTMIDI_WRAP_FUNCTION(Pm_SetFilter, set_filter)
  PORTMIDI_WRAP_FUNCTION(Pm_SetChannelMask, set_channel_mask)
  PORTMIDI_WRAP_FUNCTION(Pm_Abort, abort)
  PORTMIDI_WRAP_FUNCTION(Pm_Close, close)
  PORTMIDI_WRAP_FUNCTION(Pm_Synchronize, synchronize)
  PORTMIDI_WRAP_FUNCTION(Pm_Read, read)
  PORTMIDI_WRAP_FUNCTION(Pm_Poll, poll)
  PORTMIDI_WRAP_FUNCTION(Pm_Write, write)
  PORTMIDI_WRAP_FUNCTION(Pm_WriteShort, write_short)
  PORTMIDI_WRAP_FUNCTION(Pm_WriteSysEx, write_sys_ex)


private:
  dynalizer::library m_lib;
};

#undef PORTMIDI_WRAP_FUNCTION
#undef PORTMIDI_WRAP_INIT
