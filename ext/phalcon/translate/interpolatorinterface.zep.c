
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Translate\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_InterpolatorInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Translate, InterpolatorInterface, phalcon, translate_interpolatorinterface, phalcon_translate_interpolatorinterface_method_entry);

	return SUCCESS;

}

/**
 * Replaces placeholders by the values passed
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_InterpolatorInterface, replacePlaceholders);

