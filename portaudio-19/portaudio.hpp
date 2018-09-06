#pragma once
#include <dynalizer/dynalizer.hpp>
#include <portaudio.h>
#include <stdexcept>

#define PORTAUDIO_WRAP_INIT(Fun)                                   \
m_sym_ ## Fun = m_lib.symbol<decltype(::Fun)*>(# Fun);           \
if(!m_sym_ ## Fun)                                               \
    throw std::runtime_error("Invalid symbol lookup: Fun");

#define PORTAUDIO_WRAP_FUNCTION(Fun, PrettyFun)                    \
public:                                                          \
template<typename... Args>                                       \
auto PrettyFun(Args&&... args) -> decltype(auto)                 \
{                                                                \
  return m_sym_ ## Fun(std::forward<Args>(args)...);             \
}                                                                \
private:                                                         \
  decltype(::Fun)* m_sym_ ## Fun{};


class portaudio
{
public:
  explicit portaudio(const char* filepath)
    : m_lib{filepath}
  {
  
  PORTAUDIO_WRAP_INIT(Pa_GetVersion)
  PORTAUDIO_WRAP_INIT(Pa_GetVersionText)
  PORTAUDIO_WRAP_INIT(Pa_GetVersionInfo)
  PORTAUDIO_WRAP_INIT(Pa_GetErrorText)
  PORTAUDIO_WRAP_INIT(Pa_Initialize)
  PORTAUDIO_WRAP_INIT(Pa_Terminate)
  PORTAUDIO_WRAP_INIT(Pa_GetHostApiCount)
  PORTAUDIO_WRAP_INIT(Pa_GetDefaultHostApi)
  PORTAUDIO_WRAP_INIT(Pa_GetHostApiInfo)
  PORTAUDIO_WRAP_INIT(Pa_HostApiTypeIdToHostApiIndex)
  PORTAUDIO_WRAP_INIT(Pa_HostApiDeviceIndexToDeviceIndex)
  PORTAUDIO_WRAP_INIT(Pa_GetLastHostErrorInfo)
  PORTAUDIO_WRAP_INIT(Pa_GetDeviceCount)
  PORTAUDIO_WRAP_INIT(Pa_GetDefaultInputDevice)
  PORTAUDIO_WRAP_INIT(Pa_GetDefaultOutputDevice)
  PORTAUDIO_WRAP_INIT(Pa_GetDeviceInfo)
  PORTAUDIO_WRAP_INIT(Pa_IsFormatSupported)
  PORTAUDIO_WRAP_INIT(Pa_OpenStream)
  PORTAUDIO_WRAP_INIT(Pa_OpenDefaultStream)
  PORTAUDIO_WRAP_INIT(Pa_CloseStream)
  PORTAUDIO_WRAP_INIT(Pa_SetStreamFinishedCallback)
  PORTAUDIO_WRAP_INIT(Pa_StartStream)
  PORTAUDIO_WRAP_INIT(Pa_StopStream)
  PORTAUDIO_WRAP_INIT(Pa_AbortStream)
  PORTAUDIO_WRAP_INIT(Pa_IsStreamStopped)
  PORTAUDIO_WRAP_INIT(Pa_IsStreamActive)
  PORTAUDIO_WRAP_INIT(Pa_GetStreamInfo)
  PORTAUDIO_WRAP_INIT(Pa_GetStreamTime)
  PORTAUDIO_WRAP_INIT(Pa_GetStreamCpuLoad)
  PORTAUDIO_WRAP_INIT(Pa_ReadStream)
  PORTAUDIO_WRAP_INIT(Pa_WriteStream)
  PORTAUDIO_WRAP_INIT(Pa_GetStreamReadAvailable)
  PORTAUDIO_WRAP_INIT(Pa_GetStreamWriteAvailable)
  PORTAUDIO_WRAP_INIT(Pa_GetSampleSize)
  PORTAUDIO_WRAP_INIT(Pa_Sleep)

  }

  static auto& instance() {
    static portaudio c;
    return c;
  }
  
  PORTAUDIO_WRAP_FUNCTION(Pa_GetVersion, get_version)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetVersionText, get_version_text)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetVersionInfo, get_version_info)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetErrorText, get_error_text)
  PORTAUDIO_WRAP_FUNCTION(Pa_Initialize, initialize)
  PORTAUDIO_WRAP_FUNCTION(Pa_Terminate, terminate)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetHostApiCount, get_host_api_count)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetDefaultHostApi, get_default_host_api)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetHostApiInfo, get_host_api_info)
  PORTAUDIO_WRAP_FUNCTION(Pa_HostApiTypeIdToHostApiIndex, host_api_type_id_to_host_api_index)
  PORTAUDIO_WRAP_FUNCTION(Pa_HostApiDeviceIndexToDeviceIndex, host_api_device_index_to_device_index)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetLastHostErrorInfo, get_last_host_error_info)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetDeviceCount, get_device_count)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetDefaultInputDevice, get_default_input_device)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetDefaultOutputDevice, get_default_output_device)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetDeviceInfo, get_device_info)
  PORTAUDIO_WRAP_FUNCTION(Pa_IsFormatSupported, is_format_supported)
  PORTAUDIO_WRAP_FUNCTION(Pa_OpenStream, open_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_OpenDefaultStream, open_default_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_CloseStream, close_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_SetStreamFinishedCallback, set_stream_finished_callback)
  PORTAUDIO_WRAP_FUNCTION(Pa_StartStream, start_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_StopStream, stop_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_AbortStream, abort_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_IsStreamStopped, is_stream_stopped)
  PORTAUDIO_WRAP_FUNCTION(Pa_IsStreamActive, is_stream_active)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetStreamInfo, get_stream_info)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetStreamTime, get_stream_time)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetStreamCpuLoad, get_stream_cpu_load)
  PORTAUDIO_WRAP_FUNCTION(Pa_ReadStream, read_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_WriteStream, write_stream)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetStreamReadAvailable, get_stream_read_available)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetStreamWriteAvailable, get_stream_write_available)
  PORTAUDIO_WRAP_FUNCTION(Pa_GetSampleSize, get_sample_size)
  PORTAUDIO_WRAP_FUNCTION(Pa_Sleep, sleep)


private:
  dynalizer::library m_lib;
};

#undef PORTAUDIO_WRAP_FUNCTION
#undef PORTAUDIO_WRAP_INIT
