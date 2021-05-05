
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
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is a base class for validators
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_AbstractValidator)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation, AbstractValidator, phalcon, validation_abstractvalidator, phalcon_validation_abstractvalidator_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * Message template
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_validation_abstractvalidator_ce, SL("template"), ZEND_ACC_PROTECTED);
	/**
	 * Message templates
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_validation_abstractvalidator_ce, SL("templates"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_validation_abstractvalidator_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_validation_abstractvalidator_ce->create_object = zephir_init_properties_Phalcon_Validation_AbstractValidator;

	zend_class_implements(phalcon_validation_abstractvalidator_ce, 1, phalcon_validation_validatorinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Validation\Validator constructor
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *options_param = NULL, template, _0, _3;
	zval options, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(options)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "template");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "message");
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_LONG(&_3, 0);
	zephir_array_fast_append(&_2, &_3);
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_helper_arr_ce, "whitelist", &_1, 3, &options, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&template, "current", NULL, 4, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&template) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "settemplates", NULL, 0, &template);
		zephir_check_call_status();
	} else if (Z_TYPE_P(&template) == IS_STRING) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "settemplate", NULL, 0, &template);
		zephir_check_call_status();
	}
	if (zephir_is_true(&template)) {
		zephir_array_update_string(&options, SL("message"), &template, PH_COPY | PH_SEPARATE);
		zephir_array_unset_string(&options, SL("template"), PH_SEPARATE);
		zephir_array_unset_long(&options, 0, PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Get the template message
 *
 * @return string
 * @throw InvalidArgumentException When the field does not exists
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, getTemplate)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *field_param = NULL, _1, _4, _5, _2$$3, _3$$3;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(field)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &field_param);
	if (!field_param) {
		ZEPHIR_INIT_VAR(&field);
	} else {
	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
	}
	}


	_0 = !ZEPHIR_IS_NULL(&field);
	if (_0) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("templates"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, &field);
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("templates"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &field, PH_NOISY | PH_READONLY, "phalcon/Validation/AbstractValidator.zep", 77);
		RETURN_CTOR(&_3$$3);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("template"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_4)) {
		RETURN_MM_MEMBER(getThis(), "template");
	}
	ZEPHIR_INIT_VAR(&_5);
	zephir_get_class(&_5, this_ptr, 0);
	ZEPHIR_CONCAT_SV(return_value, "The field :field is not valid for ", &_5);
	RETURN_MM();
}

/**
 * Get templates collection object
 *
 * @return array
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, getTemplates)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "templates");
}

/**
 * Clear current templates and set new from an array,
 *
 * @return ValidatorInterface
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, setTemplates)
{
	zval _5$$3, _6$$3, _7$$4, _8$$4;
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *templates_param = NULL, field, template, _0, *_1, _2;
	zval templates;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&templates);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&template);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(templates)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &templates_param);
	ZEPHIR_OBS_COPY_OR_DUP(&templates, templates_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("templates"), &_0);
	zephir_is_iterable(&templates, 0, "phalcon/Validation/AbstractValidator.zep", 116);
	if (Z_TYPE_P(&templates) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&templates), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&field, _4);
			} else {
				ZVAL_LONG(&field, _3);
			}
			ZEPHIR_INIT_NVAR(&template);
			ZVAL_COPY(&template, _1);
			zephir_cast_to_string(&_5$$3, &field);
			ZEPHIR_CPY_WRT(&field, &_5$$3);
			zephir_cast_to_string(&_6$$3, &template);
			ZEPHIR_CPY_WRT(&template, &_6$$3);
			zephir_update_property_array(this_ptr, SL("templates"), &field, &template);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &templates, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &templates, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &templates, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&template, &templates, "current", NULL, 0);
			zephir_check_call_status();
				zephir_cast_to_string(&_7$$4, &field);
				ZEPHIR_CPY_WRT(&field, &_7$$4);
				zephir_cast_to_string(&_8$$4, &template);
				ZEPHIR_CPY_WRT(&template, &_8$$4);
				zephir_update_property_array(this_ptr, SL("templates"), &field, &template);
			ZEPHIR_CALL_METHOD(NULL, &templates, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&template);
	ZEPHIR_INIT_NVAR(&field);
	RETURN_THIS();
}

/**
 * Set a new template message
 *
 * @return ValidatorInterface
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, setTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *template_param = NULL;
	zval template;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(template)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &template_param);
	if (UNEXPECTED(Z_TYPE_P(template_param) != IS_STRING && Z_TYPE_P(template_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'template' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(template_param) == IS_STRING)) {
		zephir_get_strval(&template, template_param);
	} else {
		ZEPHIR_INIT_VAR(&template);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("template"), &template);
	RETURN_THIS();
}

/**
 * Returns an option in the validator's options
 * Returns null if the option hasn't set
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, getOption)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *defaultValue = NULL, defaultValue_sub, __$null, value, fieldValue, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&fieldValue);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(key)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &key_param, &defaultValue);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&value, &_0, &key, 1))) {
		RETVAL_ZVAL(defaultValue, 1, 0);
		RETURN_MM();
	}
	_1 = ZEPHIR_IS_STRING(&key, "attribute");
	if (_1) {
		_1 = Z_TYPE_P(&value) == IS_ARRAY;
	}
	if (_1) {
		if (zephir_array_isset_fetch(&fieldValue, &value, &key, 1)) {
			RETURN_CTOR(&fieldValue);
		}
	}
	RETURN_CTOR(&value);
}

/**
 * Checks if an option is defined
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, hasOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &key));
}

/**
 * Sets an option in the validator
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, setOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	zephir_update_property_array(this_ptr, SL("options"), &key, value);
	ZEPHIR_MM_RESTORE();
}

/**
 * Executes the validation
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, validate)
{
}

/**
 * Prepares a validation code.
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, prepareCode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field_param = NULL, code, _0, _1$$3;
	zval field;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field_param);
	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "code");
	ZEPHIR_CALL_METHOD(&code, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&code) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &code, &field, PH_NOISY | PH_READONLY, "phalcon/Validation/AbstractValidator.zep", 187);
		ZEPHIR_CPY_WRT(&code, &_1$$3);
	}
	RETURN_CCTOR(&code);
}

/**
 * Prepares a label for the field.
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, prepareLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval field;
	zval *validation, validation_sub, *field_param = NULL, label, _0, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&label);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&field);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_validation_ce)
		Z_PARAM_STR(field)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &validation, &field_param);
	if (UNEXPECTED(Z_TYPE_P(field_param) != IS_STRING && Z_TYPE_P(field_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'field' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(field_param) == IS_STRING)) {
		zephir_get_strval(&field, field_param);
	} else {
		ZEPHIR_INIT_VAR(&field);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "label");
	ZEPHIR_CALL_METHOD(&label, this_ptr, "getoption", NULL, 0, &_0);
	zephir_check_call_status();
	if (Z_TYPE_P(&label) == IS_ARRAY) {
		zephir_array_fetch(&_1$$3, &label, &field, PH_NOISY | PH_READONLY, "phalcon/Validation/AbstractValidator.zep", 203);
		ZEPHIR_CPY_WRT(&label, &_1$$3);
	}
	if (ZEPHIR_IS_EMPTY(&label)) {
		ZEPHIR_CALL_METHOD(&label, validation, "getlabel", NULL, 0, &field);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&label);
}

/**
 * Create a default message by factory
 *
 * @return Message
 *
 * @throw Exception
 */
