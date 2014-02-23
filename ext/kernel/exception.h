
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#ifndef PHALCON_KERNEL_EXCEPTION_H
#define PHALCON_KERNEL_EXCEPTION_H

#include "php_phalcon.h"

/** Exceptions */
#define PHALCON_THROW_EXCEPTION_STR(class_entry, message) \
	do { \
		phalcon_throw_exception_string(class_entry, message TSRMLS_CC); \
		PHALCON_MM_RESTORE(); \
	} while (0)

#define PHALCON_THROW_EXCEPTION_ZVAL(class_entry, message) \
	do { \
		phalcon_throw_exception_zval(class_entry, message TSRMLS_CC); \
		PHALCON_MM_RESTORE(); \
	} while (0)

#define PHALCON_THROW_EXCEPTION_STRW(class_entry, message)  phalcon_throw_exception_string(class_entry, message TSRMLS_CC)
#define PHALCON_THROW_EXCEPTION_ZVALW(class_entry, message) phalcon_throw_exception_zval(class_entry, message TSRMLS_CC)

/** Throw Exceptions */
void phalcon_throw_exception(zval *object TSRMLS_DC) PHALCON_ATTR_NONNULL;
void phalcon_throw_exception_string(zend_class_entry *ce, const char *message TSRMLS_DC) PHALCON_ATTR_NONNULL;
void phalcon_throw_exception_zval(zend_class_entry *ce, zval *message TSRMLS_DC) PHALCON_ATTR_NONNULL;

#endif /* PHALCON_KERNEL_EXCEPTION_H */
