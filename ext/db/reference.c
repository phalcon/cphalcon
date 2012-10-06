
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
 *<code>
 *	$reference = new Phalcon\Db\Reference("field_fk", array(
 *		'referencedSchema' => "invoicing",
 *		'referencedTable' => "products",
 *		'columns' => array("product_type", "product_code"),
 *		'referencedColumns' => array("type", "code")
 *	));
 *</code>
 */

/**
 * Phalcon\Db\Reference constructor
 *
 * @param string $referenceName
 * @param array $definition
 */
PHP_METHOD(Phalcon_Db_Reference, __construct){

	zval *reference_name, *definition, *referenced_table;
	zval *columns, *referenced_columns, *schema;
	zval *referenced_schema, *number_columns;
	zval *number_referenced_columns;
	zval *r0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &reference_name, &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_referenceName"), reference_name TSRMLS_CC);
	eval_int = phalcon_array_isset_string(definition, SS("referencedTable"));
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, definition, SL("referencedTable"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_referencedTable"), referenced_table TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced table is required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("columns"));
	if (eval_int) {
		PHALCON_INIT_VAR(columns);
		phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_columns"), columns TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Foreign key columns are required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("referencedColumns"));
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, definition, SL("referencedColumns"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_referencedColumns"), referenced_columns TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced columns of the foreign key are required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("schema"));
	if (eval_int) {
		PHALCON_INIT_VAR(schema);
		phalcon_array_fetch_string(&schema, definition, SL("schema"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_schemaName"), schema TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SS("referencedSchema"));
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, definition, SL("referencedSchema"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_referencedSchema"), referenced_schema TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(number_columns);
	phalcon_fast_count(number_columns, columns TSRMLS_CC);
	
	PHALCON_INIT_VAR(number_referenced_columns);
	phalcon_fast_count(number_referenced_columns, referenced_columns TSRMLS_CC);
	
	PHALCON_INIT_VAR(r0);
	is_not_equal_function(r0, number_columns, number_referenced_columns TSRMLS_CC);
	if (zend_is_true(r0)) {
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

	zval *reference_name;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(reference_name);
	phalcon_read_property(&reference_name, this_ptr, SL("_referenceName"), PH_NOISY_CC);
	
	RETURN_CCTOR(reference_name);
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getSchemaName){

	zval *schema_name;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(schema_name);
	phalcon_read_property(&schema_name, this_ptr, SL("_schemaName"), PH_NOISY_CC);
	
	RETURN_CCTOR(schema_name);
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema){

	zval *referenced_schema;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(referenced_schema);
	phalcon_read_property(&referenced_schema, this_ptr, SL("_referencedSchema"), PH_NOISY_CC);
	
	RETURN_CCTOR(referenced_schema);
}

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns){

	zval *columns;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(columns);
	phalcon_read_property(&columns, this_ptr, SL("_columns"), PH_NOISY_CC);
	
	RETURN_CCTOR(columns);
}

/**
 * Gets the referenced table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable){

	zval *referenced_table;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(referenced_table);
	phalcon_read_property(&referenced_table, this_ptr, SL("_referencedTable"), PH_NOISY_CC);
	
	RETURN_CCTOR(referenced_table);
}

/**
 * Gets referenced columns
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns){

	zval *referenced_columns;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(referenced_columns);
	phalcon_read_property(&referenced_columns, this_ptr, SL("_referencedColumns"), PH_NOISY_CC);
	
	RETURN_CCTOR(referenced_columns);
}

/**
 * Restore a Phalcon\Db\Reference object from export
 *
 * @param array $data
 * @return Phalcon\Db\Reference
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state){

	zval *data, *constraint_name, *referenced_schema = NULL;
	zval *referenced_table = NULL, *columns = NULL, *referenced_columns = NULL;
	zval *definition, *reference;
	int eval_int;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(data, SS("_referenceName"));
	if (!eval_int) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "_referenceName parameter is required");
		return;
	} else {
		PHALCON_INIT_VAR(constraint_name);
		phalcon_array_fetch_string(&constraint_name, data, SL("_referenceName"), PH_NOISY_CC);
	}
	eval_int = phalcon_array_isset_string(data, SS("_referencedSchema"));
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, data, SL("_referencedSchema"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(referenced_schema);
	}
	
	eval_int = phalcon_array_isset_string(data, SS("_referencedTable"));
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, data, SL("_referencedTable"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(referenced_table);
	}
	
	eval_int = phalcon_array_isset_string(data, SS("_columns"));
	if (eval_int) {
		PHALCON_INIT_VAR(columns);
		phalcon_array_fetch_string(&columns, data, SL("_columns"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(columns);
	}
	
	eval_int = phalcon_array_isset_string(data, SS("_referencedColumns"));
	if (eval_int) {
		PHALCON_INIT_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, data, SL("_referencedColumns"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(referenced_columns);
	}
	
	PHALCON_INIT_VAR(definition);
	array_init(definition);
	phalcon_array_update_string(&definition, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&definition, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&definition, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&definition, SL("referencedColumns"), &referenced_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(reference);
	object_init_ex(reference, phalcon_db_reference_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(reference, "__construct", constraint_name, definition, PH_CHECK);
	
	RETURN_CTOR(reference);
}