PHP_METHOD(Phalcon_Validation_AbstractValidator, messageFactory)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval replacements, _1;
	zval *validation, validation_sub, *field, field_sub, *replacements_param = NULL, singleField, _0, _2, _3, _4, _5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&validation_sub);
	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&singleField);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&replacements);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(validation, phalcon_validation_ce)
		Z_PARAM_ZVAL(field)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(replacements)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &validation, &field, &replacements_param);
	if (!replacements_param) {
		ZEPHIR_INIT_VAR(&replacements);
		array_init(&replacements);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&replacements, replacements_param);
	}


	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&singleField);
		zephir_fast_join_str(&singleField, SL(", "), field);
	} else if (Z_TYPE_P(field) == IS_STRING) {
		ZEPHIR_CPY_WRT(&singleField, field);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_validation_exception_ce, "The field can not be printed", "phalcon/Validation/AbstractValidator.zep", 229);
		return;
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 1, 0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "preparelabel", NULL, 0, validation, &singleField);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL(":field"), &_2, PH_COPY | PH_SEPARATE);
	zephir_fast_array_merge(&_0, &_1, &replacements);
	ZEPHIR_CPY_WRT(&replacements, &_0);
	object_init_ex(return_value, phalcon_messages_message_ce);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "gettemplate", NULL, 0, &singleField);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_3, "strtr", NULL, 5, &_2, &replacements);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_get_class(&_4, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "preparecode", NULL, 0, &singleField);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 6, &_3, field, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Validation_AbstractValidator(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("templates"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("templates"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

