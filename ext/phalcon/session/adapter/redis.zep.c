
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
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Session\Adapter\Redis
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter_Redis) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Session\\Adapter, Redis, phalcon, session_adapter_redis, phalcon_session_adapter_abstractadapter_ce, phalcon_session_adapter_redis_method_entry, 0);

	return SUCCESS;

}

/**
 * Constructor
 *
 * @param array options = [
 *     'prefix' => 'sess-reds-',
 *     'host' => '127.0.0.1',
 *     'port' => 6379,
 *     'index' => 0,
 *     'persistent' => false,
 *     'auth' => '',
 *     'socket' => ''
 * ]
 */
PHP_METHOD(Phalcon_Session_Adapter_Redis, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *factory, factory_sub, *options_param = NULL, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &factory, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
	ZEPHIR_OBS_COPY_OR_DUP(&options, options_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "sess-reds-");
	zephir_array_update_string(&options, SL("prefix"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "redis");
	ZEPHIR_CALL_METHOD(&_1, factory, "newinstance", NULL, 0, &_2, &options);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("adapter"), &_1);
	ZEPHIR_MM_RESTORE();

}

