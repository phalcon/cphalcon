
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
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Padding based on ISO-IEK
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_IsoIek)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Crypt\\Padding, IsoIek, phalcon, encryption_crypt_padding_isoiek, phalcon_encryption_crypt_padding_isoiek_method_entry, 0);

	zend_class_implements(phalcon_encryption_crypt_padding_isoiek_ce, 1, phalcon_encryption_crypt_padding_padinterface_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Crypt_Padding_IsoIek, pad)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *paddingSize_param = NULL, _0, _1, _3, _4;
	zend_long paddingSize, ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paddingSize)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &paddingSize_param);
	ZVAL_LONG(&_0, 0x80);
	ZEPHIR_CALL_FUNCTION(&_1, "chr", &_2, 0, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_FUNCTION(&_3, "chr", &_2, 0, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, (paddingSize - 1));
	ZEPHIR_CALL_FUNCTION(&_4, "str_repeat", NULL, 5, &_3, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VV(return_value, &_1, &_4);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM();
}

PHP_METHOD(Phalcon_Encryption_Crypt_Padding_IsoIek, unpad)
{
	zend_bool _4, _6, _9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long blockSize, ZEPHIR_LAST_CALL_STATUS, counter = 0, paddingSize = 0;
	zval input_zv, *blockSize_param = NULL, length, inputArray, zero, _0, _2, _3, _5, _7, _8;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&inputArray);
	ZVAL_UNDEF(&zero);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
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
	ZEPHIR_CALL_FUNCTION(&zero, "chr", &_1, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(&input_zv));
	ZEPHIR_CALL_FUNCTION(&inputArray, "str_split", NULL, 215, &input_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_LONG(&_2, 1);
	ZEPHIR_INIT_VAR(&_3);
	zephir_sub_function(&_3, &length, &_2);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	counter = zephir_get_intval(&_3);
	while (1) {
		_4 = counter > 0;
		if (_4) {
			ZEPHIR_OBS_NVAR(&_5);
			zephir_array_fetch_long(&_5, &inputArray, counter, PH_NOISY, "phalcon/Encryption/Crypt/Padding/IsoIek.zep", 36);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_4 = ZEPHIR_IS_IDENTICAL(&_5, &zero);
		}
		_6 = _4;
		if (_6) {
			_6 = paddingSize < blockSize;
		}
		if (!(_6)) {
			break;
		}
		paddingSize++;
		counter--;
	}
	zephir_memory_observe(&_7);
	zephir_array_fetch_long(&_7, &inputArray, counter, PH_NOISY, "phalcon/Encryption/Crypt/Padding/IsoIek.zep", 43);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZVAL_LONG(&_0, 0x80);
	ZEPHIR_CALL_FUNCTION(&_8, "chr", &_1, 0, &_0);
	zephir_check_call_status();
	_9 = ZEPHIR_IS_EQUAL(&_7, &_8);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_9) {
		paddingSize++;
	} else {
		paddingSize = 0;
	}
	RETURN_MM_LONG(paddingSize);
}

