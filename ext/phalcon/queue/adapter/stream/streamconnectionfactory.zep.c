
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
 */
/**
 * Builds a StreamContext.
 *
 * Options:
 *   - storageDir:   directory holding the queue files (default: system temp).
 *   - pollInterval: milliseconds between consumer poll attempts (default 200).
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamConnectionFactory)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue\\Adapter\\Stream, StreamConnectionFactory, phalcon, queue_adapter_stream_streamconnectionfactory, phalcon_queue_adapter_stream_streamconnectionfactory_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_adapter_stream_streamconnectionfactory_ce, SL("options"), ZEND_ACC_PROTECTED);
	phalcon_queue_adapter_stream_streamconnectionfactory_ce->create_object = zephir_init_properties_Phalcon_Queue_Adapter_Stream_StreamConnectionFactory;

	zend_class_implements(phalcon_queue_adapter_stream_streamconnectionfactory_ce, 1, phalcon_contracts_queue_connectionfactory_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamConnectionFactory, __construct)
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_FUNCTION(&storageDir, "sys_get_temp_dir", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value_string(&_0, SL("storageDir"))) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&storageDir);
		zephir_array_fetch_string(&storageDir, &_1$$3, SL("storageDir"), PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamConnectionFactory.zep", 42);
	}
	pollInterval = 200;
	zephir_read_property(&_2, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_value_string(&_2, SL("pollInterval"))) {
		zephir_read_property(&_3$$4, this_ptr, ZEND_STRL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_memory_observe(&_4$$4);
		zephir_array_fetch_string(&_4$$4, &_3$$4, SL("pollInterval"), PH_NOISY, "phalcon/Queue/Adapter/Stream/StreamConnectionFactory.zep", 48);
		pollInterval = zephir_get_intval(&_4$$4);
	}
	object_init_ex(return_value, phalcon_queue_adapter_stream_streamcontext_ce);
	ZVAL_LONG(&_5, pollInterval);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &storageDir, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Queue_Adapter_Stream_StreamConnectionFactory(zend_class_entry *class_type)
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

