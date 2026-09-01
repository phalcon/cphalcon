
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
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-auth
 * @link    https://github.com/sinbadxiii/cphalcon-auth
 */
/**
 * Not a valid JSON
 */
ZEPHIR_INIT_CLASS(Phalcon_Auth_Exceptions_FileNotValidJson)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Auth\\Exceptions, FileNotValidJson, phalcon, auth_exceptions_filenotvalidjson, phalcon_auth_exception_ce, phalcon_auth_exceptions_filenotvalidjson_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Auth_Exceptions_FileNotValidJson, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval path_zv, *ex, ex_sub, _1;
	zend_string *path = NULL;

	ZVAL_UNDEF(&path_zv);
	ZVAL_UNDEF(&ex_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(path)
		Z_PARAM_OBJECT_OF_CLASS(ex, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ex = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&path_zv);
	ZVAL_STR_COPY(&path_zv, path);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "Stream adapter file is not valid JSON: ", &path_zv);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_PARENT(NULL, phalcon_auth_exceptions_filenotvalidjson_ce, getThis(), "__construct", NULL, 0, &_0, &_1, ex);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

