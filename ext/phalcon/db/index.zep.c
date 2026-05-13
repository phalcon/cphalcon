
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Db_Index)
{
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
 * Phalcon\Db\Index constructor
 */
PHP_METHOD(Phalcon_Db_Index, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval columns;
	zval name_zv, *columns_param = NULL, type_zv;
	zend_string *name = NULL, *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&columns);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(columns, columns_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	columns_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_OBS_COPY_OR_DUP(&columns, columns_param);
	if (!type) {
		type = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&type_zv);
		ZVAL_STR(&type_zv, type);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columns);
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	ZEPHIR_MM_RESTORE();
}

/**
 * Index columns
 */
PHP_METHOD(Phalcon_Db_Index, getColumns)
{

	RETURN_MEMBER(getThis(), "columns");
}

/**
 * Index name
 */
PHP_METHOD(Phalcon_Db_Index, getName)
{

	RETURN_MEMBER(getThis(), "name");
}

/**
 * Index type
 */
PHP_METHOD(Phalcon_Db_Index, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

