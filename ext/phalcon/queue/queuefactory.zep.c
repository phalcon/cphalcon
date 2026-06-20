
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
 * Builds a queue Context from the standard Phalcon config shape. Mirrors
 * Phalcon\Cache\CacheFactory.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_QueueFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue, QueueFactory, phalcon, queue_queuefactory, phalcon_factory_abstractconfigfactory_ce, phalcon_queue_queuefactory_method_entry, 0);

	/**
	 * @var AdapterFactory
	 */
	zend_declare_property_null(phalcon_queue_queuefactory_ce, SL("adapterFactory"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * QueueFactory constructor. A default AdapterFactory is created when none
 * is supplied, so the factory is usable straight from the DI container.
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *factory = NULL, factory_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_NULL(&__$null);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("adapterFactory"), factory);
	ZEPHIR_MM_RESTORE();
}

/**
 * Builds a Context from a config array/object.
 *
 * @param array $config = [
 *     'adapter' => 'memory',
 *     'options' => []
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
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Queue/QueueFactory.zep", 54);
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
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("adapterFactory"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&connectionFactory, &_0, "newinstance", NULL, 0, &name_zv, &options);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&connectionFactory, "createcontext", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Queue_QueueFactory, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Queue\\Exceptions\\Exception");
}

