
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
 * Phalcon\Mvc\Model\CriteriaInterface
 *
 * Interface for Phalcon\Mvc\Model\Criteria
 *
 * @phpstan-import-type mvc_model_bind_params from MvcTypes
 * @phpstan-import-type mvc_model_bind_types from MvcTypes
 * @phpstan-import-type mvc_model_cache_options from MvcTypes
 * @phpstan-import-type mvc_model_parameters from MvcTypes
 * @phpstan-import-type mvc_query_columns from MvcTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_CriteriaInterface)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Mvc\\Model, CriteriaInterface, phalcon, mvc_model_criteriainterface, phalcon_mvc_model_criteriainterface_method_entry);

	return SUCCESS;
}

/**
 * Appends a condition to the current conditions using an AND operator
 *
 * @param array bindParams
 * @param array bindTypes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, andWhere);
/**
 * Appends a BETWEEN condition to the current conditions
 *
 *```php
 * $criteria->betweenWhere("price", 100.25, 200.50);
 *```
 *
 * @param mixed minimum
 * @param mixed maximum
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, betweenWhere);
/**
 * Sets the bound parameters in the criteria
 * This method replaces all previously set bound parameters
 *
 * @phpstan-param mvc_model_bind_params $bindParams
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bind);
/**
 * Sets the bind types in the criteria
 * This method replaces all previously set bound parameters
 *
 * @phpstan-param mvc_model_bind_types $bindTypes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, bindTypes);
/**
 * Sets the cache options in the criteria
 * This method replaces all previously set cache options
 *
 * @phpstan-param mvc_model_cache_options $cache
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, cache);
/**
 * Adds the conditions parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, conditions);
/**
 * Sets SELECT DISTINCT / SELECT ALL flag
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, distinct);
/**
 * Executes a find using the parameters built with the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, execute);
/**
 * Sets the "for_update" parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, forUpdate);
/**
 * Returns the columns to be queried
 *
 * @phpstan-return mvc_query_columns|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getColumns);
/**
 * Returns the conditions parameter in the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getConditions);
/**
 * Returns the group clause in the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getGroupBy);
/**
 * Returns the having clause in the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getHaving);
/**
 * Returns the limit parameter in the criteria, which will be
 *
 * - An integer if 'limit' was set without an 'offset'
 * - An array with 'number' and 'offset' keys if an offset was set with the limit
 * - NULL if limit has not been set
 *
 * @phpstan-return array{number: int|string, offset?: int|string}|int|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getLimit);
/**
 * Returns an internal model name on which the criteria will be applied
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getModelName);
/**
 * Returns the order parameter in the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getOrderBy);
/**
 * Returns all the parameters defined in the criteria
 *
 * @phpstan-return mvc_model_parameters
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getParams);
/**
 * Returns the conditions parameter in the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, getWhere);
/**
 * Adds the group-by clause to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, groupBy);
/**
 * Adds the having clause to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, having);
/**
 * Appends an IN condition to the current conditions
 *
 *```php
 * $criteria->inWhere("id", [1, 2, 3]);
 *```
 *
 * @phpstan-param array<array-key, mixed> $values
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, inWhere);
/**
 * Adds an INNER join to the query
 *
 *```php
 * $criteria->innerJoin(
 *     Orders::class
 * );
 *
 * $criteria->innerJoin(
 *     Orders::class,
 *     "r.ord_id = OrdersProducts.oxp_ord_id"
 * );
 *
 * $criteria->innerJoin(
 *     Orders::class,
 *     "r.ord_id = OrdersProducts.oxp_ord_id",
 *     "r"
 * );
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, innerJoin);
/**
 * Adds a LEFT join to the query
 *
 *```php
 * $criteria->leftJoin(
 *     Orders::class,
 *     "r.ord_id = OrdersProducts.oxp_ord_id",
 *     "r"
 * );
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, leftJoin);
/**
 * Sets the limit parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, limit);
/**
 * Appends a NOT BETWEEN condition to the current conditions
 *
 *```php
 * $criteria->notBetweenWhere("price", 100.25, 200.50);
 *```
 *
 * @param mixed minimum
 * @param mixed maximum
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notBetweenWhere);
/**
 * Appends a NOT IN condition to the current conditions
 *
 *```php
 * $criteria->notInWhere("id", [1, 2, 3]);
 *```
 *
 * @phpstan-param array<array-key, mixed> $values
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, notInWhere);
/**
 * Appends a condition to the current conditions using an OR operator
 *
 * @param array bindParams
 * @param array bindTypes
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, orWhere);
/**
 * Adds the order-by parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, orderBy);
/**
 * Adds a RIGHT join to the query
 *
 *```php
 * $criteria->rightJoin(
 *     Orders::class,
 *     "r.ord_id = OrdersProducts.oxp_ord_id",
 *     "r"
 * );
 *```
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, rightJoin);
/**
 * Set a model on which the query will be executed
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, setModelName);
/**
 * Sets the "shared_lock" parameter to the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, sharedLock);
/**
 * Sets the conditions parameter in the criteria
 */
ZEPHIR_DOC_METHOD(Phalcon_Mvc_Model_CriteriaInterface, where);
