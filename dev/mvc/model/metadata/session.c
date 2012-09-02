
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
#include "kernel/fcall.h"
#include "kernel/concat.h"

/**
 * Phalcon\Mvc\Model\MetaData\Session
 *
 * Stores model meta-data in session. Data will erase when the session finishes.
 * Meta-data are permanent while the session is active.
 *
 * You can query the meta-data by printing $_SESSION['$PMM$']
 *
 *<code>
 * $metaData = new Phalcon\Mvc\Model\Metadata\Session(array(
 *    'suffix' => 'my-app-id'
 * ));
 *</code>
 */

/**
 * Phalcon\Mvc\Model\MetaData\Session constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, __construct){

	zval *options = NULL, *suffix = NULL, *meta_data = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	eval_int = phalcon_array_isset_string(options, SL("suffix")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(suffix);
		phalcon_array_fetch_string(&suffix, options, SL("suffix"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_suffix"), suffix TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(meta_data);
	PHALCON_CALL_METHOD(meta_data, this_ptr, "read", PH_NO_CHECK);
	phalcon_update_property_zval(this_ptr, SL("_metaData"), meta_data TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Reads meta-data from $_SESSION
 *
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, read){

	zval *session = NULL, *suffix = NULL, *key = NULL, *meta_data = NULL;
	zval *g0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	PHALCON_CPY_WRT(session, g0);
	
	PHALCON_INIT_VAR(suffix);
	phalcon_read_property(&suffix, this_ptr, SL("_suffix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_SV(key, "$PMM$", suffix);
	eval_int = phalcon_array_isset(session, key);
	if (eval_int) {
		PHALCON_INIT_VAR(meta_data);
		phalcon_array_fetch(&meta_data, session, key, PH_NOISY_CC);
		
		RETURN_CCTOR(meta_data);
	}
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	
	RETURN_CTOR(a0);
}

/**
 * Writes the meta-data to $_SESSION
 *
 * @param array $data
 */
PHP_METHOD(Phalcon_Mvc_Model_MetaData_Session, write){

	zval *data = NULL, *suffix = NULL, *key = NULL;
	zval *g0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(suffix);
	phalcon_read_property(&suffix, this_ptr, SL("_suffix"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(key);
	PHALCON_CONCAT_SV(key, "$PMM$", suffix);
	phalcon_get_global(&g0, SL("_SESSION")+1 TSRMLS_CC);
	phalcon_array_update_zval(&g0, key, &data, PH_COPY TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

