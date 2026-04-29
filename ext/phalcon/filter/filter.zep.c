
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Lazy loads, stores and exposes sanitizer objects
 *
 * @method int          absint(mixed $input)
 * @method string       alnum(mixed $input)
 * @method string       alpha(mixed $input)
 * @method bool         bool(mixed $input)
 * @method string       email(string $input)
 * @method float        float(mixed $input)
 * @method int          int(string $input)
 * @method string|false ip(string $input, int $filter = FILTER_FLAG_NONE)
 * @method string       lower(string $input)
 * @method string       lowerfirst(string $input)
 * @method mixed        regex(mixed $input, mixed $pattern, mixed $replace)
 * @method mixed        remove(mixed $input, mixed $replace)
 * @method mixed        replace(mixed $input, mixed $source, mixed $target)
 * @method string       special(string $input)
 * @method string       specialfull(string $input)
 * @method string       string(string $input)
 * @method string       stringlegacy(mixed $input)
 * @method string       striptags(string $input)
 * @method string       trim(string $input)
 * @method string       upper(string $input)
 * @method string       upperFirst(string $input)
 * @method null         upperWords(string $input): strin
 * @method null         url(string $input): strin
 *
 * @property array $mapper
 * @property array $services
 */
ZEPHIR_INIT_CLASS(Phalcon_Filter_Filter)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Filter, Filter, phalcon, filter_filter, phalcon_filter_filter_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_filter_ce, SL("mapper"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_filter_filter_ce, SL("services"), ZEND_ACC_PROTECTED);
	phalcon_filter_filter_ce->create_object = zephir_init_properties_Phalcon_Filter_Filter;
	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_ABSINT"), "absint");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_ALNUM"), "alnum");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_ALPHA"), "alpha");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_BOOL"), "bool");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_EMAIL"), "email");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_FLOAT"), "float");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_INT"), "int");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_IP"), "ip");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_LOWER"), "lower");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_LOWERFIRST"), "lowerfirst");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_REGEX"), "regex");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_REMOVE"), "remove");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_REPLACE"), "replace");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_SPECIAL"), "special");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_SPECIALFULL"), "specialfull");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_STRING"), "string");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_STRING_LEGACY"), "stringlegacy");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_STRIPTAGS"), "striptags");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_TRIM"), "trim");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_UPPER"), "upper");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_UPPERFIRST"), "upperfirst");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_UPPERWORDS"), "upperwords");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_filter_filter_ce, SL("FILTER_URL"), "url");

	zend_class_implements(phalcon_filter_filter_ce, 1, phalcon_filter_filterinterface_ce);
	return SUCCESS;
}

/**
 * Filter constructor.
 *
 * @param array $mapper
 */
PHP_METHOD(Phalcon_Filter_Filter, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mapper_param = NULL;
	zval mapper;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mapper);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(mapper, mapper_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &mapper_param);
	if (!mapper_param) {
		ZEPHIR_INIT_VAR(&mapper);
		array_init(&mapper);
	} else {
		zephir_get_arrval(&mapper, mapper_param);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &mapper);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Magic call to make the helper objects available as methods.
 *
 * @param string $name
 * @param array  $args
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _0;
	zval name_zv, *args_param = NULL, sanitizer, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(args, args_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	args_param = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_get_arrval(&args, args_param);
	ZEPHIR_CALL_METHOD(&sanitizer, this_ptr, "get", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &sanitizer);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "__invoke");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &args);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Get a service. If it is not in the mapper array, create a new object,
 * set it and then return it.
 *
 * @param string $name
 *
 * @return mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, get)
{
	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, definition, _0, _3, _6, _7, _1$$3, _4$$4, _5$$4;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_2$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("mapper"), PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset(&_0, &name_zv)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_filter_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SVS(&_2$$3, "Filter ", &name_zv, " is not registered");
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 32, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Filter/Filter.zep", 192);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	if (1 != zephir_array_isset(&_3, &name_zv)) {
		zephir_read_property(&_4$$4, this_ptr, ZEND_STRL("mapper"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&definition);
		zephir_array_fetch(&definition, &_4$$4, &name_zv, PH_NOISY, "phalcon/Filter/Filter.zep", 196);
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "createinstance", NULL, 277, &definition);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("services"), &name_zv, &_5$$4);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_7, &_6, &name_zv, PH_NOISY | PH_READONLY, "phalcon/Filter/Filter.zep", 200);
	RETURN_CTOR(&_7);
}

