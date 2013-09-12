
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"


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
 * Phalcon\Db\Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *<code>
 *	use Phalcon\Db\Column as Column;
 *
 * //column definition
 * $column = new Column("id", array(
 *   "type" => Column::TYPE_INTEGER,
 *   "size" => 10,
 *   "unsigned" => true,
 *   "notNull" => true,
 *   "autoIncrement" => true,
 *   "first" => true
 * ));
 *
 * //add column to existing table
 * $connection->addColumn("robots", null, $column);
 *</code>
 *
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Column) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Column, phalcon, db_column, NULL, 0);

/**
 * Column's name
 *
 * @var string
 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_columnName"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Schema which table related is
 *
 * @var string
 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Column data type
 *
 * @var int
 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * The column have some numeric type?
 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_isNumeric"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Integer column size
 *
 * @var int
 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_size"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Integer column number scale
 *
 * @var int
 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_scale"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Integer column unsigned?
 *
 * @var boolean
 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_unsigned"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Column not nullable?
 *
 * @var boolean
 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_notNull"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Column is part of the primary key?
 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_primary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Column is autoIncrement?
 *
 * @var boolean
 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_autoIncrement"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Position is first
 *
 * @var boolean
 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_first"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Column Position
 *
 * @var string
 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_after"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Bind Type
 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_bindType"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Integer abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0 TSRMLS_CC);
/**
 * Date abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1 TSRMLS_CC);
/**
 * Varchar abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2 TSRMLS_CC);
/**
 * Decimal abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3 TSRMLS_CC);
/**
 * Datetime abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4 TSRMLS_CC);
/**
 * Char abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5 TSRMLS_CC);
/**
 * Text abstract data type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6 TSRMLS_CC);
/**
 * Float abstract data type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_FLOAT"), 7 TSRMLS_CC);
/**
 * Boolean abstract data type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BOOLEAN"), 8 TSRMLS_CC);
/**
 * Bind Type Null
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_NULL"), 0 TSRMLS_CC);
/**
 * Bind Type Integer
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_INT"), 1 TSRMLS_CC);
/**
 * Bind Type String
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_STR"), 2 TSRMLS_CC);
/**
 * Bind Type Bool
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BOOL"), 5 TSRMLS_CC);
/**
 * Bind Type Decimal
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_DECIMAL"), 32 TSRMLS_CC);
/**
 * Skip binding by type
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_SKIP"), 1024 TSRMLS_CC);

	return SUCCESS;

}

