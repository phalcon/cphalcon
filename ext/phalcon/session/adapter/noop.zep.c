
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
#include "ext/session/php_session.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Adapter\Noop
 *
 * This is an "empty" or null adapter. It can be used for testing or any
 * other purpose that no session needs to be invoked
 *
 * ```php
 * <?php
 *
 * use Phalcon\Session\Manager;
 * use Phalcon\Session\Adapter\Noop;
 *
 * $session = new Manager();
 * $session->setAdapter(new Noop());
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Noop)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Session\\Adapter, Noop, phalcon, session_adapter_noop, phalcon_session_adapter_noop_method_entry, 0);

	/**
	 * The connection of some adapters
	 *
	 * @var null
	 */
	zend_declare_property_null(phalcon_session_adapter_noop_ce, SL("connection"), ZEND_ACC_PROTECTED);
	/**
	 * Session options
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_session_adapter_noop_ce, SL("options"), ZEND_ACC_PROTECTED);
	/**
	 * Session prefix
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_session_adapter_noop_ce, SL("prefix"), "", ZEND_ACC_PROTECTED);
	/**
	 * Time To Live
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_session_adapter_noop_ce, SL("ttl"), 8600, ZEND_ACC_PROTECTED);
	phalcon_session_adapter_noop_ce->create_object = zephir_init_properties_Phalcon_Session_Adapter_Noop;

	zend_class_implements(phalcon_session_adapter_noop_ce, 1, php_session_iface_entry);
	return SUCCESS;
}

/**
 * Constructor
 *
 * @param array options = [
 *     'prefix' => ''
 * ]
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, prefix;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&prefix);
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


	ZEPHIR_OBS_VAR(&prefix);
	if (!(zephir_array_isset_string_fetch(&prefix, &options, SL("prefix"), 0))) {
		ZEPHIR_INIT_NVAR(&prefix);
		ZVAL_STRING(&prefix, "");
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("prefix"), &prefix);
	zephir_update_property_zval(this_ptr, ZEND_STRL("options"), &options);
	ZEPHIR_MM_RESTORE();
}

/**
 * Close
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, close)
{
	zval *this_ptr = getThis();



	RETURN_BOOL(1);
}

/**
 * Destroy
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, destroy)
{
	zval *sessionId, sessionId_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(sessionId)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &sessionId);


	RETURN_BOOL(1);
}

/**
 * Garbage Collector
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, gc)
{
	zval *maxlifetime, maxlifetime_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&maxlifetime_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(maxlifetime)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &maxlifetime);


	RETURN_BOOL(1);
}

/**
 * Read
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, read)
{
	zval *sessionId, sessionId_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(sessionId)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &sessionId);


	RETURN_STRING("");
}

/**
 * Open
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, open)
{
	zval *savePath, savePath_sub, *sessionName, sessionName_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&savePath_sub);
	ZVAL_UNDEF(&sessionName_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(savePath)
		Z_PARAM_ZVAL(sessionName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &savePath, &sessionName);


	RETURN_BOOL(1);
}

/**
 * Write
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, write)
{
	zval *sessionId, sessionId_sub, *data, data_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sessionId_sub);
	ZVAL_UNDEF(&data_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(sessionId)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(2, 0, &sessionId, &data);


	RETURN_BOOL(1);
}

/**
 * Helper method to get the name prefixed
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, getPrefixedName)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name = NULL, name_sub, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name);
	ZEPHIR_SEPARATE_PARAM(name);


	zephir_cast_to_string(&_0, name);
	ZEPHIR_CPY_WRT(name, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VV(return_value, &_1, name);
	RETURN_MM();
}

zend_object *zephir_init_properties_Phalcon_Session_Adapter_Noop(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

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
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

