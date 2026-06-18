
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
 * Interface for the repository of current state
 * Phalcon\Paginator\AdapterInterface::paginate()
 *
 * Two adapter dialects fill this repository:
 *
 * - Offset adapters (Model, NativeArray, QueryBuilder) populate every
 *   property as a sequential page number / item count.
 * - Cursor adapters (QueryBuilderCursor) reuse the same properties with a
 *   different meaning: `getCurrent()`/`getNext()` carry keyset cursor values
 *   rather than page numbers, and `getTotalItems()`, `getLast()` and
 *   `getPrevious()` are not computed (they return 0).
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Paginator_Repository)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Paginator, Repository, phalcon, contracts_paginator_repository, phalcon_contracts_paginator_repository_method_entry);

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_CURRENT_PAGE"), "current");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_FIRST_PAGE"), "first");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_ITEMS"), "items");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_LAST_PAGE"), "last");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_LIMIT"), "limit");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_NEXT_PAGE"), "next");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_PREVIOUS_PAGE"), "previous");

	/**
	 * @var string
	 */
	zephir_declare_class_constant_string(phalcon_contracts_paginator_repository_ce, SL("PROPERTY_TOTAL_ITEMS"), "total_items");

	return SUCCESS;
}

/**
 * Gets the aliases for properties repository
 *
 * @return array
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getAliases);
/**
 * Gets number of the current page
 *
 * Cursor adapters store the cursor value used for the current page here
 * (0 on the first page), not a sequential page number.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getCurrent);
/**
 * Gets number of the first page
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getFirst);
/**
 * Gets the items on the current page
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getItems);
/**
 * Gets number of the last page
 *
 * Cursor adapters do not compute this and return 0.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getLast);
/**
 * Gets current rows limit
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getLimit);
/**
 * Gets number of the next page
 *
 * Cursor adapters store the next cursor value here rather than a page
 * number; 0 means there is no next page.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getNext);
/**
 * Gets number of the previous page
 *
 * Cursor adapters do not compute this and return 0.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getPrevious);
/**
 * Gets the total number of items
 *
 * Cursor adapters do not compute this and return 0.
 *
 * @return int
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, getTotalItems);
/**
 * Sets the aliases for properties repository
 *
 * @param array $aliases
 *
 * @return Repository
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, setAliases);
/**
 * Sets values for properties of the repository
 *
 * @param array $properties
 *
 * @return Repository
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Paginator_Repository, setProperties);
