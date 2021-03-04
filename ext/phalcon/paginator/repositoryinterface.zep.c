
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
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Paginator\RepositoryInterface
 *
 * Interface for the repository of current state
 * Phalcon\Paginator\AdapterInterface::paginate()
 */
ZEPHIR_INIT_CLASS(Phalcon_Paginator_RepositoryInterface) {

	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Paginator, RepositoryInterface, phalcon, paginator_repositoryinterface, phalcon_paginator_repositoryinterface_method_entry);

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_CURRENT_PAGE"), "current");

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_FIRST_PAGE"), "first");

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_ITEMS"), "items");

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_LAST_PAGE"), "last");

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_LIMIT"), "limit");

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_NEXT_PAGE"), "next");

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_PREVIOUS_PAGE"), "previous");

	zephir_declare_class_constant_string(phalcon_paginator_repositoryinterface_ce, SL("PROPERTY_TOTAL_ITEMS"), "total_items");

	return SUCCESS;

}

/**
 * Gets the aliases for properties repository
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getAliases);
/**
 * Gets number of the current page
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getCurrent);
/**
 * Gets number of the first page
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getFirst);
/**
 * Gets the items on the current page
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getItems);
/**
 * Gets number of the last page
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getLast);
/**
 * Gets current rows limit
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getLimit);
/**
 * Gets number of the next page
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getNext);
/**
 * Gets number of the previous page
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getPrevious);
/**
 * Gets the total number of items
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, getTotalItems);
/**
 * Sets the aliases for properties repository
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, setAliases);
/**
 * Sets values for properties of the repository
 */
ZEPHIR_DOC_METHOD(Phalcon_Paginator_RepositoryInterface, setProperties);
