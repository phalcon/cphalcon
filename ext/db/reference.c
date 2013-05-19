
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
#include "kernel/operators.h"

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
 * Phalcon\Db\Reference initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Reference){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Reference, db_reference, phalcon_db_reference_method_entry, 0);

	zend_declare_property_null(phalcon_db_reference_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedSchema"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referenceName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedTable"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedColumns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_reference_ce TSRMLS_CC, 1, phalcon_db_referenceinterface_ce);

	return SUCCESS;
}

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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &reference_name, &definition);
	
	phalcon_update_property_this(this_ptr, SL("_referenceName"), reference_name TSRMLS_CC);
	if (phalcon_array_isset_string(definition, SS("referencedTable"))) {
		PHALCON_OBS_VAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, definition, SL("referencedTable"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_referencedTable"), referenced_table TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced table is required");
		return;
	}
	
	if (phalcon_array_isset_string(definition, SS("columns"))) {
		PHALCON_OBS_VAR(columns);
		phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Foreign key columns are required");
		return;
	}
	
	if (phalcon_array_isset_string(definition, SS("referencedColumns"))) {
		PHALCON_OBS_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, definition, SL("referencedColumns"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_referencedColumns"), referenced_columns TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced columns of the foreign key are required");
		return;
	}
	
	if (phalcon_array_isset_string(definition, SS("schema"))) {
		PHALCON_OBS_VAR(schema);
		phalcon_array_fetch_string(&schema, definition, SL("schema"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_schemaName"), schema TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(definition, SS("referencedSchema"))) {
		PHALCON_OBS_VAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, definition, SL("referencedSchema"), PH_NOISY_CC);
		phalcon_update_property_this(this_ptr, SL("_referencedSchema"), referenced_schema TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(number_columns);
	phalcon_fast_count(number_columns, columns TSRMLS_CC);
	
	PHALCON_INIT_VAR(number_referenced_columns);
	phalcon_fast_count(number_referenced_columns, referenced_columns TSRMLS_CC);
	if (!PHALCON_IS_EQUAL(number_columns, number_referenced_columns)) {
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


	RETURN_MEMBER(this_ptr, "_referenceName");
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getSchemaName){


	RETURN_MEMBER(this_ptr, "_schemaName");
}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema){


	RETURN_MEMBER(this_ptr, "_referencedSchema");
}

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns){


	RETURN_MEMBER(this_ptr, "_columns");
}

/**
 * Gets the referenced table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable){


	RETURN_MEMBER(this_ptr, "_referencedTable");
}

/**
 * Gets referenced columns
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns){


	RETURN_MEMBER(this_ptr, "_referencedColumns");
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

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	if (!phalcon_array_isset_string(data, SS("_referenceName"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "_referenceName parameter is required");
		return;
	} else {
		PHALCON_OBS_VAR(constraint_name);
		phalcon_array_fetch_string(&constraint_name, data, SL("_referenceName"), PH_NOISY_CC);
	}
	if (phalcon_array_isset_string(data, SS("_referencedSchema"))) {
		PHALCON_OBS_VAR(referenced_schema);
		phalcon_array_fetch_string(&referenced_schema, data, SL("_referencedSchema"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(referenced_schema);
	}
	
	if (phalcon_array_isset_string(data, SS("_referencedTable"))) {
		PHALCON_OBS_VAR(referenced_table);
		phalcon_array_fetch_string(&referenced_table, data, SL("_referencedTable"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(referenced_table);
	}
	
	if (phalcon_array_isset_string(data, SS("_columns"))) {
		PHALCON_OBS_VAR(columns);
		phalcon_array_fetch_string(&columns, data, SL("_columns"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(columns);
	}
	
	if (phalcon_array_isset_string(data, SS("_referencedColumns"))) {
		PHALCON_OBS_VAR(referenced_columns);
		phalcon_array_fetch_string(&referenced_columns, data, SL("_referencedColumns"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(referenced_columns);
	}
	
	PHALCON_INIT_VAR(definition);
	array_init_size(definition, 4);
	phalcon_array_update_string(&definition, SL("referencedSchema"), &referenced_schema, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&definition, SL("referencedTable"), &referenced_table, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&definition, SL("columns"), &columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	phalcon_array_update_string(&definition, SL("referencedColumns"), &referenced_columns, PH_COPY | PH_SEPARATE TSRMLS_CC);
	
	PHALCON_INIT_VAR(reference);
	object_init_ex(reference, phalcon_db_reference_ce);
	phalcon_call_method_p2_noret(reference, "__construct", constraint_name, definition);
	
	RETURN_CTOR(reference);
}

