
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Assets\ResourceInterface
 *
 * Interface for custom Phalcon\Assets reources
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_ResourceInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Assets, ResourceInterface, phalcon, assets_resourceinterface, phalcon_assets_resourceinterface_method_entry);

	return SUCCESS;

}

/**
 * Sets the resource's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_ResourceInterface, setType);

/**
 * Gets the resource's type.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_ResourceInterface, getType);

/**
 * Sets if the resource must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_ResourceInterface, setFilter);

/**
 * Gets if the resource must be filtered or not.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_ResourceInterface, getFilter);

/**
 * Sets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_ResourceInterface, setAttributes);

/**
 * Gets extra HTML attributes.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_ResourceInterface, getAttributes);

/**
 * Gets the resource's key.
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_ResourceInterface, getResourceKey);

