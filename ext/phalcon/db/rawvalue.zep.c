
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
 * This class allows to insert/update raw data without quoting or formatting.
 *
 * The next example shows how to use the MySQL now() function as a field value.
 *
 *```php
 * $subscriber = new Subscribers();
 *
 * $subscriber->email     = "andres@phalcon.io";
 * $subscriber->createdAt = new \Phalcon\Db\RawValue("now()");
 *
 * $subscriber->save();
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_RawValue)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, RawValue, phalcon, db_rawvalue, phalcon_db_rawvalue_method_entry, 0);

	/**
	 * Raw value without quoting or formatting
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_rawvalue_ce, SL("value"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Raw value without quoting or formatting
 */
PHP_METHOD(Phalcon_Db_RawValue, getValue)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "value");
}

/**
 * Raw value without quoting or formatting
 */
PHP_METHOD(Phalcon_Db_RawValue, __toString)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "value");
}

/**
 * Phalcon\Db\RawValue constructor
 */
PHP_METHOD(Phalcon_Db_RawValue, __construct)
{
	zval _2$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *value, value_sub, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);


	if (ZEPHIR_IS_STRING_IDENTICAL(value, "")) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_NVAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "''");
		zephir_update_property_zval(this_ptr, ZEND_STRL("value"), &_0$$3);
	} else if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZEPHIR_INIT_NVAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "NULL");
		zephir_update_property_zval(this_ptr, ZEND_STRL("value"), &_1$$4);
	} else {
		zephir_cast_to_string(&_2$$5, value);
		zephir_update_property_zval(this_ptr, ZEND_STRL("value"), &_2$$5);
	}
	ZEPHIR_MM_RESTORE();
}

