
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */
/**
 * Generates a random 48-bit node with the multicast bit set.
 *
 * Used as a fallback when no hardware MAC address is available.
 *
 * @link https://www.ietf.org/rfc/rfc4122.txt Section 4.5
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Security_Uuid_RandomNodeProvider)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Encryption\\Security\\Uuid, RandomNodeProvider, phalcon, encryption_security_uuid_randomnodeprovider, phalcon_encryption_security_uuid_randomnodeprovider_method_entry, 0);

	zend_class_implements(phalcon_encryption_security_uuid_randomnodeprovider_ce, 1, phalcon_encryption_security_uuid_nodeproviderinterface_ce);
	return SUCCESS;
}

/**
 * Returns a random 12-character hex node with the multicast bit set.
 */
PHP_METHOD(Phalcon_Encryption_Security_Uuid_RandomNodeProvider, getNode)
{
	zval nodeBytes, _0, _1, _2, _3, _4, _5, _6, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&nodeBytes);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZVAL_LONG(&_0, 6);
	ZEPHIR_CALL_FUNCTION(&nodeBytes, "random_bytes", NULL, 272, &_0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &nodeBytes, 0 , 1 , 0);
	ZEPHIR_CALL_FUNCTION(&_3, "ord", NULL, 249, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_4, ((int) (zephir_get_numberval(&_3)) | 0x01));
	ZEPHIR_CALL_FUNCTION(&_5, "chr", NULL, 248, &_4);
	zephir_check_call_status();
	ZVAL_LONG(&_4, 1);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &nodeBytes, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VV(&_7, &_5, &_6);
	ZEPHIR_CPY_WRT(&nodeBytes, &_7);
	ZEPHIR_RETURN_CALL_FUNCTION("bin2hex", NULL, 282, &nodeBytes);
	zephir_check_call_status();
	RETURN_MM();
}

