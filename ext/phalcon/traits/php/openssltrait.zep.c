
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * OpenSSL based wrapper methods
 */
ZEPHIR_INIT_CLASS(Phalcon_Traits_Php_OpensslTrait)
{
	ZEPHIR_REGISTER_TRAIT(Phalcon\\Traits\\Php, OpensslTrait, phalcon, traits_php_openssltrait, phalcon_traits_php_openssltrait_method_entry);

	return SUCCESS;
}

/**
 * @param string $cipher
 *
 * @return int|bool
 *
 * @link https://php.net/manual/en/function.openssl-cipher-iv-length.php
 */
PHP_METHOD(Phalcon_Traits_Php_OpensslTrait, phpOpensslCipherIvLength)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval cipher_zv;
	zend_string *cipher = NULL;

	ZVAL_UNDEF(&cipher_zv);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(cipher)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&cipher_zv);
	ZVAL_STR_COPY(&cipher_zv, cipher);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_cipher_iv_length", NULL, 0, &cipher_zv);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @param int $length
 *
 * @return string|false
 *
 * @link https://php.net/manual/en/function.openssl-random-pseudo-bytes.php
 */
PHP_METHOD(Phalcon_Traits_Php_OpensslTrait, phpOpensslRandomPseudoBytes)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *length_param = NULL, _0;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &length_param);
	ZVAL_LONG(&_0, length);
	ZEPHIR_RETURN_CALL_FUNCTION("openssl_random_pseudo_bytes", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

