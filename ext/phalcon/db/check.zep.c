
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Allows to define `CHECK` constraints on tables. CHECK constraints enforce
 * a boolean SQL predicate on each row of the table; rows that fail the
 * predicate are rejected at INSERT/UPDATE time.
 *
 *```php
 * use Phalcon\Db\Check;
 *
 * $positivePrice = new Check(
 *     "chk_price_positive",
 *     [
 *         "expression" => "price > 0",
 *     ]
 * );
 *
 * // Used inside a createTable() definition
 * $connection->createTable(
 *     "products",
 *     null,
 *     [
 *         "columns" => [ ... ],
 *         "checks"  => [$positivePrice],
 *     ]
 * );
 *
 * // Or added to an existing table (MySQL 8.0.16+ and PostgreSQL).
 * // SQLite cannot add CHECK constraints to existing tables.
 * $connection->addCheck("products", null, $positivePrice);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Check)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Check, phalcon, db_check, phalcon_db_check_method_entry, 0);

	/**
	 * The boolean SQL predicate this constraint enforces.
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_check_ce, SL("expression"), ZEND_ACC_PROTECTED);
	/**
	 * The CHECK constraint name. An empty string indicates an unnamed
	 * constraint — the dialect will emit the clause without a `CONSTRAINT`
	 * prefix in that case.
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_check_ce, SL("name"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_db_check_ce, 1, phalcon_db_checkinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Db\Check constructor
 */
PHP_METHOD(Phalcon_Db_Check, __construct)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval definition;
	zval name_zv, *definition_param = NULL, expression;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&expression);
	ZVAL_UNDEF(&definition);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	zephir_memory_observe(&expression);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&expression, &definition, SL("expression"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "CHECK expression is required", "phalcon/Db/Check.zep", 69);
		return;
	}
	_0 = Z_TYPE_P(&expression) != IS_STRING;
	if (!(_0)) {
		_0 = ZEPHIR_IS_STRING_IDENTICAL(&expression, "");
	}
	if (UNEXPECTED(_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "CHECK expression must be a non-empty string", "phalcon/Db/Check.zep", 75);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	zephir_update_property_zval(this_ptr, ZEND_STRL("expression"), &expression);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the CHECK expression
 */
PHP_METHOD(Phalcon_Db_Check, getExpression)
{

	RETURN_MEMBER_TYPED(getThis(), "expression", IS_STRING);
}

/**
 * Returns the constraint name (may be an empty string for unnamed)
 */
PHP_METHOD(Phalcon_Db_Check, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

