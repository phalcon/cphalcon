
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
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
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */
/**
 * Builds a queue Context from the standard Phalcon config shape. Mirrors
 * Phalcon\Cache\CacheFactory.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_QueueFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue, QueueFactory, phalcon, queue_queuefactory, phalcon_queue_queuefactory_method_entry, 0);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_queue_queuefactory_ce, SL("adapterFactory"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Queue\\AdapterFactory"));
	}

	return SUCCESS;
}

/**
 * A default AdapterFactory is created when none is supplied, so the
 * factory is usable straight from the DI container.
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *factory = NULL, factory_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapterFactory", 14, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(factory, phalcon_queue_adapterfactory_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &factory);
	if (!factory) {
		factory = &factory_sub;
		ZEPHIR_CPY_WRT(factory, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(factory);
	}
	if (Z_TYPE_P(factory) == IS_NULL) {
		ZEPHIR_INIT_NVAR(factory);
		object_init_ex(factory, phalcon_queue_adapterfactory_ce);
		ZEPHIR_CALL_METHOD(NULL, factory, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1310, factory);
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a Context from a config array/object.
 *
 * @param array<string, mixed>|ConfigInterface $config = [
 *     'adapter' => 'memory',
 *     'options' => [],
 * ]
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, name, options, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "adapter");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfigelement", NULL, 0, config, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	zephir_memory_observe(&name);
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Queue/QueueFactory.zep", 64);
	zephir_memory_observe(&options);
	if (!(zephir_array_isset_string_fetch(&options, config, SL("options"), 0))) {
		ZEPHIR_INIT_NVAR(&options);
		array_init(&options);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Builds a Context for the named adapter.
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval name_zv, *options_param = NULL, connectionFactory, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&connectionFactory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("adapterFactory", 14, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1310, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&connectionFactory, &_0, "newinstance", NULL, 0, &name_zv, &options);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&connectionFactory, "createcontext", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Returns the exception class for the factory
 *
 * @return class-string<\Throwable>
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Queue\\Exceptions\\Exception");
}

/**
 * @param array<string, mixed>|ConfigInterface $config
 *
 * @return array<string, mixed>
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, checkConfig)
{
	zend_class_entry *_3$$4;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, exceptionClass, _1$$4, _2$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	_0 = Z_TYPE_P(config) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(config, phalcon_config_configinterface_ce);
	}
	if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(config, "toarray", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	if (Z_TYPE_P(config) != IS_ARRAY) {
		ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_fetch_safe_class(&_2$$4, &exceptionClass);
		_3$$4 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_2$$4), Z_STRLEN_P(&_2$$4), ZEND_FETCH_CLASS_AUTO);
		if(!_3$$4) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_1$$4, _3$$4);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_1$$4);
		zephir_check_call_status();
		if (zephir_has_constructor(&_1$$4)) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, "Config must be array or Phalcon\\Config\\Config object");
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 0, &_4$$4);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_1$$4, "phalcon/Traits/Factory/ConfigTrait.zep", 34);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETVAL_ZVAL(config, 1, 0);
	RETURN_MM();
}

/**
 * Checks if the config has a specific element
 *
 * @param array  $config
 * @param string $element
 *
 * @return array
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, checkConfigElement)
{
	zval _3$$3;
	zend_class_entry *_2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_string *element = NULL;
	zval *config_param = NULL, element_zv, exceptionClass, _0$$3, _1$$3;
	zval config;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&element_zv);
	ZVAL_UNDEF(&exceptionClass);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		ZEPHIR_Z_PARAM_ARRAY(config, config_param)
		Z_PARAM_STR(element)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	config_param = ZEND_CALL_ARG(execute_data, 1);
	zephir_get_arrval(&config, config_param);
	zephir_memory_observe(&element_zv);
	ZVAL_STR_COPY(&element_zv, element);
	if (!(zephir_array_isset_value(&config, &element_zv))) {
		ZEPHIR_CALL_METHOD(&exceptionClass, this_ptr, "getexceptionclass", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_fetch_safe_class(&_1$$3, &exceptionClass);
		_2$$3 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1$$3), Z_STRLEN_P(&_1$$3), ZEND_FETCH_CLASS_AUTO);
		if(!_2$$3) {
			RETURN_MM_NULL();
		}
		object_init_ex(&_0$$3, _2$$3);
		ZEPHIR_LAST_CALL_STATUS = zephir_check_constructor_access(&_0$$3);
		zephir_check_call_status();
		if (zephir_has_constructor(&_0$$3)) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZEPHIR_CONCAT_SVS(&_3$$3, "You must provide the '", &element_zv, "' option in the factory config parameter.");
			ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0, &_3$$3);
			zephir_check_call_status();
		}

		zephir_throw_exception_debug(&_0$$3, "phalcon/Traits/Factory/ConfigTrait.zep", 56);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CTOR(&config);
}

