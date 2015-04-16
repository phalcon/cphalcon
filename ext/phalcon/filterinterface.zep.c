
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\FilterInterface
 *
 * Interface for Phalcon\Filter
 */
ZEPHIR_INIT_CLASS(Phalcon_FilterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon, FilterInterface, phalcon, filterinterface, phalcon_filterinterface_method_entry);

	return SUCCESS;

}

/**
 * Adds a user-defined filter
 */
ZEPHIR_DOC_METHOD(Phalcon_FilterInterface, add);

/**
 * Sanizites a value with a specified single or set of filters
 */
ZEPHIR_DOC_METHOD(Phalcon_FilterInterface, sanitize);

/**
 * Return the user-defined filters in the instance
 */
ZEPHIR_DOC_METHOD(Phalcon_FilterInterface, getFilters);