/**
 * Checks if a service exists in the map array
 *
 * @param string $name
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Filter_Filter, has)
{
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("mapper"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_array_isset(&_0, &name_zv));
}

/**
 * Sanitizes a value with a specified single or set of sanitizers
 *
 * @param mixed $value
 * @param mixed $sanitizers
 * @param bool  $noRecursive
 *
 * @return array|false|mixed|null
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, sanitize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive, _1;
	zval *value, value_sub, *sanitizers, sanitizers_sub, *noRecursive_param = NULL, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizers_sub);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(sanitizers)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 1, &value, &sanitizers, &noRecursive_param);
	if (!noRecursive_param) {
		noRecursive = 0;
	} else {
		}
	if (Z_TYPE_P(sanitizers) == IS_ARRAY) {
		if (noRecursive) {
			ZVAL_BOOL(&_0$$3, 1);
		} else {
			ZVAL_BOOL(&_0$$3, 0);
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processarraysanitizers", NULL, 278, sanitizers, value, &_0$$3);
		zephir_check_call_status();
		RETURN_MM();
	}
	_1 = Z_TYPE_P(value) == IS_ARRAY;
	if (_1) {
		_1 = !noRecursive;
	}
	if (_1) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "processarrayvalues", NULL, 279, value, sanitizers);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sanitizer", NULL, 280, value, sanitizers);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Set a new service to the mapper array
 *
 * @param string $name
 * @param mixed  $service
 */
PHP_METHOD(Phalcon_Filter_Filter, set)
{
	zval name_zv, *service, service_sub, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&service_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(service)
	ZEND_PARSE_PARAMETERS_END();
	service = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_update_property_array(this_ptr, SL("mapper"), &name_zv, service);
	zephir_unset_property_array(this_ptr, ZEND_STRL("services"), &name_zv);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name_zv, PH_SEPARATE);
}

/**
 * Loads the objects in the internal mapper array
 *
 * @param array $mapper
 */
PHP_METHOD(Phalcon_Filter_Filter, init)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mapper_param = NULL, name, service, *_0, _1;
	zval mapper;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mapper);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(mapper, mapper_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &mapper_param);
	zephir_get_arrval(&mapper, mapper_param);
	zephir_is_iterable(&mapper, 0, "phalcon/Filter/Filter.zep", 302);
	if (Z_TYPE_P(&mapper) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&mapper), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&service);
			ZVAL_COPY(&service, _0);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &name, &service);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &mapper, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &mapper, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &mapper, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &mapper, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "set", &_4, 0, &name, &service);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &mapper, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&service);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * @param mixed $definition
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Filter_Filter, createInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition, definition_sub, instance;

	ZVAL_UNDEF(&definition_sub);
	ZVAL_UNDEF(&instance);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &definition);
	ZEPHIR_CPY_WRT(&instance, definition);
	if (Z_TYPE_P(&instance) == IS_STRING) {
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(return_value, &instance);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&instance);
}

