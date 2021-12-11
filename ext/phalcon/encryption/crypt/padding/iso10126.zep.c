
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class Iso10126
 *
 * @package Phalcon\Encryption\Crypt\Padding
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_Iso10126)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Crypt\\Padding, Iso10126, phalcon, encryption_crypt_padding_iso10126, phalcon_encryption_crypt_padding_iso10126_method_entry, 0);

	zend_class_implements(phalcon_encryption_crypt_padding_iso10126_ce, 1, phalcon_encryption_crypt_padding_padinterface_ce);
	return SUCCESS;
}

/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Iso10126, pad)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zval *paddingSize_param = NULL, counter, padding, _7, _8, _3$$3, _5$$3;
	zend_long paddingSize, ZEPHIR_LAST_CALL_STATUS, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&counter);
	ZVAL_UNDEF(&padding);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paddingSize)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paddingSize_param);
	paddingSize = zephir_get_intval(paddingSize_param);


	ZEPHIR_INIT_VAR(&padding);
	ZVAL_STRING(&padding, "");
	_2 = (paddingSize - 2);
	_1 = 0;
	_0 = 0;
	if (_1 <= _2) {
		while (1) {
			if (_0) {
				_1++;
				if (!(_1 <= _2)) {
					break;
				}
			} else {
				_0 = 1;
			}
			ZEPHIR_INIT_NVAR(&counter);
			ZVAL_LONG(&counter, _1);
			ZEPHIR_CALL_FUNCTION(&_3$$3, "rand", &_4, 259);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_5$$3, "chr", &_6, 257, &_3$$3);
			zephir_check_call_status();
			zephir_concat_self(&padding, &_5$$3);
		}
	}
	ZVAL_LONG(&_7, paddingSize);
	ZEPHIR_CALL_FUNCTION(&_8, "chr", &_6, 257, &_7);
	zephir_check_call_status();
	zephir_concat_self(&padding, &_8);
	RETURN_CCTOR(&padding);
}

/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Iso10126, unpad)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *blockSize_param = NULL, last, length, _0, _1;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(input)
		Z_PARAM_LONG(blockSize)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &input_param, &blockSize_param);
	zephir_get_strval(&input, input_param);
	blockSize = zephir_get_intval(blockSize_param);


	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(&input));
	ZVAL_LONG(&_0, (zephir_get_numberval(&length) - 1));
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&last);
	zephir_substr(&last, &input, zephir_get_intval(&_0), 1 , 0);
	ZEPHIR_RETURN_CALL_FUNCTION("ord", NULL, 258, &last);
	zephir_check_call_status();
	RETURN_MM();
}

