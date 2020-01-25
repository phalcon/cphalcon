
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Phalcon Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifndef ZEPHIR_KERNEL_EXCEPTIONS_H
#define ZEPHIR_KERNEL_EXCEPTIONS_H

#include <Zend/zend.h>
#include "kernel/main.h"

/** Exceptions */
#define ZEPHIR_THROW_EXCEPTION_STR(class_entry, message) \
	do { \
		zephir_throw_exception_string(class_entry, message, strlen(message)); \
		ZEPHIR_MM_RESTORE(); \
	} while (0)

#define ZEPHIR_THROW_EXCEPTION_DEBUG_STR(class_entry, message, file, line) \
  do { \
    zephir_throw_exception_string_debug(class_entry, message, strlen(message), file, line); \
    ZEPHIR_MM_RESTORE(); \
  } while (0)

#define ZEPHIR_THROW_EXCEPTION_ZVAL(class_entry, message) \
	do { \
		zephir_throw_exception_zval(class_entry, message); \
		ZEPHIR_MM_RESTORE(); \
	} while (0)

#define ZEPHIR_THROW_EXCEPTION_DEBUG_ZVAL(class_entry, message, file, line) \
  do { \
    zephir_throw_exception_zval(class_entry, message, file, line); \
    ZEPHIR_MM_RESTORE(); \
  } while (0)


#define ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(class_entry, message, file, line) zephir_throw_exception_string_debug(class_entry, message, strlen(message), file, line)
#define ZEPHIR_THROW_EXCEPTION_STRW(class_entry, message) zephir_throw_exception_string(class_entry, message, strlen(message))
#define ZEPHIR_THROW_EXCEPTION_ZVALW(class_entry, message) zephir_throw_exception_zval(class_entry, message)
#define ZEPHIR_THROW_EXCEPTION_DEBUG_ZVALW(class_entry, message, file, line) zephir_throw_exception_zval_debug(class_entry, message, file, line)

/** Throw Exceptions */
void zephir_throw_exception_string(zend_class_entry *ce, const char *message, uint32_t message_len);
void zephir_throw_exception_debug(zval *object, const char *file, uint32_t line);
void zephir_throw_exception_format(zend_class_entry *ce, const char *format, ...);
void zephir_throw_exception_string_debug(zend_class_entry *ce, const char *message, uint32_t message_len, const char *file, uint32_t line);

#endif /* ZEPHIR_KERNEL_EXCEPTIONS_H */
