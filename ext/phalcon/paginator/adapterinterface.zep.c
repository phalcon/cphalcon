
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
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, paginate);

/**
 * Set current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, setLimit);

/**
 * Get current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_AdapterInterface, getLimit);

