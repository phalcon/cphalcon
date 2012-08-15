
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
 * Phalcon\Db\Reference
 *
 * Allows to define reference constraints on tables
 *
 *
 */

/**
 * Phalcon\Db\Reference constructor
 *
 * @param string $referenceName
 * @param array $definition
 */
PHP_METHOD(Phalcon_Db_Reference, __construct){

	zval *reference_name = NULL, *definition = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &reference_name, &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_referenceName"), reference_name TSRMLS_CC);
	eval_int = phalcon_array_isset_string(definition, SL("referencedTable")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, definition, SL("referencedTable"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_referencedTable"), r0 TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced table is required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, definition, SL("columns"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_columns"), r1 TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Foreign key columns are required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("referencedColumns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, definition, SL("referencedColumns"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_referencedColumns"), r2 TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced columns of the foreign key are required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("schema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, definition, SL("schema"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_schema"), r3 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("referencedSchema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, definition, SL("referencedSchema"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_referencedSchema"), r4 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_columns"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_fast_count(r5, t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, SL("_referencedColumns"), PH_NOISY_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_fast_count(r6, t1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_not_equal_function(r7, r5, r6 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Number of columns is not equals than the number of columns referenced");
		return;
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the index name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_referenceName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getSchemaName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_schemaName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_referencedSchema"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_columns"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets the referenced table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_referencedTable"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Gets referenced columns
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_referencedColumns"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Restore a Phalcon\Db\Reference object from export
 *
 * @param array $data
 * @return Phalcon\Db\Reference
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state){

	zval *data = NULL, *constraint_name = NULL, *referenced_schema = NULL;
	zval *referenced_table = NULL, *columns = NULL, *referenced_columns = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(data, SL("_referenceName")+1);
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "_referenceName parameter is required");
		return;
	} else {
		PHALCON_INIT_VAR(constraint_name);
		phalcon_array_fetch_string(&constraint_name, data, SL("_referenceName"), PH_NOISY_CC);
	}
	eval_int = phalcon_array_isset_string(data, SL("_referencedSchema")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, data, SL("_referencedSchema"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(referenced_schema);
		ZVAL_NULL(referenced_schema);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_referencedTable")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, data, SL("_referencedTable"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(referenced_table);
		ZVAL_NULL(referenced_table);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_columns")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(columns);
		phalcon_array_fetch_string(&columns, data, SL("_columns"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(columns);
		ZVAL_NULL(columns);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_referencedColumns")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, data, SL("_referencedColumns"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(referenced_columns);
		ZVAL_NULL(referenced_columns);
	}
	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_db_reference_ce);
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	phalcon_array_update_string(&a0, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&a0, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&a0, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&a0, SL("referencedColumns"), &referenced_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i0, "__construct", constraint_name, a0, PH_CHECK);
	
	RETURN_CTOR(i0);
}

