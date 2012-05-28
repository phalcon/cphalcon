
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
#include "kernel/memory.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Db_Reference
 *
 * Allows to define reference constraints on tables
 *
 *
 */

/**
 * Phalcon_Db_Reference constructor
 *
 * @param string $indexName
 * @param array $columns
 */
PHP_METHOD(Phalcon_Db_Reference, __construct){

	zval *reference_name = NULL, *definition = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL, *c3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &reference_name, &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_referenceName", strlen("_referenceName"), reference_name TSRMLS_CC);
	eval_int = phalcon_array_isset_string(definition, "referencedTable", strlen("referencedTable")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, definition, "referencedTable", strlen("referencedTable"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedTable", strlen("_referencedTable"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Referenced table is required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, definition, "columns", strlen("columns"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "Foreign key columns are required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, "referencedColumns", strlen("referencedColumns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, definition, "referencedColumns", strlen("referencedColumns"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedColumns", strlen("_referencedColumns"), r2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c2);
		ZVAL_STRING(c2, "Referenced columns of the foreign key are required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", c2, PHALCON_CHECK);
		phalcon_throw_exception(i2 TSRMLS_CC);
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, "schema", strlen("schema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, definition, "schema", strlen("schema"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), r3 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, "referencedSchema", strlen("referencedSchema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, definition, "referencedSchema", strlen("referencedSchema"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedSchema", strlen("_referencedSchema"), r4 TSRMLS_CC);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	phalcon_fast_count(r5, t0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_referencedColumns", sizeof("_referencedColumns")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r6);
	phalcon_fast_count(r6, t1 TSRMLS_CC);
	
	PHALCON_INIT_VAR(r7);
	is_not_equal_function(r7, r5, r6 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c3);
		ZVAL_STRING(c3, "Number of columns is not equals than the number of columns referenced", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i3, "__construct", c3, PHALCON_CHECK);
		phalcon_throw_exception(i3 TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_referenceName", sizeof("_referenceName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_schemaName", sizeof("_schemaName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_referencedSchema", sizeof("_referencedSchema")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_referencedTable", sizeof("_referencedTable")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, "_referencedColumns", sizeof("_referencedColumns")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Restore a Phalcon_Db_Reference object from export
 *
 * @param array $data
 * @return Phalcon_Db_Reference
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state){

	zval *data = NULL, *constraint_name = NULL, *referenced_schema = NULL;
	zval *referenced_table = NULL, *columns = NULL, *referenced_columns = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(data, "_referenceName", strlen("_referenceName")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "_referenceName parameter is required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	} else {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, data, "_referenceName", strlen("_referenceName"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(constraint_name, r0);
	}
	eval_int = phalcon_array_isset_string(data, "_referencedSchema", strlen("_referencedSchema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, data, "_referencedSchema", strlen("_referencedSchema"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(referenced_schema, r1);
	} else {
		PHALCON_INIT_VAR(referenced_schema);
		ZVAL_NULL(referenced_schema);
	}
	
	eval_int = phalcon_array_isset_string(data, "_referencedTable", strlen("_referencedTable")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, data, "_referencedTable", strlen("_referencedTable"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(referenced_table, r2);
	} else {
		PHALCON_INIT_VAR(referenced_table);
		ZVAL_NULL(referenced_table);
	}
	
	eval_int = phalcon_array_isset_string(data, "_columns", strlen("_columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, data, "_columns", strlen("_columns"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(columns, r3);
	} else {
		PHALCON_INIT_VAR(columns);
		ZVAL_NULL(columns);
	}
	
	eval_int = phalcon_array_isset_string(data, "_referencedColumns", strlen("_referencedColumns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, data, "_referencedColumns", strlen("_referencedColumns"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(referenced_columns, r4);
	} else {
		PHALCON_INIT_VAR(referenced_columns);
		ZVAL_NULL(referenced_columns);
	}
	
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_reference_ce);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_array_update_string(&a0, "referencedSchema", strlen("referencedSchema"), &referenced_schema, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_update_string(&a0, "referencedTable", strlen("referencedTable"), &referenced_table, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_update_string(&a0, "columns", strlen("columns"), &columns, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	phalcon_array_update_string(&a0, "referencedColumns", strlen("referencedColumns"), &referenced_columns, PHALCON_SEPARATE_PLZ, PHALCON_COPY, PHALCON_NO_CTOR TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i1, "__construct", constraint_name, a0, PHALCON_CHECK);
	
	PHALCON_RETURN_CTOR(i1);
}

