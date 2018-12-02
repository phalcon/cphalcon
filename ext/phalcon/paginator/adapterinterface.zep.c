
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * Phalcon\Paginator\AdapterInterface
 *
 * Interface for Phalcon\Paginator adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Paginator, AdapterInterface, phalcon, paginator_adapterinterface, phalcon_paginator_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Set the current page number
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, setCurrentPage);

/**
 * Returns a slice of the resultset to show in the pagination
 *
 * @deprecated will be removed after 4.0
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, getPaginate);

/**
 * Set current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, setLimit);

/**
 * Get current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, getLimit);

