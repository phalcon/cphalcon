
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
 * Phalcon\Translate\InterpolatorInterface
 *
 * Interface for Phalcon\Translate interpolators
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Interpolator_InterpolatorInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Translate\\Interpolator, InterpolatorInterface, phalcon, translate_interpolator_interpolatorinterface, phalcon_translate_interpolator_interpolatorinterface_method_entry);

	return SUCCESS;
}

/**
 * Replaces placeholders by the values passed
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_Interpolator_InterpolatorInterface, replacePlaceholders);
