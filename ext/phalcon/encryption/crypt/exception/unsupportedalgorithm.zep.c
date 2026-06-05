
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Exception_UnsupportedAlgorithm)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Crypt\\Exception, UnsupportedAlgorithm, phalcon, encryption_crypt_exception_unsupportedalgorithm, phalcon_encryption_crypt_exception_exception_ce, phalcon_encryption_crypt_exception_unsupportedalgorithm_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Crypt_Exception_UnsupportedAlgorithm, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, cipher_zv;
	zend_string *type = NULL, *cipher = NULL;

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&cipher_zv);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_STR(cipher)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_memory_observe(&cipher_zv);
	ZVAL_STR_COPY(&cipher_zv, cipher);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVS(&_0, "The ", &type_zv, " algorithm '", &cipher_zv, "' is not supported on this system.");
	ZEPHIR_CALL_PARENT(NULL, phalcon_encryption_crypt_exception_unsupportedalgorithm_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

