
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

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Mvc\Model\MetaData\Apc
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
 * Phalcon\Mvc\Model\MetaData\Apc constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, __construct){

	zval *options = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(options, SL("suffix")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, options, SL("suffix"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_suffix"), r0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(options, SL("lifetime")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, options, SL("lifetime"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_ttl"), r1 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from APC
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, read){

	zval *key = NULL, *data = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_suffix"), PH_NOISY_CC);
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_SV(key, "$PMM$", t0);
	
	PHALCON_INIT_VAR(data);
	PHALCON_CALL_FUNC_PARAMS_1(data, "apc_fetch", key);
	if (Z_TYPE_P(data) == IS_ARRAY) { 
		
		RETURN_CCTOR(data);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Writes the meta-data to APC
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Apc, write){

	zval *data = NULL, *key = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_suffix"), PH_NOISY_CC);
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_SV(key, "$PMM$", t0);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_ttl"), PH_NOISY_CC);
	PHALCON_CALL_FUNC_PARAMS_3_NORETURN("apc_store", key, data, t1);
	
	PHALCON_MM_RESTORE();
}

