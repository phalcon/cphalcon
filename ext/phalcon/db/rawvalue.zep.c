
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
 * Phalcon\Db\RawValue
 *
 * This class allows to insert/update raw data without quoting or formating.
 *
 *The next example shows how to use the MySQL now() function as a field value.
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

	zval *value_param = NULL;
	zval *value = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value_param);

	if (unlikely(Z_TYPE_P(value_param) != IS_STRING && Z_TYPE_P(value_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'value' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(value_param) == IS_STRING)) {
		zephir_get_strval(value, value_param);
	} else {
		ZEPHIR_INIT_VAR(value);
		ZVAL_EMPTY_STRING(value);
	}


	zephir_update_property_this(this_ptr, SL("_value"), value TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

