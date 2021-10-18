
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
#include "kernel/operators.h"
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
/**
 * Class Noop
 *
 * @package Phalcon\Crypt\Padding
 */
ZEPHIR_INIT_CLASS(Phalcon_Crypt_Padding_Noop)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Crypt\\Padding, Noop, phalcon, crypt_padding_noop, phalcon_crypt_padding_noop_method_entry, 0);

	zend_class_implements(phalcon_crypt_padding_noop_ce, 1, phalcon_crypt_padding_padinterface_ce);
	return SUCCESS;
}

/**
 * @param int $paddingSize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Crypt_Padding_Noop, pad)
{
	zval *paddingSize_param = NULL;
	zend_long paddingSize;
	zval *this_ptr = getThis();

#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paddingSize)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &paddingSize_param);
	paddingSize = zephir_get_intval(paddingSize_param);


	RETURN_STRING("");
}

/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
PHP_METHOD(Phalcon_Crypt_Padding_Noop, unpad)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long blockSize;
	zval *input_param = NULL, *blockSize_param = NULL;
	zval input;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input);
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


	RETURN_MM_LONG(0);
}

