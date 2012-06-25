
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

#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
/**
 * Phalcon_Model_MetaData_Apc
 *
 * Stores model meta-data in the APC cache. Data will erased if the web server is restarted
 *
 * By default meta-data is stored 48 hours (172800 seconds)
 *
 * You can query the meta-data by printing apc_fetch('$PMM$') or apc_fetch('$PMM$my-local-app')
 *
 *
 */

/**
 * Phalcon_Model_MetaData_Apc constructor
 *
 * @param Phalcon_Config|stdClass $options
 */
PHP_METHOD(Phalcon_Model_MetaData_Apc, __construct){

	zval *options = NULL, *adapter_options = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(options);
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_cast(r0, options, IS_ARRAY);
		PHALCON_CPY_WRT(adapter_options, r0);
	} else {
		PHALCON_CPY_WRT(adapter_options, options);
	}
	eval_int = phalcon_isset_property(adapter_options, SL("suffix") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, adapter_options, SL("suffix"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_suffix"), t0 TSRMLS_CC);
	}
	
	eval_int = phalcon_isset_property(adapter_options, SL("lifetime") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, adapter_options, SL("lifetime"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_ttl"), t1 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from APC
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData_Apc, read){

	zval *key = NULL, *data = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_suffix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SV(r0, "$PMM$", t0);
	PHALCON_CPY_WRT(key, r0);
	
	PHALCON_INIT_VAR(data);
	PHALCON_CALL_FUNC_PARAMS_1(data, "apc_fetch", key);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		
		RETURN_CHECK_CTOR(data);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Writes the meta-data to APC
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Model_MetaData_Apc, write){

	zval *data = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_suffix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SV(r0, "$PMM$", t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_ttl"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("apc_store", r0, data, t1);
	
	PHALCON_MM_RESTORE();
}

