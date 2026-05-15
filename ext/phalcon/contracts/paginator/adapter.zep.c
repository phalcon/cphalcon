
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
 * Interface for Phalcon\Paginator adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Paginator_Adapter)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Paginator, Adapter, phalcon, contracts_paginator_adapter, phalcon_contracts_paginator_adapter_method_entry);

	return SUCCESS;
}

/**
 * Get current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Adapter, getLimit);
/**
 * Returns a slice of the resultset to show in the pagination
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Adapter, paginate);
/**
 * Set the current page number
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Adapter, setCurrentPage);
/**
 * Set current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Adapter, setLimit);
