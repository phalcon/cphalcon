
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
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Exception_InvalidPaddingSize)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Encryption\\Crypt\\Exception, InvalidPaddingSize, phalcon, encryption_crypt_exception_invalidpaddingsize, phalcon_encryption_crypt_exception_exception_ce, phalcon_encryption_crypt_exception_invalidpaddingsize_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Encryption_Crypt_Exception_InvalidPaddingSize, __construct)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Padding size cannot be less than 0 or greater than 256");
	ZEPHIR_CALL_PARENT(NULL, phalcon_encryption_crypt_exception_invalidpaddingsize_ce, getThis(), "__construct", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

