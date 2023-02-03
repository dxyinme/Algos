#pragma once
#ifndef BASELIB_LOG_HPP_
#define BASELIB_LOG_HPP_
#include <cstdio>
#include <stdarg.h>

namespace baselib
{
  const int INFO = 0;
  const int WARN = 1;
  const int ERRO = 2;
  const int LOG_BUFF_SIZE = 4096;
  static const char *log_levels[] = {
      "INFO",
      "WARN",
      "ERRO"};

  static void
  Out(int level, const char *filename, int line_number, const char *msg)
  {
    fprintf(stdout, "[%s|%s:line:%d]%s\n", log_levels[level], filename, line_number, msg);
  }

  static void Outf(const char *format, ...)
  {
    va_list ap;
    va_start(ap, format);
    static char log_buf[LOG_BUFF_SIZE];
    vsnprintf(log_buf, LOG_BUFF_SIZE, format, ap);
    va_end(ap);
    fprintf(stdout, "msg: %s\n", log_buf);
  }

} // namespace baselib

#define INFO(msg) baselib::Out(baselib::INFO, __FILE__, __LINE__, msg)
#define WARN(msg) baselib::Out(baselib::WARN, __FILE__, __LINE__, msg)
#define ERRO(msg) baselib::Out(baselib::ERRO, __FILE__, __LINE__, msg)

#endif