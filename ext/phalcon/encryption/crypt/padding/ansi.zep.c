
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
#include "kernel/concat.h"
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
 * Class Ansi
 *
 * @package Phalcon\Encryption\Crypt\Padding
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_Ansi)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Crypt\\Padding, Ansi, phalcon, encryption_crypt_padding_ansi, phalcon_encryption_crypt_padding_ansi_method_entry, 0);

	zend_class_implements(phalcon_encryption_crypt_padding_ansi_ce, 1, phalcon_encryption_crypt_padding_padinterface_ce);
	return SUCCESS;
}

/**
 * @param int $paddingSize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Ansi, pad)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *paddingSize_param = NULL, _0, _1, _2, _3;
	zend_long paddingSize, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paddingSize)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &paddingSize_param);
	paddingSize = zephir_get_intval(paddingSize_param);


	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&_1, "chr", NULL, 257, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, (paddingSize - 1));
	ZEPHIR_CALL_FUNCTION(&_2, "str_repeat", NULL, 1, &_1, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, paddingSize);
	ZEPHIR_CALL_FUNCTION(&_3, "chr", NULL, 257, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_2, &_3);
	RETURN_MM();
}

/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Ansi, unpad)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, ZEPHIR_LAST_CALL_STATUS;
	zval *input_param = NULL, *blockSize_param = NULL, last, length, ord, padding, paddingSize, repeat, _0, _1, _2$$4, _3$$4, _4$$3, _5$$3;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&last);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&ord);
	ZVAL_UNDEF(&padding);
	ZVAL_UNDEF(&paddingSize);
	ZVAL_UNDEF(&repeat);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
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


	ZEPHIR_INIT_VAR(&paddingSize);
	ZVAL_LONG(&paddingSize, 0);
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(&input));
	ZVAL_LONG(&_0, (zephir_get_numberval(&length) - 1));
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&last);
	zephir_substr(&last, &input, zephir_get_intval(&_0), 1 , 0);
	ZEPHIR_CALL_FUNCTION(&ord, "ord", NULL, 258, &last);
	zephir_check_call_status();
	if (ZEPHIR_LE_LONG(&ord, blockSize)) {
		ZEPHIR_CPY_WRT(&paddingSize, &ord);
		ZEPHIR_INIT_VAR(&repeat);
		ZVAL_STRING(&repeat, "");
		if (ZEPHIR_GT_LONG(&paddingSize, 1)) {
			ZVAL_LONG(&_2$$4, 0);
			ZEPHIR_CALL_FUNCTION(&_3$$4, "chr", NULL, 257, &_2$$4);
			zephir_check_call_status();
			ZVAL_LONG(&_2$$4, (zephir_get_numberval(&paddingSize) - 1));
			ZEPHIR_CALL_FUNCTION(&repeat, "str_repeat", NULL, 1, &_3$$4, &_2$$4);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&padding);
		ZEPHIR_CONCAT_VV(&padding, &repeat, &last);
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_sub_function(&_4$$3, &length, &paddingSize);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_substr(&_5$$3, &input, zephir_get_intval(&_4$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		if (!ZEPHIR_IS_IDENTICAL(&_5$$3, &padding)) {
			ZEPHIR_INIT_NVAR(&paddingSize);
			ZVAL_LONG(&paddingSize, 0);
		}
	}
	RETURN_CCTOR(&paddingSize);
}

