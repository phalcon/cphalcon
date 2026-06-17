
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
 * The pad/unpad protocol operates on binary (8-bit) data. Implementations
 * must measure and slice the input with byte-true functions (`strlen`,
 * `substr`, or the `mb_*` family with the explicit `"8bit"` encoding); using
 * encoding-sensitive functions such as `mb_strlen()` on the padded plaintext
 * yields the wrong padding size whenever the bytes form valid multibyte
 * sequences.
 */
ZEPHIR_INIT_CLASS(Phalcon_Encryption_Crypt_Padding_PadInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Encryption\\Crypt\\Padding, PadInterface, phalcon, encryption_crypt_padding_padinterface, phalcon_encryption_crypt_padding_padinterface_method_entry);

	return SUCCESS;
}

/**
 * @param int $paddingSize
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_Padding_PadInterface, pad);
/**
 * @param string $input
 * @param int    $blockSize
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Encryption_Crypt_Padding_PadInterface, unpad);
