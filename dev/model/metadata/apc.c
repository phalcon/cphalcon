
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
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(options);
	
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_SEPARATE_PARAM(options);
		convert_to_array(options);
		PHALCON_CPY_WRT(adapter_options, options);
	}
	eval_int = phalcon_isset_property(adapter_options, "suffix", strlen("suffix") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, adapter_options, "suffix", sizeof("suffix")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_suffix", strlen("_suffix"), t0 TSRMLS_CC);
	}
	
	eval_int = phalcon_isset_property(adapter_options, "lifetime", strlen("lifetime") TSRMLS_CC);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t1);
		phalcon_read_property(&t1, adapter_options, "lifetime", sizeof("lifetime")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_ttl", strlen("_ttl"), t1 TSRMLS_CC);
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
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_suffix", sizeof("_suffix")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SV(r0, "$PMM$", t0);
	PHALCON_CPY_WRT(key, r0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_1(r1, "apc_fetch", key, 0x05B);
	PHALCON_CPY_WRT(data, r1);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		
		PHALCON_RETURN_CHECK_CTOR(data);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	
	PHALCON_RETURN_CTOR(a0);
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
	phalcon_read_property(&t0, this_ptr, "_suffix", sizeof("_suffix")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SV(r0, "$PMM$", t0);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_ttl", sizeof("_ttl")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("apc_store", r0, data, t1, 0x05C);
	
	PHALCON_MM_RESTORE();
}

