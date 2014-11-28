/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "async.h"
#include "exception.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"

/**
 * Phalcon\Async
 */
zend_class_entry *phalcon_async_ce;

PHP_METHOD(Phalcon_Async, call);
PHP_METHOD(Phalcon_Async, recv);
PHP_METHOD(Phalcon_Async, recvAll);
PHP_METHOD(Phalcon_Async, count);
PHP_METHOD(Phalcon_Async, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_async_call, 0, 0, 1)
	ZEND_ARG_INFO(0, closure)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_async_recv, 0, 0, 1)
	ZEND_ARG_INFO(0, async)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_async_method_entry[] = {
	PHP_ME(Phalcon_Async, call, arginfo_phalcon_async_call, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Async, recv, arginfo_phalcon_async_recv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Async, recvAll, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Async, count, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Phalcon_Async, clear, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

/**
 * Phalcon\Async initializer
 */
PHALCON_INIT_CLASS(Phalcon_Async){

	PHALCON_REGISTER_CLASS(Phalcon, Async, async, phalcon_async_method_entry, 0);

	zend_declare_property_long(phalcon_async_ce, SL("_num"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_string(phalcon_async_ce, SL("_filename"), __FILE__, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);
	zend_declare_property_string(phalcon_async_ce, SL("_proj"), "a", ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_async_ce, SL("NOWAIT"),		PHALCON_ASYNC_NOWAIT TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_async_ce, SL("MSG_NOERROR"),	PHALCON_ASYNC_MSG_NOERROR TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_async_ce, SL("MSG_EXCEPT"),	PHALCON_ASYNC_MSG_EXCEPT TSRMLS_CC);

	return SUCCESS;
}

/**
 * Called asynchronous
 *
 *<code>
 *	$async = Phalcon\Async::call(function () {
 *		return 'one';
 *	 });
 *</code>
 *
 * @param closure $callable
 * @return int
 */
PHP_METHOD(Phalcon_Async, call){

	zval *callable, *arguments = NULL;
	zval *pid = NULL, *child_num, *filename, *proj, *key = NULL, *seg = NULL;
	zval *result, *sig;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &callable, &arguments);

	if (Z_TYPE_P(callable) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(callable), zend_ce_closure TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Callable must be an closure object");
		RETURN_MM();
	}

	if (!arguments) {
		arguments = PHALCON_GLOBAL(z_null);
	} else {
		PHALCON_SEPARATE_PARAM(arguments);
	}

	if (Z_TYPE_P(arguments) != IS_ARRAY) {
		PHALCON_INIT_NVAR(arguments);
		array_init(arguments);
	}

	PHALCON_CALL_FUNCTION(&pid, "pcntl_fork");

	if (PHALCON_LT_LONG(pid, 0)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_exception_ce, "Callable must be an closure object");
		RETURN_MM();
	}

	if (PHALCON_GT_LONG(pid, 0)) {
		PHALCON_OBS_VAR(child_num);
		phalcon_read_static_property_ce(&child_num, phalcon_async_ce, SL("_num") TSRMLS_CC);

		phalcon_increment(child_num);

		phalcon_update_static_property_ce(phalcon_async_ce, SL("_num"), child_num TSRMLS_CC);

		RETURN_CTOR(pid);
	}

	PHALCON_OBS_VAR(filename);
	phalcon_read_static_property_ce(&filename, phalcon_async_ce, SL("_filename") TSRMLS_CC);

	PHALCON_OBS_VAR(proj);
	phalcon_read_static_property_ce(&proj, phalcon_async_ce, SL("_proj") TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&key, "ftok", filename, proj);

	PHALCON_CALL_FUNCTION(&seg, "msg_get_queue", key);

	PHALCON_INIT_VAR(result);
	PHALCON_CALL_USER_FUNC_ARRAY(result, callable, arguments);

	PHALCON_CALL_FUNCTION(&pid, "posix_getpid");

	PHALCON_CALL_FUNCTION(NULL, "msg_send", seg, pid, result);

	PHALCON_INIT_VAR(sig);
	if (zend_get_constant(SL("SIGKILL"), sig TSRMLS_CC)) {
		PHALCON_CALL_FUNCTION(NULL, "posix_kill", pid, sig);
	}

	PHALCON_MM_RESTORE();
}

/**
 * Gets asynchronous result
 *
 *<code>
 *	$id = Phalcon\Async::call(function () {
 *		return 'one';
 *	});
 *	$data = Phalcon\Async::recv($id);
 *</code>
 *
 * @param int $pid
 * @param int $flag
 * @return mixed
 */
PHP_METHOD(Phalcon_Async, recv){

	zval *pid = NULL, *flag = NULL, *filename, *proj, *key = NULL, *seg = NULL;
	zval *type, *size, *message, *result = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 2, &pid, &flag);

	if (!pid) {
		PHALCON_INIT_VAR(pid);
		ZVAL_LONG(pid, 0);
	} else if (Z_TYPE_P(pid) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(pid);
		convert_to_long_ex(&pid);
	}

	if (!flag) {
		PHALCON_INIT_VAR(flag);
		ZVAL_LONG(flag, 0);
	} else if (Z_TYPE_P(pid) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(flag);
		convert_to_long_ex(&flag);
	}

	PHALCON_OBS_VAR(filename);
	phalcon_read_static_property_ce(&filename, phalcon_async_ce, SL("_filename") TSRMLS_CC);

	PHALCON_OBS_VAR(proj);
	phalcon_read_static_property_ce(&proj, phalcon_async_ce, SL("_proj") TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&key, "ftok", filename, proj);

	PHALCON_CALL_FUNCTION(&seg, "msg_get_queue", key);

	PHALCON_INIT_VAR(type);
	PHALCON_INIT_VAR(message);

	PHALCON_INIT_VAR(size);
	ZVAL_LONG(size, 1024);

	PHALCON_CALL_FUNCTION(&result, "msg_receive", seg, pid, type, size, message, PHALCON_GLOBAL(z_true), flag);

	if (zend_is_true(result)) {
		RETURN_CTOR(message);
	}

	RETURN_MM_FALSE;
}

/**
 * Gets all asynchronous result
 *
 *<code>
 *	$id = Phalcon\Async::call(function () {
 *		return 'one';
 *	});
 *	$data = Phalcon\Async::recvAll();
 *</code>
 *
 * @return array
 */
PHP_METHOD(Phalcon_Async, recvAll){

	zval *flag = NULL, *num, *filename, *proj, *key = NULL, *seg = NULL;
	zval *pid, *type = NULL, *size, *message = NULL, *result = NULL;
	int i = 0;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &flag);

	if (!flag) {
		PHALCON_INIT_VAR(flag);
		ZVAL_LONG(flag, 0);
	} else if (Z_TYPE_P(pid) != IS_LONG) {
		PHALCON_SEPARATE_PARAM(flag);
		convert_to_long_ex(&flag);
	}

	PHALCON_OBS_VAR(num);
	phalcon_read_static_property_ce(&num, phalcon_async_ce, SL("_num") TSRMLS_CC);

	i = phalcon_get_intval(num);

	PHALCON_OBS_VAR(filename);
	phalcon_read_static_property_ce(&filename, phalcon_async_ce, SL("_filename") TSRMLS_CC);

	PHALCON_OBS_VAR(proj);
	phalcon_read_static_property_ce(&proj, phalcon_async_ce, SL("_proj") TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&key, "ftok", filename, proj);

	PHALCON_CALL_FUNCTION(&seg, "msg_get_queue", key);

	PHALCON_INIT_VAR(pid);
	ZVAL_LONG(pid, 0);

	PHALCON_INIT_VAR(size);
	ZVAL_LONG(size, 1024);

	array_init(return_value);

	while(i--) {
		PHALCON_INIT_NVAR(type);
		PHALCON_INIT_NVAR(message);

		PHALCON_CALL_FUNCTION(&result, "msg_receive", seg, pid, type, size, message, PHALCON_GLOBAL(z_true), flag);
		if (zend_is_true(result)) {
			phalcon_array_update_zval(&return_value, type, message, PH_COPY);
		} else {
			phalcon_array_update_zval(&return_value, type, PHALCON_GLOBAL(z_null), PH_COPY);
		}
		
	}

	PHALCON_MM_RESTORE();
}

