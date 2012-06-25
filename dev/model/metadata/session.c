
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
#include "kernel/array.h"
/**
 * Phalcon_Model_MetaData_Session
 *
 * Stores model meta-data in session. Data will erase when the session finishes.
 * Meta-data are permanent while the session is active.
 *
 * You can query the meta-data by printing $_SESSION['$PMM$']
 *
 *
 */

/**
 * Phalcon_Model_MetaData_Session constructor
 *
 * @param Phalcon_Config|stdClass $options
 */
PHP_METHOD(Phalcon_Model_MetaData_Session, __construct){

	zval *options = NULL, *adapter_options = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;
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
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from $_SESSION
 *
 * @return array
 */
PHP_METHOD(Phalcon_Model_MetaData_Session, read){

	zval *session = NULL, *key = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	zval *t0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(session, g0);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_suffix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SV(r0, "$PMM$", t0);
	PHALCON_CPY_WRT(key, r0);
	eval_int = phalcon_array_isset(session, key);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch(&r1, session, key, PHALCON_NOISY TSRMLS_CC);
		
		RETURN_CHECK_CTOR(r1);
	}
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Writes the meta-data to $_SESSION
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Model_MetaData_Session, write){

	zval *data = NULL;
	zval *g0 = NULL;
	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_suffix"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CONCAT_SV(r0, "$PMM$", t0);
	phalcon_array_update(&g0, r0, &data, PHALCON_NO_SEPARATE_THX, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

