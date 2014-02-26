
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

#ifndef PHALCON_VALIDATION_H
#define PHALCON_VALIDATION_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_validation_ce;

PHALCON_INIT_CLASS(Phalcon_Validation);

PHALCON_STATIC int phalcon_validation_getdefaultmessage_helper(const zend_class_entry *ce, zval **return_value_ptr, zval *this_ptr, const char *type TSRMLS_DC);

#endif /* PHALCON_VALIDATION_H */
