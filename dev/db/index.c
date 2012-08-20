
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Db\Index
 *
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index.
 *
 * 
 *
 */

/**
 * Phalcon\Db\Index constructor
 *
 * @param string $indexName
 * @param array $columns
 */
PHP_METHOD(Phalcon_Db_Index, __construct){

	zval *index_name = NULL, *columns = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index_name, &columns) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_indexName"), index_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_columns"), columns TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the index name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Index, getName){

	zval *index_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(index_name);
	phalcon_read_property(&index_name, this_ptr, SL("_indexName"), PH_NOISY_CC);
	
	RETURN_CCTOR(index_name);
}

/**
 * Gets the columns that comprends the index
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Index, getColumns){

	zval *columns = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(columns);
	phalcon_read_property(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	
	RETURN_CCTOR(columns);
}

/**
 * Restore a Phalcon\Db\Index object from export
 *
 * @param array $data
 * @return Phalcon\Db\Index
 */
PHP_METHOD(Phalcon_Db_Index, __set_state){

	zval *data = NULL, *index_name = NULL, *columns = NULL, *index = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(data, SL("_indexName")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "_indexName parameter is required");
		return;
	}
	eval_int = phalcon_array_isset_string(data, SL("_columns")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "_columns parameter is required");
		return;
	}
	
	PHALCON_INIT_VAR(index_name);
	phalcon_array_fetch_string(&index_name, data, SL("_indexName"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(columns);
	phalcon_array_fetch_string(&columns, data, SL("_columns"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(index);
	object_init_ex(index, phalcon_db_index_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(index, "__construct", index_name, columns, PH_CHECK);
	
	RETURN_CTOR(index);
}

