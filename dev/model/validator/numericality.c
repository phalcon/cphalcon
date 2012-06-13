
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Model_Validator_Numericality
 *
 *
 */

/**
 * Executes the validator
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Model_Validator_Numericality, validate){

	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_METHOD(r0, this_ptr, "isrequired", PHALCON_NO_CHECK);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_METHOD(r2, this_ptr, "getvalue", PHALCON_NO_CHECK);
		PHALCON_CALL_FUNC_PARAMS_1(r1, "is_numeric", r2, 0x02B);
		if (!zend_is_true(r1)) {
			PHALCON_ALLOC_ZVAL_MM(r3);
			PHALCON_ALLOC_ZVAL_MM(r4);
			PHALCON_CALL_METHOD(r4, this_ptr, "getfieldname", PHALCON_NO_CHECK);
			PHALCON_CONCAT_SVS(r3, "Value of field '", r4, "' must be numeric");
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(this_ptr, "appendmessage", r3, PHALCON_NO_CHECK);
			PHALCON_MM_RESTORE();
			RETURN_FALSE;
		}
	}
	PHALCON_MM_RESTORE();
	RETURN_TRUE;
}

