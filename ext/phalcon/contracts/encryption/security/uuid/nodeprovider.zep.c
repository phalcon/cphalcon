
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
 *
 * Implementation of this file has been influenced by sinbadxiii/cphalcon-uuid
 * @link    https://github.com/sinbadxiii/cphalcon-uuid
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Encryption_Security_Uuid_NodeProvider)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Encryption\\Security\\Uuid, NodeProvider, phalcon, contracts_encryption_security_uuid_nodeprovider, phalcon_contracts_encryption_security_uuid_nodeprovider_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(Phalcon_Contracts_Encryption_Security_Uuid_NodeProvider, getNode);
