
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Db_Reference) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Reference, phalcon, db_reference, phalcon_db_reference_method_entry, 0);

	zend_declare_property_null(phalcon_db_reference_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedSchema"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Constraint name
 *
 * @var string
 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referenceName"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Referenced Table
 *
 * @var string
 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedTable"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Local reference columns
 *
 * @var array
 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Referenced Columns
 *
 * @var array
 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedColumns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Db\Reference constructor
 *
 * @param string referenceName
 * @param array definition
 */
PHP_METHOD(Phalcon_Db_Reference, __construct) {

	zval *referenceName, *definition, *columns, *schema, *referencedTable, *referencedSchema, *referencedColumns;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &referenceName, &definition);



	zephir_update_property_this(this_ptr, SL("_referenceName"), referenceName TSRMLS_CC);
	ZEPHIR_OBS_VAR(referencedTable);
	if (zephir_array_isset_string_fetch(&referencedTable, definition, SS("referencedTable") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_referencedTable"), referencedTable TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced table is required");
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (zephir_array_isset_string_fetch(&columns, definition, SS("columns") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Foreign key columns are required");
		return;
	}
	ZEPHIR_OBS_VAR(referencedColumns);
	if (zephir_array_isset_string_fetch(&referencedColumns, definition, SS("referencedColumns") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_referencedColumns"), referencedColumns TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Referenced columns of the foreign key are required");
		return;
	}
	ZEPHIR_OBS_VAR(schema);
	if (zephir_array_isset_string_fetch(&schema, definition, SS("schema") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_schemaName"), schema TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(referencedSchema);
	if (zephir_array_isset_string_fetch(&referencedSchema, definition, SS("referencedSchema") TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_referencedSchema"), referencedSchema TSRMLS_CC);
	}
	if ((zephir_fast_count_int(columns TSRMLS_CC) != zephir_fast_count_int(referencedColumns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Number of columns is not equals than the number of columns referenced");
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the index name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getName) {


	RETURN_MEMBER(this_ptr, "_referenceName");

}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getSchemaName) {


	RETURN_MEMBER(this_ptr, "_schemaName");

}

/**
 * Gets the schema where referenced table is
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema) {


	RETURN_MEMBER(this_ptr, "_referencedSchema");

}

/**
 * Gets local columns which reference is based
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns) {


	RETURN_MEMBER(this_ptr, "_columns");

}

/**
 * Gets the referenced table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable) {


	RETURN_MEMBER(this_ptr, "_referencedTable");

}

/**
 * Gets referenced columns
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns) {


	RETURN_MEMBER(this_ptr, "_referencedColumns");

}

/**
 * Restore a Phalcon\Db\Reference object from export
 *
 * @param array data
 * @return Phalcon\Db\Reference
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state) {

	zval *data, *constraintName;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_OBS_VAR(constraintName);
	if (!(zephir_array_isset_string_fetch(&constraintName, data, SS("_referenceName") TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "_referenceName parameter is required");
		return;
	}
	ZEPHIR_MM_RESTORE();

}

