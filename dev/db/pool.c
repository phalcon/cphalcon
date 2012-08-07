
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

#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Db\Pool
 *
 * Manages the caching of database connections. With the help of Phalcon\Db\Pool, developers can be
 * sure that no new database connections will created when calling multiple of times Phalcon\Db\Pool::getConnection().
 *
 *
 */

/**
 * Check if a default descriptor has already defined
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Pool, hasDefaultDescriptor){

	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_OBSERVE_VAR(t0);
	phalcon_read_static_property(&t0, SL("phalcon\\db\\pool"), SL("_defaultDescriptor") TSRMLS_CC);
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_not_identical_function(r0, t1, t0 TSRMLS_CC);
	
	RETURN_NCTOR(r0);
}

/**
 * Sets the default descriptor for creating database connections
 *
 * @param array $options
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Pool, setDefaultDescriptor){

	zval *options = NULL, *descriptor = NULL, *value = NULL, *key = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;
	char *hash_index;
	uint hash_index_len;
	ulong hash_num;
	int hash_type;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(options) != IS_ARRAY) { 
		if (Z_TYPE_P(options) != IS_OBJECT) {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The parameter 'options' must be an Array or Object");
			return;
		}
	}
	if (Z_TYPE_P(options) == IS_ARRAY) { 
		PHALCON_INIT_VAR(descriptor);
		object_init(descriptor);
		if (phalcon_valid_foreach(options TSRMLS_CC)) {
			ah0 = Z_ARRVAL_P(options);
			zend_hash_internal_pointer_reset_ex(ah0, &hp0);
			fes_162f_0:
			if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
				goto fee_162f_0;
			} else {
				PHALCON_INIT_VAR(key);
				PHALCON_GET_FOREACH_KEY(key, ah0, hp0);
			}
			PHALCON_INIT_VAR(value);
			ZVAL_ZVAL(value, *hd, 1, 0);
			phalcon_update_property_zval_zval(descriptor, key, value TSRMLS_CC);
			zend_hash_move_forward_ex(ah0, &hp0);
			goto fes_162f_0;
			fee_162f_0:
			if(0){}
		} else {
			return;
		}
	} else {
		PHALCON_CPY_WRT(descriptor, options);
	}
	
	phalcon_update_static_property(SL("phalcon\\db\\pool"), SL("_defaultDescriptor"), descriptor TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns a connection built with the default descriptor parameters
 *
 * @param boolean $newConnection
 * @param boolean $renovate
 * @return Phalcon\Db\Adapter
 */
PHP_METHOD(Phalcon_Db_Pool, getConnection){

	zval *new_connection = NULL, *renovate = NULL, *database = NULL, *connection = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|zz", &new_connection, &renovate) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!new_connection) {
		PHALCON_ALLOC_ZVAL_MM(new_connection);
		ZVAL_BOOL(new_connection, 0);
	}
	
	if (!renovate) {
		PHALCON_ALLOC_ZVAL_MM(renovate);
		ZVAL_BOOL(renovate, 0);
	}
	
	PHALCON_OBSERVE_VAR(database);
	phalcon_read_static_property(&database, SL("phalcon\\db\\pool"), SL("_defaultDescriptor") TSRMLS_CC);
	if (!zend_is_true(database)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Default database connection parameters was not defined");
		return;
	}
	
	eval_int = phalcon_isset_property(database, SL("adapter") TSRMLS_CC);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "A valid adapter name is required");
		return;
	}
	
	if (zend_is_true(new_connection)) {
		if (zend_is_true(renovate)) {
			PHALCON_ALLOC_ZVAL_MM(t0);
			phalcon_read_property(&t0, database, SL("adapter"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r0);
			PHALCON_CALL_STATIC_PARAMS_2(r0, "phalcon\\db", "factory", t0, database);
			phalcon_update_static_property(SL("phalcon\\db\\pool"), SL("_connection"), r0 TSRMLS_CC);
			PHALCON_OBSERVE_VAR(connection);
			phalcon_read_static_property(&connection, SL("phalcon\\db\\pool"), SL("_connection") TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(t1);
			phalcon_read_property(&t1, database, SL("adapter"), PH_NOISY_CC);
			PHALCON_INIT_VAR(connection);
			PHALCON_CALL_STATIC_PARAMS_2(connection, "phalcon\\db", "factory", t1, database);
		}
	} else {
		PHALCON_OBSERVE_VAR(t2);
		phalcon_read_static_property(&t2, SL("phalcon\\db\\pool"), SL("_connection") TSRMLS_CC);
		if (!zend_is_true(t2)) {
			PHALCON_ALLOC_ZVAL_MM(t3);
			phalcon_read_property(&t3, database, SL("adapter"), PH_NOISY_CC);
			PHALCON_ALLOC_ZVAL_MM(r1);
			PHALCON_CALL_STATIC_PARAMS_2(r1, "phalcon\\db", "factory", t3, database);
			phalcon_update_static_property(SL("phalcon\\db\\pool"), SL("_connection"), r1 TSRMLS_CC);
		}
		PHALCON_OBSERVE_VAR(connection);
		phalcon_read_static_property(&connection, SL("phalcon\\db\\pool"), SL("_connection") TSRMLS_CC);
	}
	
	
	RETURN_CCTOR(connection);
}

/**
 * Resets default descriptor and connection
 *
 */
PHP_METHOD(Phalcon_Db_Pool, reset){

	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(t0);
	ZVAL_NULL(t0);
	phalcon_update_static_property(SL("phalcon\\db\\pool"), SL("_connection"), t0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(t1);
	ZVAL_NULL(t1);
	phalcon_update_static_property(SL("phalcon\\db\\pool"), SL("_defaultDescriptor"), t1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

