
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
 * Phalcon\Db\RawValue
 *
 * This class allows to insert/update raw data without quoting or formating.
 *
 * The next example shows how to use the MySQL now() function as a field value.
 *
 *<code>
 *	$subscriber = new Subscribers();
 *	$subscriber->email = 'andres@phalconphp.com';
 *	$subscriber->createdAt = new \Phalcon\Db\RawValue('now()');
 *	$subscriber->save();
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_RawValue) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, RawValue, phalcon, db_rawvalue, phalcon_db_rawvalue_method_entry, 0);

	/**
	 * Raw value without quoting or formating
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_rawvalue_ce, SL("_value"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Raw value without quoting or formating
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_RawValue, getValue) {


	RETURN_MEMBER(this_ptr, "_value");

}

/**
 * Raw value without quoting or formating
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_RawValue, __toString) {


	RETURN_MEMBER(this_ptr, "_value");

}

/**
 * Phalcon\Db\RawValue constructor
 */
PHP_METHOD(Phalcon_Db_RawValue, __construct) {

	zval *_2 = NULL;
	zend_bool _0;
	zval *value, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	_0 = Z_TYPE_P(value) == IS_STRING;
	if (_0) {
		_0 = ZEPHIR_IS_STRING(value, "");
	}
	if (_0) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_STRING(_1, "''", 1);
		zephir_update_property_this(this_ptr, SL("_value"), _1 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_ZVAL_NREF(_1);
		ZVAL_STRING(_1, "NULL", 1);
		zephir_update_property_this(this_ptr, SL("_value"), _1 TSRMLS_CC);
		RETURN_MM_NULL();
	}
	zephir_get_strval(_2, value);
	zephir_update_property_this(this_ptr, SL("_value"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

