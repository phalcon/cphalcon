
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


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
 * Builds a BeanstalkContext.
 *
 * Options:
 *   - host:         server host (default 127.0.0.1).
 *   - port:         server port (default 11300).
 *   - persistent:   use a persistent socket (default false).
 *   - ttr:          default time-to-run in seconds for every job (default 86400).
 *   - pollInterval: milliseconds between subscription poll passes (default 200).
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnectionFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Beanstalk, BeanstalkConnectionFactory, phalcon, queue_adapter_beanstalk_beanstalkconnectionfactory, phalcon_queue_adapter_beanstalk_beanstalkconnectionfactory_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_adapter_beanstalk_beanstalkconnectionfactory_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_queue_adapter_beanstalk_beanstalkconnectionfactory_ce->create_object = zephir_init_properties_Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnectionFactory;

	zend_class_implements(phalcon_queue_adapter_beanstalk_beanstalkconnectionfactory_ce, 1, phalcon_contracts_queue_connectionfactory_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnectionFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &options_param);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnectionFactory, createContext)
{
	zval options, host, port, persistent, ttr, pollInterval, _0, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&host);
	ZVAL_UNDEF(&port);
	ZVAL_UNDEF(&persistent);
	ZVAL_UNDEF(&ttr);
	ZVAL_UNDEF(&pollInterval);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&options, &_0);
	if (zephir_array_isset_value_string(&options, SL("host"))) {
		zephir_memory_observe(&host);
		zephir_array_fetch_string(&host, &options, SL("host"), PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnectionFactory.zep", 52);
	} else {
		ZEPHIR_INIT_NVAR(&host);
		ZVAL_STRING(&host, "127.0.0.1");
	}
	if (zephir_array_isset_value_string(&options, SL("port"))) {
		zephir_memory_observe(&_1);
		zephir_array_fetch_string(&_1, &options, SL("port"), PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnectionFactory.zep", 53);
		ZEPHIR_INIT_VAR(&port);
		ZVAL_LONG(&port, zephir_get_intval(&_1));
	} else {
		ZEPHIR_INIT_NVAR(&port);
		ZVAL_LONG(&port, 11300);
	}
	if (zephir_array_isset_value_string(&options, SL("persistent"))) {
		zephir_memory_observe(&_2);
		zephir_array_fetch_string(&_2, &options, SL("persistent"), PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnectionFactory.zep", 54);
		ZEPHIR_INIT_VAR(&persistent);
		ZVAL_BOOL(&persistent, zephir_get_boolval(&_2));
	} else {
		ZEPHIR_INIT_NVAR(&persistent);
		ZVAL_BOOL(&persistent, 0);
	}
	if (zephir_array_isset_value_string(&options, SL("ttr"))) {
		ZEPHIR_OBS_NVAR(&_2);
		zephir_array_fetch_string(&_2, &options, SL("ttr"), PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnectionFactory.zep", 55);
		ZEPHIR_INIT_VAR(&ttr);
		ZVAL_LONG(&ttr, zephir_get_intval(&_2));
	} else {
		ZEPHIR_INIT_NVAR(&ttr);
		ZVAL_LONG(&ttr, 86400);
	}
	if (zephir_array_isset_value_string(&options, SL("pollInterval"))) {
		zephir_memory_observe(&_3);
		zephir_array_fetch_string(&_3, &options, SL("pollInterval"), PH_NOISY, "phalcon/Queue/Adapter/Beanstalk/BeanstalkConnectionFactory.zep", 56);
		ZEPHIR_INIT_VAR(&pollInterval);
		ZVAL_LONG(&pollInterval, zephir_get_intval(&_3));
	} else {
		ZEPHIR_INIT_NVAR(&pollInterval);
		ZVAL_LONG(&pollInterval, 200);
	}
	object_init_ex(return_value, phalcon_queue_adapter_beanstalk_beanstalkcontext_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &host, &port, &persistent, &ttr, &pollInterval);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Queue_Adapter_Beanstalk_BeanstalkConnectionFactory(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("options"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

