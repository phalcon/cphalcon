
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
/**
 * Phalcon_Acl
 *
 * This component allows to manage ACL lists. An access control list (ACL) is a list
 * of permissions attached to an object. An ACL specifies which users or system processes
 * are granted access to objects, as well as what operations are allowed on given objects.
 *
 *
 */

/**
 * Phalcon_Acl Constructor
 *
 * @param string $adapterName
 * @param array $options
 */
PHP_METHOD(Phalcon_Acl, __construct){

	zval *adapter_name = NULL, *options = NULL, *adapter_class = NULL;
	zval *a0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &adapter_name, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!adapter_name) {
		PHALCON_INIT_VAR(adapter_name);
		ZVAL_STRING(adapter_name, "Memory", 1);
	}
	
	if (!options) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(options, a0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CONCAT_SV(r0, "Phalcon_Acl_Adapter_", adapter_name);
	PHALCON_CPY_WRT(adapter_class, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "class_exists", adapter_class);
	if (!zend_is_true(r1)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_acl_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_SVS(r2, "Adapter '", adapter_name, "' does not exist");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	ce0 = phalcon_fetch_class(adapter_class TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, ce0);
	PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", options, PHALCON_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_adapter"), i1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Pass any call to the internal adapter object
 *
 * @param  string $method
 * @param  array $arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Acl, __call){

	zval *method = NULL, *arguments = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &method, &arguments) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!arguments) {
		PHALCON_INIT_VAR(a0);
		array_init(a0);
		PHALCON_CPY_WRT(arguments, a0);
	}
	
	PHALCON_INIT_VAR(a1);
	array_init(a1);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_adapter"), PHALCON_NOISY TSRMLS_CC);
	phalcon_array_append(&a1, t0, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	phalcon_array_append(&a1, method, PHALCON_SEPARATE_PLZ TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "call_user_func_array", a1, arguments);
	RETURN_DZVAL(r0);
}

