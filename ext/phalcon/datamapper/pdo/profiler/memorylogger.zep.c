
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Pdo
 * @license https://github.com/atlasphp/Atlas.Pdo/blob/1.x/LICENSE.md
 */
/**
 * A naive memory-based logger.
 *
 * @property array $messages
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\DataMapper\\Pdo\\Profiler, MemoryLogger, phalcon, datamapper_pdo_profiler_memorylogger, zephir_get_internal_ce(SL("psr\\log\\abstractlogger")), phalcon_datamapper_pdo_profiler_memorylogger_method_entry, 0);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_pdo_profiler_memorylogger_ce, SL("messages"), ZEND_ACC_PROTECTED);

	phalcon_datamapper_pdo_profiler_memorylogger_ce->create_object = zephir_init_properties_Phalcon_DataMapper_Pdo_Profiler_MemoryLogger;

	return SUCCESS;

}

/**
 * Returns the logged messages.
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, getMessages) {

	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "messages");

}

/**
 * Logs a message.
 *
 * @param mixed  $level
 * @param string $message
 * @param array  $context
 */
PHP_METHOD(Phalcon_DataMapper_Pdo_Profiler_MemoryLogger, log) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval context, replace;
	zval *level, level_sub, *message, message_sub, *context_param = NULL, key, value, *_0, _1, _6, _4$$3, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&context);
	ZVAL_UNDEF(&replace);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_ZVAL(level)
		Z_PARAM_ZVAL(message)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(context)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level, &message, &context_param);

	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&replace);
	array_init(&replace);
	zephir_is_iterable(&context, 0, "phalcon/DataMapper/Pdo/Profiler/MemoryLogger.zep", 58);
	if (Z_TYPE_P(&context) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			ZEPHIR_CONCAT_SVS(&_4$$3, "{", &key, "}");
			zephir_array_update_zval(&replace, &_4$$3, &value, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &context, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &context, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &context, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&value, &context, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CONCAT_SVS(&_5$$4, "{", &key, "}");
				zephir_array_update_zval(&replace, &_5$$4, &value, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &context, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_FUNCTION(&_6, "strtr", NULL, 5, message, &replace);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("messages"), &_6);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_Phalcon_DataMapper_Pdo_Profiler_MemoryLogger(zend_class_entry *class_type) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("messages"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("messages"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