/**
 * @param array $sanitizers
 * @param mixed $value
 * @param bool  $noRecursive
 *
 * @return array|false|mixed|null
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, processArraySanitizers)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive;
	zval *sanitizers_param = NULL, *value = NULL, value_sub, *noRecursive_param = NULL, sanitizer, sanitizerKey, sanitizerName, sanitizerParams, split, *_0, _1, _5$$5, _6$$5, _8$$6, _10$$8, _11$$8, _12$$9;
	zval sanitizers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sanitizers);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizer);
	ZVAL_UNDEF(&sanitizerKey);
	ZVAL_UNDEF(&sanitizerName);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&split);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		ZEPHIR_Z_PARAM_ARRAY(sanitizers, sanitizers_param)
		Z_PARAM_ZVAL(value)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &sanitizers_param, &value, &noRecursive_param);
	zephir_get_arrval(&sanitizers, sanitizers_param);
	ZEPHIR_SEPARATE_PARAM(value);
	if (Z_TYPE_P(value) == IS_NULL) {
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	zephir_is_iterable(&sanitizers, 0, "phalcon/Filter/Filter.zep", 376);
	if (Z_TYPE_P(&sanitizers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&sanitizers), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&sanitizerKey);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&sanitizerKey, _3);
			} else {
				ZVAL_LONG(&sanitizerKey, _2);
			}
			ZEPHIR_INIT_NVAR(&sanitizer);
			ZVAL_COPY(&sanitizer, _0);
			ZEPHIR_CALL_METHOD(&split, this_ptr, "splitsanitizerparameters", &_4, 281, &sanitizerKey, &sanitizer);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&sanitizerName);
			zephir_array_fetch_long(&sanitizerName, &split, 0, PH_NOISY, "phalcon/Filter/Filter.zep", 352);
			ZEPHIR_OBS_NVAR(&sanitizerParams);
			zephir_array_fetch_long(&sanitizerParams, &split, 1, PH_NOISY, "phalcon/Filter/Filter.zep", 353);
			if (Z_TYPE_P(value) == IS_ARRAY) {
				if (noRecursive) {
					ZVAL_BOOL(&_6$$5, 1);
				} else {
					ZVAL_BOOL(&_6$$5, 0);
				}
				ZEPHIR_CALL_METHOD(&_5$$5, this_ptr, "processvalueisarray", &_7, 282, value, &sanitizerName, &sanitizerParams, &_6$$5);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, &_5$$5);
			} else {
				ZEPHIR_CALL_METHOD(&_8$$6, this_ptr, "processvalueisnotarray", &_9, 283, value, &sanitizerName, &sanitizerParams);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(value, &_8$$6);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &sanitizers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &sanitizers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&sanitizerKey, &sanitizers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&sanitizer, &sanitizers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&split, this_ptr, "splitsanitizerparameters", &_4, 281, &sanitizerKey, &sanitizer);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&sanitizerName);
				zephir_array_fetch_long(&sanitizerName, &split, 0, PH_NOISY, "phalcon/Filter/Filter.zep", 352);
				ZEPHIR_OBS_NVAR(&sanitizerParams);
				zephir_array_fetch_long(&sanitizerParams, &split, 1, PH_NOISY, "phalcon/Filter/Filter.zep", 353);
				if (Z_TYPE_P(value) == IS_ARRAY) {
					if (noRecursive) {
						ZVAL_BOOL(&_11$$8, 1);
					} else {
						ZVAL_BOOL(&_11$$8, 0);
					}
					ZEPHIR_CALL_METHOD(&_10$$8, this_ptr, "processvalueisarray", &_7, 282, value, &sanitizerName, &sanitizerParams, &_11$$8);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, &_10$$8);
				} else {
					ZEPHIR_CALL_METHOD(&_12$$9, this_ptr, "processvalueisnotarray", &_9, 283, value, &sanitizerName, &sanitizerParams);
					zephir_check_call_status();
					ZEPHIR_CPY_WRT(value, &_12$$9);
				}
			ZEPHIR_CALL_METHOD(NULL, &sanitizers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&sanitizer);
	ZEPHIR_INIT_NVAR(&sanitizerKey);
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * Processes the array values with the relevant sanitizers
 *
 * @param array  $values
 * @param string $sanitizerName
 * @param array  $sanitizerParams
 *
 * @return array
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, processArrayValues)
{
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *sanitizerName = NULL, *_3;
	zval *values_param = NULL, sanitizerName_zv, *sanitizerParams_param = NULL, itemKey, itemValue, *_0, _1, _4$$3, _6$$4;
	zval values, sanitizerParams, arrayValues;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&arrayValues);
	ZVAL_UNDEF(&sanitizerName_zv);
	ZVAL_UNDEF(&itemKey);
	ZVAL_UNDEF(&itemValue);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		ZEPHIR_Z_PARAM_ARRAY(values, values_param)
		Z_PARAM_STR(sanitizerName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(sanitizerParams, sanitizerParams_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	values_param = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		sanitizerParams_param = ZEND_CALL_ARG(execute_data, 3);
	}
	zephir_get_arrval(&values, values_param);
	ZVAL_STR_COPY(&sanitizerName_zv, sanitizerName);
	if (!sanitizerParams_param) {
		ZEPHIR_INIT_VAR(&sanitizerParams);
		array_init(&sanitizerParams);
	} else {
		zephir_get_arrval(&sanitizerParams, sanitizerParams_param);
	}
	ZEPHIR_INIT_VAR(&arrayValues);
	array_init(&arrayValues);
	zephir_is_iterable(&values, 0, "phalcon/Filter/Filter.zep", 405);
	if (Z_TYPE_P(&values) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&values), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&itemKey);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&itemKey, _3);
			} else {
				ZVAL_LONG(&itemKey, _2);
			}
			ZEPHIR_INIT_NVAR(&itemValue);
			ZVAL_COPY(&itemValue, _0);
			ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "sanitizer", &_5, 280, &itemValue, &sanitizerName_zv, &sanitizerParams);
			zephir_check_call_status();
			zephir_array_update_zval(&arrayValues, &itemKey, &_4$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &values, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&itemKey, &values, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&itemValue, &values, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, this_ptr, "sanitizer", &_5, 280, &itemValue, &sanitizerName_zv, &sanitizerParams);
				zephir_check_call_status();
				zephir_array_update_zval(&arrayValues, &itemKey, &_6$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&itemValue);
	ZEPHIR_INIT_NVAR(&itemKey);
	RETURN_CTOR(&arrayValues);
}

/**
 * Internal sanitize wrapper for recursion
 *
 * @param mixed  $value
 * @param string $sanitizerName
 * @param array  $sanitizerParams
 *
 * @return false|mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, sanitizer)
{
	zval _1$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sanitizerParams, _3;
	zend_string *sanitizerName = NULL;
	zval *value, value_sub, sanitizerName_zv, *sanitizerParams_param = NULL, params, sanitizerObject, _0, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizerName_zv);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&sanitizerObject);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&sanitizerParams);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$4);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(sanitizerName)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(sanitizerParams, sanitizerParams_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 1);
	if (ZEND_NUM_ARGS() > 2) {
		sanitizerParams_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&sanitizerName_zv, sanitizerName);
	if (!sanitizerParams_param) {
		ZEPHIR_INIT_VAR(&sanitizerParams);
		array_init(&sanitizerParams);
	} else {
		zephir_get_arrval(&sanitizerParams, sanitizerParams_param);
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "has", NULL, 0, &sanitizerName_zv);
	zephir_check_call_status();
	if (!ZEPHIR_IS_TRUE_IDENTICAL(&_0)) {
		if (1 != ZEPHIR_IS_EMPTY(&sanitizerName_zv)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			ZEPHIR_CONCAT_SVS(&_1$$4, "Sanitizer '", &sanitizerName_zv, "' is not registered");
			ZVAL_LONG(&_2$$4, 1024);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 9, &_1$$4, &_2$$4);
			zephir_check_call_status();
		}
		RETVAL_ZVAL(value, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&sanitizerObject, this_ptr, "get", NULL, 0, &sanitizerName_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 1, 0);
	zephir_array_fast_append(&_3, value);
	ZEPHIR_INIT_VAR(&params);
	zephir_fast_array_merge(&params, &_3, &sanitizerParams);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &sanitizerObject, &params);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param mixed  $value
 * @param string $sanitizerName
 * @param array  $sanitizerParams
 * @param bool   $noRecursive
 *
 * @return array|mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, processValueIsArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool noRecursive;
	zval sanitizerParams;
	zend_string *sanitizerName = NULL;
	zval *value = NULL, value_sub, sanitizerName_zv, *sanitizerParams_param = NULL, *noRecursive_param = NULL, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizerName_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&sanitizerParams);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(sanitizerName)
		ZEPHIR_Z_PARAM_ARRAY(sanitizerParams, sanitizerParams_param)
		Z_PARAM_BOOL(noRecursive)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 1);
	sanitizerParams_param = ZEND_CALL_ARG(execute_data, 3);
	noRecursive_param = ZEND_CALL_ARG(execute_data, 4);
	ZEPHIR_SEPARATE_PARAM(value);
	ZVAL_STR_COPY(&sanitizerName_zv, sanitizerName);
	zephir_get_arrval(&sanitizerParams, sanitizerParams_param);
	if (noRecursive) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "sanitizer", NULL, 280, value, &sanitizerName_zv, &sanitizerParams);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_0$$3);
	} else {
		ZEPHIR_CALL_METHOD(&_1$$4, this_ptr, "processarrayvalues", NULL, 279, value, &sanitizerName_zv, &sanitizerParams);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_1$$4);
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * @param mixed  $value
 * @param string $sanitizerName
 * @param array  $sanitizerParams
 *
 * @return array|false|mixed
 * @throws Exception
 */
