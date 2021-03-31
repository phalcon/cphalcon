
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
 * Phalcon\Paginator\AdapterInterface
 *
 * Interface for Phalcon\Paginator adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_Adapter_AdapterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Paginator\\Adapter, AdapterInterface, phalcon, paginator_adapter_adapterinterface, phalcon_paginator_adapter_adapterinterface_method_entry);

	return SUCCESS;

}

/**
 * Get current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_Adapter_AdapterInterface, getLimit);
/**
 * Returns a slice of the resultset to show in the pagination
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_Adapter_AdapterInterface, paginate);
/**
 * Set the current page number
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_Adapter_AdapterInterface, setCurrentPage);
/**
 * Set current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_Adapter_AdapterInterface, setLimit);
