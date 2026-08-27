
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
#include "kernel/fcall.h"
#include "kernel/array.h"


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
 * Builds a StreamContext.
 *
 * Options:
 *   - storageDir:   directory holding the queue files (default: a private
 *                   "phalcon_queue" subdirectory of the system temp dir).
 *   - pollInterval: milliseconds between consumer poll attempts (default 200).
 *
 * @phpstan-import-type queue_stream_options from QueueTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamConnectionFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Stream, StreamConnectionFactory, phalcon, queue_adapter_stream_streamconnectionfactory, phalcon_queue_adapter_stream_streamconnectionfactory_method_entry, 0);

	/**
	 * @phpstan-param queue_stream_options $options
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_queue_adapter_stream_streamconnectionfactory_ce, SL("options"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	zend_class_implements(phalcon_queue_adapter_stream_streamconnectionfactory_ce, 1, phalcon_contracts_queue_connectionfactory_ce);
	return SUCCESS;
}

/**
 * @phpstan-param queue_stream_options $options
 */
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConnectionFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 1287, &options);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConnectionFactory, createContext)
{
	zval storageDir, _0, _2, _5, _1$$3, _3$$4, _4$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pollInterval = 0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storageDir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("options", 7, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_FUNCTION(&storageDir, "sys_get_temp_dir", NULL, 0);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 1287, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value_string(&_0, SL("storageDir"))) {
		zephir_read_property_cached(&_1$$3, this_ptr, _zephir_prop_0, 1287, PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&storageDir);
		zephir_array_fetch_string(&storageDir, &_1$$3, SL("storageDir"), PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamConnectionFactory.zep", 58);
	}
	pollInterval = 200;
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 1287, PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value_string(&_2, SL("pollInterval"))) {
		zephir_read_property_cached(&_3$$4, this_ptr, _zephir_prop_0, 1287, PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_4$$4);
		zephir_array_fetch_string(&_4$$4, &_3$$4, SL("pollInterval"), PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamConnectionFactory.zep", 64);
		pollInterval = zephir_get_intval(&_4$$4);
	}
	object_init_ex(return_value, phalcon_queue_adapter_stream_streamcontext_ce);
	ZVAL_LONG(&_5, pollInterval);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &storageDir, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

