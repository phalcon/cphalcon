
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
 * @package Phalcon\Encryption\Crypt\Padding
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_Noop)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Crypt\\Padding, Noop, phalcon, encryption_crypt_padding_noop, phalcon_encryption_crypt_padding_noop_method_entry, 0);

	zend_class_implements(phalcon_encryption_crypt_padding_noop_ce, 1, phalcon_encryption_crypt_padding_padinterface_ce);
	return SUCCESS;
}

/**
 * @param int $paddingSize
 *
 * @return string
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Noop, pad)
{
	zval *paddingSize_param = NULL;
	zend_long paddingSize;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paddingSize)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &paddingSize_param);
	RETURN_STRING("");
}

/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
PHP_METHOD(Phalcon_Encryption_Crypt_Padding_Noop, unpad)
{
	zend_long blockSize;
	zval input_zv, *blockSize_param = NULL;
	zend_string *input = NULL;

	ZVAL_UNDEF(&input_zv);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(input)
		Z_PARAM_LONG(blockSize)
	ZEND_PARSE_PARAMETERS_END();
	blockSize_param = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&input_zv, input);
	RETURN_LONG(0);
}

