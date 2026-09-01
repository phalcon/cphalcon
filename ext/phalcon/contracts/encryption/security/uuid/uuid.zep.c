
#ifdef HAVE_CONFIG_H
#include "../../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../../php_ext.h"
#include "../../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Canonical marker contract for UUID version adapters.
 *
 * Also carries the standard RFC 4122 namespace UUIDs as constants.
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_Uuid_Uuid)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Security\\Uuid, Uuid, phalcon, contracts_encryption_security_uuid_uuid, NULL);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_encryption_security_uuid_uuid_ce, SL("NAMESPACE_DNS"), "6ba7b810-9dad-11d1-80b4-00c04fd430c8");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_encryption_security_uuid_uuid_ce, SL("NAMESPACE_OID"), "6ba7b812-9dad-11d1-80b4-00c04fd430c8");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_encryption_security_uuid_uuid_ce, SL("NAMESPACE_URL"), "6ba7b811-9dad-11d1-80b4-00c04fd430c8");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_encryption_security_uuid_uuid_ce, SL("NAMESPACE_X500"), "6ba7b814-9dad-11d1-80b4-00c04fd430c8");

	return SUCCESS;
}

