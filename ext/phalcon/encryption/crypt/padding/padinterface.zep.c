
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

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
 * Interface for Phalcon\Encryption\Crypt\Padding
 *
 * @psalm-suppress DeprecatedInterface
 * @deprecated Will be removed in a future major release.
 *             Use {@see \Phalcon\Contracts\Encryption\Crypt\Padding\Pad} instead.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_PadInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Encryption\\Crypt\\Padding, PadInterface, phalcon, encryption_crypt_padding_padinterface, NULL);

	zend_class_implements(phalcon_encryption_crypt_padding_padinterface_ce, 1, phalcon_contracts_encryption_crypt_padding_pad_ce);
	return SUCCESS;
}

