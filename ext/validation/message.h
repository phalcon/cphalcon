
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

#ifndef PHALCON_VALIDATION_MESSAGE_H
#define PHALCON_VALIDATION_MESSAGE_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_validation_message_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Message);

PHALCON_STATIC zval* phalcon_validation_message_construct_helper(zval *message, zval *field, const char *type, zval *code TSRMLS_DC) PHALCON_ATTR_NONNULL;

#endif /* PHALCON_VALIDATION_MESSAGE_H */
