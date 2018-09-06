#pragma once
#include <dynalizer/dynalizer.hpp>
#include <zstd.h>
#include <stdexcept>

#define ZSTD_WRAP_INIT(Fun)                                   \
m_sym_ ## Fun = m_lib.symbol<decltype(::Fun)*>(# Fun);           \
if(!m_sym_ ## Fun)                                               \
    throw std::runtime_error("Invalid symbol lookup: Fun");

#define ZSTD_WRAP_FUNCTION(Fun, PrettyFun)                    \
public:                                                          \
template<typename... Args>                                       \
auto PrettyFun(Args&&... args) -> decltype(auto)                 \
{                                                                \
  return m_sym_ ## Fun(std::forward<Args>(args)...);             \
}                                                                \
private:                                                         \
  decltype(::Fun)* m_sym_ ## Fun{};


class zstd
{
public:
  explicit zstd(const char* filepath)
    : m_lib{filepath}
  {
  
  ZSTD_WRAP_INIT(ZSTD_versionNumber)
  ZSTD_WRAP_INIT(ZSTD_versionString)
  ZSTD_WRAP_INIT(ZSTD_compress)
  ZSTD_WRAP_INIT(ZSTD_decompress)
  ZSTD_WRAP_INIT(ZSTD_getFrameContentSize)
  ZSTD_WRAP_INIT(ZSTD_getDecompressedSize)
  ZSTD_WRAP_INIT(ZSTD_compressBound)
  ZSTD_WRAP_INIT(ZSTD_isError)
  ZSTD_WRAP_INIT(ZSTD_getErrorName)
  ZSTD_WRAP_INIT(ZSTD_maxCLevel)
  ZSTD_WRAP_INIT(ZSTD_createCCtx)
  ZSTD_WRAP_INIT(ZSTD_freeCCtx)
  ZSTD_WRAP_INIT(ZSTD_compressCCtx)
  ZSTD_WRAP_INIT(ZSTD_createDCtx)
  ZSTD_WRAP_INIT(ZSTD_freeDCtx)
  ZSTD_WRAP_INIT(ZSTD_decompressDCtx)
  ZSTD_WRAP_INIT(ZSTD_compress_usingDict)
  ZSTD_WRAP_INIT(ZSTD_decompress_usingDict)
  ZSTD_WRAP_INIT(ZSTD_createCDict)
  ZSTD_WRAP_INIT(ZSTD_freeCDict)
  ZSTD_WRAP_INIT(ZSTD_compress_usingCDict)
  ZSTD_WRAP_INIT(ZSTD_createDDict)
  ZSTD_WRAP_INIT(ZSTD_freeDDict)
  ZSTD_WRAP_INIT(ZSTD_decompress_usingDDict)
  ZSTD_WRAP_INIT(ZSTD_createCStream)
  ZSTD_WRAP_INIT(ZSTD_freeCStream)
  ZSTD_WRAP_INIT(ZSTD_initCStream)
  ZSTD_WRAP_INIT(ZSTD_compressStream)
  ZSTD_WRAP_INIT(ZSTD_flushStream)
  ZSTD_WRAP_INIT(ZSTD_endStream)
  ZSTD_WRAP_INIT(ZSTD_CStreamInSize)
  ZSTD_WRAP_INIT(ZSTD_CStreamOutSize)
  ZSTD_WRAP_INIT(ZSTD_createDStream)
  ZSTD_WRAP_INIT(ZSTD_freeDStream)
  ZSTD_WRAP_INIT(ZSTD_initDStream)
  ZSTD_WRAP_INIT(ZSTD_decompressStream)
  ZSTD_WRAP_INIT(ZSTD_DStreamInSize)
  ZSTD_WRAP_INIT(ZSTD_DStreamOutSize)

  }

  static auto& instance() {
    static zstd c;
    return c;
  }
  
  ZSTD_WRAP_FUNCTION(ZSTD_versionNumber, version_number)
  ZSTD_WRAP_FUNCTION(ZSTD_versionString, version_string)
  ZSTD_WRAP_FUNCTION(ZSTD_compress, compress)
  ZSTD_WRAP_FUNCTION(ZSTD_decompress, decompress)
  ZSTD_WRAP_FUNCTION(ZSTD_getFrameContentSize, get_frame_content_size)
  ZSTD_WRAP_FUNCTION(ZSTD_getDecompressedSize, get_decompressed_size)
  ZSTD_WRAP_FUNCTION(ZSTD_compressBound, compress_bound)
  ZSTD_WRAP_FUNCTION(ZSTD_isError, is_error)
  ZSTD_WRAP_FUNCTION(ZSTD_getErrorName, get_error_name)
  ZSTD_WRAP_FUNCTION(ZSTD_maxCLevel, max_c_level)
  ZSTD_WRAP_FUNCTION(ZSTD_createCCtx, create_c_ctx)
  ZSTD_WRAP_FUNCTION(ZSTD_freeCCtx, free_c_ctx)
  ZSTD_WRAP_FUNCTION(ZSTD_compressCCtx, compress_c_ctx)
  ZSTD_WRAP_FUNCTION(ZSTD_createDCtx, create_d_ctx)
  ZSTD_WRAP_FUNCTION(ZSTD_freeDCtx, free_d_ctx)
  ZSTD_WRAP_FUNCTION(ZSTD_decompressDCtx, decompress_d_ctx)
  ZSTD_WRAP_FUNCTION(ZSTD_compress_usingDict, compress_using_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_decompress_usingDict, decompress_using_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_createCDict, create_c_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_freeCDict, free_c_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_compress_usingCDict, compress_using_c_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_createDDict, create_d_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_freeDDict, free_d_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_decompress_usingDDict, decompress_using_d_dict)
  ZSTD_WRAP_FUNCTION(ZSTD_createCStream, create_c_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_freeCStream, free_c_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_initCStream, init_c_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_compressStream, compress_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_flushStream, flush_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_endStream, end_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_CStreamInSize, c_stream_in_size)
  ZSTD_WRAP_FUNCTION(ZSTD_CStreamOutSize, c_stream_out_size)
  ZSTD_WRAP_FUNCTION(ZSTD_createDStream, create_d_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_freeDStream, free_d_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_initDStream, init_d_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_decompressStream, decompress_stream)
  ZSTD_WRAP_FUNCTION(ZSTD_DStreamInSize, d_stream_in_size)
  ZSTD_WRAP_FUNCTION(ZSTD_DStreamOutSize, d_stream_out_size)


private:
  dynalizer::library m_lib;
};

#undef ZSTD_WRAP_FUNCTION
#undef ZSTD_WRAP_INIT
