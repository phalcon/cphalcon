
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Assets\FilterInterface
 *
 * Interface for custom Phalcon\Assets filters
 */
ZEPHIR_INIT_CLASS(Phalcon_Assets_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Assets, FilterInterface, phalcon, assets_filterinterface, phalcon_assets_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Filters the content returning a string with the filtered content
 */
ZEPHIR_DOC_METHOD(Phalcon_Assets_FilterInterface, filter);

