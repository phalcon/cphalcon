
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

#ifndef PHALCON_VALIDATION_VALIDATOR_H
#define PHALCON_VALIDATION_VALIDATOR_H

#include "php_phalcon.h"

extern zend_class_entry *phalcon_validation_validator_ce;

PHALCON_INIT_CLASS(Phalcon_Validation_Validator);

PHALCON_STATIC int phalcon_validation_validator_getoption_helper(const zend_class_entry *ce, zval **result, zval *this_ptr, const char *option TSRMLS_DC);

static inline int phalcon_validation_validator_isempty_helper(const zval *v)
{
	return
			Z_TYPE_P(v) == IS_NULL
		 || (Z_TYPE_P(v) == IS_STRING && !Z_STRLEN_P(v))
		 || (Z_TYPE_P(v) == IS_ARRAY && !zend_hash_num_elements(Z_ARRVAL_P(v)))
	;
}

#endif /* PHALCON_VALIDATION_VALIDATOR_H */
