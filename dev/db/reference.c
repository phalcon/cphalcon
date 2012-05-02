
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
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

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

	zval *v0 = NULL, *v1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL, *i3 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL }, *p2[] = { NULL }, *p5[] = { NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_referenceName", strlen("_referenceName"), v0 TSRMLS_CC);
	eval_int = phalcon_array_isset_string(v1, "referencedTable", strlen("referencedTable")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "referencedTable", strlen("referencedTable"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedTable", strlen("_referencedTable"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Referenced table is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "columns", strlen("columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v1, "columns", strlen("columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), r1 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p1[0]);
		ZVAL_STRING(p1[0], "Foreign key columns are required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 1, p1, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i1 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "referencedColumns", strlen("referencedColumns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v1, "referencedColumns", strlen("referencedColumns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedColumns", strlen("_referencedColumns"), r2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i2);
		object_init_ex(i2, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p2[0]);
		ZVAL_STRING(p2[0], "Referenced columns of the foreign key are required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i2, "__construct", 1, p2, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i2 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "schema", strlen("schema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v1, "schema", strlen("schema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_schema", strlen("_schema"), r3 TSRMLS_CC);
	}
	eval_int = phalcon_array_isset_string(v1, "referencedSchema", strlen("referencedSchema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v1, "referencedSchema", strlen("referencedSchema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_referencedSchema", strlen("_referencedSchema"), r4 TSRMLS_CC);
	}
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r5, "count", t0, 0x007);
	PHALCON_ALLOC_ZVAL_MM(r6);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_referencedColumns", sizeof("_referencedColumns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r6, "count", t1, 0x007);
	PHALCON_INIT_VAR(r7);
	is_not_equal_function(r7, r5, r6 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_ALLOC_ZVAL_MM(i3);
		object_init_ex(i3, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p5[0]);
		ZVAL_STRING(p5[0], "Number of columns is not equals than the number of columns referenced", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i3, "__construct", 1, p5, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i3 TSRMLS_CC);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	phalcon_read_property(&t0, this_ptr, "_referenceName", sizeof("_referenceName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_schemaName", sizeof("_schemaName")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_referencedSchema", sizeof("_referencedSchema")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_referencedTable", sizeof("_referencedTable")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, "_referencedColumns", sizeof("_referencedColumns")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Restore a Phalcon_Db_Reference object from export
 *
 * @param array $data
 * @return Phalcon_Db_Reference
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL, *v4 = NULL, *v5 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL }, *p1[] = { NULL, NULL };
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	eval_int = phalcon_array_isset_string(v0, "_referenceName", strlen("_referenceName")+1);
	PHALCON_INIT_VAR(r0);
	ZVAL_BOOL(r0, eval_int);
	if (!zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "_referenceName parameter is required", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		return phalcon_throw_exception(i0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, v0, "_referenceName", strlen("_referenceName"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v1, r1);
	}
	eval_int = phalcon_array_isset_string(v0, "_referencedSchema", strlen("_referencedSchema")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, v0, "_referencedSchema", strlen("_referencedSchema"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r2);
	} else {
		PHALCON_INIT_VAR(v2);
		ZVAL_NULL(v2);
	}
	eval_int = phalcon_array_isset_string(v0, "_referencedTable", strlen("_referencedTable")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r3);
		phalcon_array_fetch_string(&r3, v0, "_referencedTable", strlen("_referencedTable"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v3, r3);
	} else {
		PHALCON_INIT_VAR(v3);
		ZVAL_NULL(v3);
	}
	eval_int = phalcon_array_isset_string(v0, "_columns", strlen("_columns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r4);
		phalcon_array_fetch_string(&r4, v0, "_columns", strlen("_columns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v4, r4);
	} else {
		PHALCON_INIT_VAR(v4);
		ZVAL_NULL(v4);
	}
	eval_int = phalcon_array_isset_string(v0, "_referencedColumns", strlen("_referencedColumns")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, v0, "_referencedColumns", strlen("_referencedColumns"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v5, r5);
	} else {
		PHALCON_INIT_VAR(v5);
		ZVAL_NULL(v5);
	}
	PHALCON_ALLOC_ZVAL_MM(i1);
	object_init_ex(i1, phalcon_db_reference_class_entry);
	Z_ADDREF_P(v1);
	p1[0] = v1;
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	Z_ADDREF_P(v2);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "referencedSchema", v2);
	Z_ADDREF_P(v3);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "referencedTable", v3);
	Z_ADDREF_P(v4);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "columns", v4);
	Z_ADDREF_P(v5);
	PHALCON_SEPARATE_ARRAY(a0);
	add_assoc_zval(a0, "referencedColumns", v5);
	Z_ADDREF_P(a0);
	p1[1] = a0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 2, p1, PHALCON_CALL_CHECK);
	Z_DELREF_P(p1[0]);
	Z_DELREF_P(p1[1]);
	PHALCON_RETURN_CTOR(i1);
}

