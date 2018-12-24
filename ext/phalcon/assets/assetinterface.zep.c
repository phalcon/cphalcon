
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
 * Phalcon\Assets\AssetInterface
 *
 * Interface for custom Phalcon\Assets reources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_AssetInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Assets, AssetInterface, phalcon, assets_assetinterface, phalcon_assets_assetinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the asset's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, setType);

/**
 * Gets the asset's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getType);

/**
 * Sets if the asset must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, setFilter);

/**
 * Gets if the asset must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getFilter);

/**
 * Sets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, setAttributes);

/**
 * Gets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getAttributes);

/**
 * Gets the asset's key.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_AssetInterface, getAssetKey);

