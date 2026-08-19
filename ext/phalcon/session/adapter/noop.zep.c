
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


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

	zend_class_implements(phalcon_session_adapter_noop_ce, 1, php_session_iface_entry);
	zend_class_implements(phalcon_session_adapter_noop_ce, 1, php_session_update_timestamp_iface_entry);
	return SUCCESS;
}

/**
 * Close
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, close)
{

	RETURN_BOOL(1);
}

/**
 * Destroy
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, destroy)
{
	zval id_zv;
	zend_string *id = NULL;

	ZVAL_UNDEF(&id_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&id_zv, id);
	RETURN_BOOL(1);
}

/**
 * Garbage Collector
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, gc)
{
	zval *max_lifetime_param = NULL;
	zend_long max_lifetime;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(max_lifetime)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &max_lifetime_param);
	RETURN_LONG(1);
}

/**
 * Open
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, open)
{
	zval path_zv, name_zv;
	zend_string *path = NULL, *name = NULL;

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&name_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(path)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&path_zv, path);
	ZVAL_STR(&name_zv, name);
	RETURN_BOOL(1);
}

/**
 * Read
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, read)
{
	zval id_zv;
	zend_string *id = NULL;

	ZVAL_UNDEF(&id_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&id_zv, id);
	RETURN_STRING("");
}

/**
 * Refresh the session lifetime without changing the session data
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, updateTimestamp)
{
	zval id_zv, data_zv;
	zend_string *id = NULL, *data = NULL;

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&data_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(id)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&id_zv, id);
	ZVAL_STR(&data_zv, data);
	RETURN_BOOL(1);
}

/**
 * Validate the session id (used when strict mode is enabled)
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, validateId)
{
	zval id_zv;
	zend_string *id = NULL;

	ZVAL_UNDEF(&id_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&id_zv, id);
	RETURN_BOOL(1);
}

/**
 * Write
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, write)
{
	zval id_zv, data_zv;
	zend_string *id = NULL, *data = NULL;

	ZVAL_UNDEF(&id_zv);
	ZVAL_UNDEF(&data_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(id)
		Z_PARAM_STR(data)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&id_zv, id);
	ZVAL_STR(&data_zv, data);
	RETURN_BOOL(1);
}

