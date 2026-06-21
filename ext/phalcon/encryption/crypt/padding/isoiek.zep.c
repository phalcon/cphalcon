
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
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Class IsoIek
 *
 * @package Phalcon\Encryption\Crypt\Padding
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_IsoIek)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Crypt\\Padding, IsoIek, phalcon, encryption_crypt_padding_isoiek, phalcon_encryption_crypt_padding_isoiek_method_entry, 0);

	zend_class_implements(phalcon_encryption_crypt_padding_isoiek_ce, 1, phalcon_encryption_crypt_padding_padinterface_ce);
	return SUCCESS;
}

/**
 * @param int $paddingSize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_IsoIek, pad)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *paddingSize_param = NULL, _0, _1, _2, _3;
	zend_long paddingSize, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paddingSize)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &paddingSize_param);
	ZVAL_LONG(&_0, 0x80);
	ZEPHIR_CALL_FUNCTION(&_1, "chr", NULL, 0, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&_2, "chr", NULL, 0, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, (paddingSize - 1));
	ZEPHIR_CALL_FUNCTION(&_3, "str_repeat", NULL, 6, &_2, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_1, &_3);
	RETURN_MM();
}

/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_IsoIek, unpad)
{
	zend_bool _1, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize, ZEPHIR_LAST_CALL_STATUS, counter = 0, paddingSize = 0;
	zval input_zv, *blockSize_param = NULL, length, inputArray, zero, _0, _2, _4, _5;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&inputArray);
	ZVAL_UNDEF(&zero);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(input)
		Z_PARAM_LONG(blockSize)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	blockSize_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&input_zv);
	ZVAL_STR_COPY(&input_zv, input);
	paddingSize = 0;
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&zero, "chr", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(&input_zv));
	ZEPHIR_CALL_FUNCTION(&inputArray, "str_split", NULL, 191, &input_zv);
	zephir_check_call_status();
	counter = (zephir_get_numberval(&length) - 1);
	while (1) {
		_1 = counter > 0;
		if (_1) {
			zephir_array_fetch_long(&_2, &inputArray, counter, PH_NOISY | PH_READONLY, "phalcon/Encryption/Crypt/Padding/IsoIek.zep", 49);
			_1 = ZEPHIR_IS_IDENTICAL(&_2, &zero);
		}
		_3 = _1;
		if (_3) {
			_3 = paddingSize < blockSize;
		}
		if (!(_3)) {
			break;
		}
		paddingSize++;
		counter--;
	}
	zephir_array_fetch_long(&_4, &inputArray, counter, PH_NOISY | PH_READONLY, "phalcon/Encryption/Crypt/Padding/IsoIek.zep", 56);
	ZVAL_LONG(&_0, 0x80);
	ZEPHIR_CALL_FUNCTION(&_5, "chr", NULL, 0, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EQUAL(&_4, &_5)) {
		paddingSize++;
	} else {
		paddingSize = 0;
	}
	RETURN_MM_LONG(paddingSize);
}

