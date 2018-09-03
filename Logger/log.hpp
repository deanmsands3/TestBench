/*
 * log.hpp
 *        Name: Lightweight Logging Library for C++11
 *      Author: Filip Janiszewski
 *   Reference: http://www.drdobbs.com/cpp/a-lightweight-logger-for-c/240147505
 */

#ifndef LOG_HPP_
#define LOG_HPP_

#include "logger.hpp"
static logging::logger< logging::file_log_policy > log_inst( "execution.log" );

#define LOGGING_LEVEL_1

#ifdef LOGGING_LEVEL_1
#define LOG log_inst.print< logging::severity_type::debug >
#define LOG_ERR log_inst.print< logging::severity_type::error >
#define LOG_WARN log_inst.print< logging::severity_type::warning >
#else
#define LOG(...)
#define LOG_ERR(...)
#define LOG_WARN(...)
#endif

#ifdef LOGGING_LEVEL_2
#define ELOG log_inst.print< logging::severity_type::debug >
#define ELOG_ERR log_inst.print< logging::severity_type::error >
#define ELOG_WARN log_inst.print< logging::severity_type::warning >
#else
#define ELOG(...)
#define ELOG_ERR(...)
#define ELOG_WARN(...)
#endif

#endif /* LOG_HPP_ */
