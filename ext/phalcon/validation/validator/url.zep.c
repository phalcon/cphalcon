
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Validation\Validator\Url
 *
 * Checks if a value has a url format
 *
 * <code>
 * use Phalcon\Validation;
 * use Phalcon\Validation\Validator\Url as UrlValidator;
 *
 * $validator = new Validation();
 *
 * $validator->add(
 *     "url",
 *     new UrlValidator(
 *         [
 *             "message" => ":field must be a url",
 *         ]
 *     )
 * );
 *
 * $validator->add(
 *     [
 *         "url",
 *         "homepage",
 *     ],
 *     new UrlValidator(
 *         [
 *             "message" => [
 *                 "url"      => "url must be a url",
 *                 "homepage" => "homepage must be a url",
 *             ]
 *         ]
 *     )
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Validator_Url) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Validation\\Validator, Url, phalcon, validation_validator_url, phalcon_validation_validator_ce, phalcon_validation_validator_url_method_entry, 0);

	return SUCCESS;

}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_Validator_Url, validate) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *validation, validation_sub, *field, field_sub, value, message, label, replacePairs, code, _0, _1, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&replacePairs);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field);



	ZEPHIR_CALL_METHOD(&value, validation, "getvalue", NULL, 0, field);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 273);
	ZEPHIR_CALL_FUNCTION(&_1, "filter_var", NULL, 188, &value, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_CALL_METHOD(&label, this_ptr, "preparelabel", NULL, 0, validation, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Url");
		ZEPHIR_CALL_METHOD(&message, this_ptr, "preparemessage", NULL, 0, validation, field, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&code, this_ptr, "preparecode", NULL, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&replacePairs);
		zephir_create_array(&replacePairs, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&replacePairs, SL(":field"), &label, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_messages_message_ce);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "strtr", NULL, 48, &message, &replacePairs);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "Url");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 300, &_3$$3, field, &_4$$3, &code);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, validation, "appendmessage", NULL, 0, &_2$$3);
		zephir_check_call_status();
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

