
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
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\RawValue
 *
 * This class allows to insert/update raw data without quoting or formatting.
 *
 * The next example shows how to use the MySQL now() function as a field value.
 *
 *<code>
 * $subscriber = new Subscribers();
 *
 * $subscriber->email     = "andres@phalconphp.com";
 * $subscriber->createdAt = new \Phalcon\Db\RawValue("now()");
 *
 * $subscriber->save();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_RawValue) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, RawValue, phalcon, db_rawvalue, phalcon_db_rawvalue_method_entry, 0);

	/**
	 * Raw value without quoting or formatting
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_rawvalue_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Raw value without quoting or formatting
 */
PHP_METHOD(Phalcon_Db_RawValue, getValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_value");

}

/**
 * Raw value without quoting or formatting
 */
PHP_METHOD(Phalcon_Db_RawValue, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_value");

}

/**
 * Phalcon\Db\RawValue constructor
 */
PHP_METHOD(Phalcon_Db_RawValue, __construct) {

	zval _3;
	zend_bool _0;
	zval *value, value_sub, _1$$3, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = Z_TYPE_P(value) == IS_STRING;
	if (_0) {
		_0 = ZEPHIR_IS_STRING(value, "");
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_INIT_NVAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "''");
		zephir_update_property_zval(this_ptr, SL("_value"), &_1$$3);
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "NULL");
		zephir_update_property_zval(this_ptr, SL("_value"), &_2$$4);
		RETURN_MM_NULL();
	}
	zephir_get_strval(&_3, value);
	zephir_update_property_zval(this_ptr, SL("_value"), &_3);
	ZEPHIR_MM_RESTORE();

}

