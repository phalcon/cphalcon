
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
 * Phalcon\Translate\Adapter\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_Adapter_AdapterInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Translate\\Adapter, AdapterInterface, phalcon, translate_adapter_adapterinterface, phalcon_translate_adapter_adapterinterface_method_entry);

	return SUCCESS;
}

/**
 * Check whether is defined a translation key in the internal array
 *
 * @param string $index
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_Adapter_AdapterInterface, exists);
/**
 * Returns the translation related to the given key
 *
 * @param string $translateKey
 * @param array  $placeholders
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_Adapter_AdapterInterface, query);
/**
 * Returns the translation string of the given key
 *
 * @param string $translateKey
 * @param array  $placeholders
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Translate_Adapter_AdapterInterface, t);
