
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index
 *
 *```php
 * // Define new unique index
 * $index_unique = new \Phalcon\Db\Index(
 *     'column_UNIQUE',
 *     [
 *         'column',
 *         'column',
 *     ],
 *     'UNIQUE'
 * );
 *
 * // Define new primary index
 * $index_primary = new \Phalcon\Db\Index(
 *     'PRIMARY',
 *     [
 *         'column',
 *     ]
 * );
 *
 * // Add index to existing table
 * $connection->addIndex("robots", null, $index_unique);
 * $connection->addIndex("robots", null, $index_primary);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Index) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Index, phalcon, db_index, phalcon_db_index_method_entry, 0);

	/**
	 * Index columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("columns"), ZEND_ACC_PROTECTED);

	/**
	 * Index name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("name"), ZEND_ACC_PROTECTED);

	/**
	 * Index type
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("type"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalcon_db_index_ce, 1, phalcon_db_indexinterface_ce);
	return SUCCESS;

}

/**
 * Index columns
 */
PHP_METHOD(Phalcon_Db_Index, getColumns) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "columns");

}

/**
 * Index name
 */
PHP_METHOD(Phalcon_Db_Index, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Index type
 */
PHP_METHOD(Phalcon_Db_Index, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "type");

}

/**
 * Phalcon\Db\Index constructor
 */
PHP_METHOD(Phalcon_Db_Index, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval columns;
	zval *name_param = NULL, *columns_param = NULL, *type_param = NULL;
	zval name, type;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&columns);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &columns_param, &type_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columns);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	ZEPHIR_MM_RESTORE();

}

