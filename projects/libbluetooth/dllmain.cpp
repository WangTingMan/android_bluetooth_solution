#include <windows.h>
#include <string>

#include <base/logging.h>
#include <log/log.h>

bool baseLoggingHandler( int levelIn, const char* file, int line,
                         size_t message_start, const std::string& str );

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        logging::SetLogMessageHandler( baseLoggingHandler );
    break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

bool baseLoggingHandler(int levelIn, const char* file, int line,
                        size_t message_start, const std::string& str)
{
    android_LogPriority level = ANDROID_LOG_VERBOSE;
    switch (levelIn) {
        case logging::LOG_VERBOSE:
            level = ANDROID_LOG_VERBOSE;
            break;
        case logging::LOG_INFO:
            level = ANDROID_LOG_INFO;
            break;
        case logging::LOG_WARNING:
            level = ANDROID_LOG_WARN;
            break;
        case logging::LOG_ERROR:
            level = ANDROID_LOG_ERROR;
            break;
        case logging::LOG_FATAL:
            level = ANDROID_LOG_FATAL;
            break;
        case logging::LOG_NUM_SEVERITIES:
            level = ANDROID_LOG_VERBOSE;
            break;
        default:
            break;
    }
    std::string logStr;
    if (str.size() > message_start) {
        logStr = str.substr(message_start);
    }

    struct __android_log_message message = {
      .struct_size = sizeof( __android_log_message ),
      .buffer_id = LOG_ID_MAIN,
      .priority = static_cast<android_LogPriority>( level ),
      .tag = nullptr,
      .file = file,
      .line = static_cast<uint32_t>( line ),
      .message = logStr.c_str(),
    };

    __android_log_write_log_message( &message );
    return true;
}