PHP_METHOD(Phalcon_Filter_Filter, processValueIsNotArray)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval sanitizerParams;
	zend_string *sanitizerName = NULL;
	zval *value = NULL, value_sub, sanitizerName_zv, *sanitizerParams_param = NULL, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&sanitizerName_zv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&sanitizerParams);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(value)
		Z_PARAM_STR(sanitizerName)
		ZEPHIR_Z_PARAM_ARRAY(sanitizerParams, sanitizerParams_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	value = ZEND_CALL_ARG(execute_data, 1);
	sanitizerParams_param = ZEND_CALL_ARG(execute_data, 3);
	ZEPHIR_SEPARATE_PARAM(value);
	ZVAL_STR_COPY(&sanitizerName_zv, sanitizerName);
	zephir_get_arrval(&sanitizerParams, sanitizerParams_param);
	if (Z_TYPE_P(value) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "sanitizer", NULL, 280, value, &sanitizerName_zv, &sanitizerParams);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(value, &_0$$3);
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();
}

/**
 * @param mixed $sanitizerKey
 * @param mixed $sanitizer
 *
 * @return array
 */
PHP_METHOD(Phalcon_Filter_Filter, splitSanitizerParameters)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *sanitizerKey, sanitizerKey_sub, *sanitizer, sanitizer_sub, _0;

	ZVAL_UNDEF(&sanitizerKey_sub);
	ZVAL_UNDEF(&sanitizer_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(sanitizerKey)
		Z_PARAM_ZVAL(sanitizer)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &sanitizerKey, &sanitizer);
	if (Z_TYPE_P(sanitizer) == IS_ARRAY) {
		zephir_create_array(return_value, 2, 0);
		zephir_array_fast_append(return_value, sanitizerKey);
		zephir_array_fast_append(return_value, sanitizer);
		RETURN_MM();
	}
	zephir_create_array(return_value, 2, 0);
	zephir_array_fast_append(return_value, sanitizer);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_array_fast_append(return_value, &_0);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Filter_Filter(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("services"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("services"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("mapper"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("mapper"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

