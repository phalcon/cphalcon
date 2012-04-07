
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 *
 * Phalcon_Acl_Resource
 *
 * This class defines resource entity and its description
 *
 */

/**
 * Phalcon_Acl_Resource description
 *
 * @param string $name
 * @param string $description
 */
PHP_METHOD(Phalcon_Acl_Resource, __construct){

	zval *v0 = NULL, *v1 = NULL;
	zval *i0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(v1);
		ZVAL_STRING(v1, "", 1);
	}
	
	if (PHALCON_COMPARE_STRING(v0, "*")) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Resource name cannot be \"*\"", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	phalcon_update_property_zval(this_ptr, "_name", strlen("_name"), v0 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_description", strlen("_description"), v1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the resource name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Resource, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_name", sizeof("_name")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns resource description
 *
 * @return string
 */
PHP_METHOD(Phalcon_Acl_Resource, getDescription){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_description", sizeof("_description")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

