#ifndef COREDEFINES_H
#define COREDEFINES_H

#if defined (_WIN32)
#if defined (Core_EXPORTS)
#define Core_EXPORT __declspec(dllexport)
#else
#define Core_EXPORT __declspec(dllimport)
#endif //defined (Core_EXPORTS)
#else
#define Core_EXPORT
#endif //defined (_WIN32)

#endif // COREDEFINES_H