/**
 * Gets result count
 *
 *<code>
 *	Phalcon\Async::count();
 *</code>
 *
 * @return int
 */
PHP_METHOD(Phalcon_Async, count){

	zval *filename, *proj, *key = NULL, *seg = NULL;
	zval *result = NULL, *num;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(filename);
	phalcon_read_static_property_ce(&filename, phalcon_async_ce, SL("_filename") TSRMLS_CC);

	PHALCON_OBS_VAR(proj);
	phalcon_read_static_property_ce(&proj, phalcon_async_ce, SL("_proj") TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&key, "ftok", filename, proj);

	PHALCON_CALL_FUNCTION(&seg, "msg_get_queue", key);

	PHALCON_CALL_FUNCTION(&result, "msg_stat_queue", seg);

	if (phalcon_array_isset_string_fetch(&num, result, SS("msg_qnum"))) {
		RETURN_CTOR(num);
	}

	RETURN_MM_FALSE;
}

/**
 * Gets result count
 *
 *<code>
 *	Phalcon\Async::clear();
 *</code>
 *
 * @return bool
 */
PHP_METHOD(Phalcon_Async, clear){

	zval *filename, *proj, *key = NULL, *seg = NULL;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(filename);
	phalcon_read_static_property_ce(&filename, phalcon_async_ce, SL("_filename") TSRMLS_CC);

	PHALCON_OBS_VAR(proj);
	phalcon_read_static_property_ce(&proj, phalcon_async_ce, SL("_proj") TSRMLS_CC);

	PHALCON_CALL_FUNCTION(&key, "ftok", filename, proj);

	PHALCON_CALL_FUNCTION(&seg, "msg_get_queue", key);

	PHALCON_RETURN_CALL_FUNCTION("msg_remove_queue", seg);

	PHALCON_MM_RESTORE();
}
