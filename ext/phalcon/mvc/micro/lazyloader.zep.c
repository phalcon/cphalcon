
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
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
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
 * Phalcon\Mvc\Micro\LazyLoader
 *
 * Lazy-Load of handlers for Mvc\Micro using auto-loading
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Micro_LazyLoader)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Micro, LazyLoader, phalcon, mvc_micro_lazyloader, phalcon_mvc_micro_lazyloader_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("definition"), ZEND_ACC_PROTECTED);
	/**
	 * @var object|null
	 */
	zend_declare_property_null(phalcon_mvc_micro_lazyloader_ce, SL("handler"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Phalcon\Mvc\Micro\LazyLoader constructor
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, __construct)
{
	zval definition_zv;
	zend_string *definition = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definition_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&definition_zv, definition);
	zephir_update_property_zval(this_ptr, ZEND_STRL("definition"), &definition_zv);
}

/**
 * Calling __call method
 *
 * @param  array arguments
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, callMethod)
{
	zval _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval method_zv, *arguments = NULL, arguments_sub, *modelBinder = NULL, modelBinder_sub, __$null, handler, definition, bindCacheKey, _0, _5, _1$$4, _2$$4, _3$$5;
	zend_string *method = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method_zv);
	ZVAL_UNDEF(&arguments_sub);
	ZVAL_UNDEF(&modelBinder_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&handler);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&bindCacheKey);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(method)
		Z_PARAM_ZVAL(arguments)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(modelBinder, phalcon_mvc_model_binderinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	arguments = ZEND_CALL_ARG(execute_data, 2);
	if (ZEND_NUM_ARGS() > 2) {
		modelBinder = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&method_zv, method);
	ZEPHIR_SEPARATE_PARAM(arguments);
	if (!modelBinder) {
		modelBinder = &modelBinder_sub;
		modelBinder = &__$null;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&handler, &_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("definition"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&definition, &_0);
	if (Z_TYPE_P(&handler) != IS_OBJECT) {
		if (!(zephir_class_exists(&definition, 1))) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_mvc_micro_exception_ce);
			ZEPHIR_INIT_VAR(&_2$$4);
			ZEPHIR_CONCAT_SVS(&_2$$4, "Handler '", &definition, "' does not exist");
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 32, &_2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Mvc/Micro/LazyLoader.zep", 55);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_NVAR(&handler);
		ZEPHIR_LAST_CALL_STATUS = zephir_create_instance(&handler, &definition);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &handler);
	}
	if (Z_TYPE_P(modelBinder) != IS_NULL) {
		ZEPHIR_INIT_VAR(&bindCacheKey);
		ZEPHIR_CONCAT_SVSV(&bindCacheKey, "_PHMB_", &definition, "_", &method_zv);
		ZEPHIR_CALL_METHOD(&_3$$5, modelBinder, "bindtohandler", NULL, 0, &handler, arguments, &bindCacheKey, &method_zv);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(arguments, &_3$$5);
	}
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_fast_append(&_4, &handler);
	zephir_array_fast_append(&_4, &method_zv);
	ZEPHIR_CALL_FUNCTION(&_5, "array_values", NULL, 13, arguments);
	zephir_check_call_status();
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &_5);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, getDefinition)
{

	RETURN_MEMBER(getThis(), "definition");
}

/**
 * @return object|null
 */
PHP_METHOD(Phalcon_Mvc_Micro_LazyLoader, getHandler)
{

	RETURN_MEMBER(getThis(), "handler");
}

