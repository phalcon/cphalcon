
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
#include "kernel/memory.h"
#include "kernel/operators.h"


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
	zval *id, id_sub;

	ZVAL_UNDEF(&id_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id);
	RETURN_BOOL(1);
}

/**
 * Garbage Collector
 *
 * @param int $max_lifetime
 * @return false|int
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
	zval *path, path_sub, *name, name_sub;

	ZVAL_UNDEF(&path_sub);
	ZVAL_UNDEF(&name_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(path)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &path, &name);
	RETURN_BOOL(1);
}

/**
 * Read
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, read)
{
	zval *id, id_sub;

	ZVAL_UNDEF(&id_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id);
	RETURN_STRING("");
}

/**
 * Refresh the session lifetime without changing the session data
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, updateTimestamp)
{
	zval *id, id_sub, *data, data_sub;

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(id)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &id, &data);
	RETURN_BOOL(1);
}

/**
 * Validate the session id (used when strict mode is enabled)
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, validateId)
{
	zval *id, id_sub;

	ZVAL_UNDEF(&id_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id);
	RETURN_BOOL(1);
}

/**
 * Write
 */
PHP_METHOD(Phalcon_Session_Adapter_Noop, write)
{
	zval *id, id_sub, *data, data_sub;

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&data_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(id)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &id, &data);
	RETURN_BOOL(1);
}

