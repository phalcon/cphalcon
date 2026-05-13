
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
 * Canonical contract for Phalcon\Support\Collection.
 *
 * @phpstan-template T
 *
 * @extends ArrayAccess<int|string, mixed>
 * @extends IteratorAggregate<int|string, mixed>
 */
ZEPHIR_INIT_CLASS(Phalcon_Contracts_Support_Collection)
{
	ZEPHIR_REGISTER_INTERFACE(Phalcon\\Contracts\\Support, Collection, phalcon, contracts_support_collection, phalcon_contracts_support_collection_method_entry);

	zend_class_implements(phalcon_contracts_support_collection_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalcon_contracts_support_collection_ce, 1, zend_ce_aggregate);
	return SUCCESS;
}

/**
 * @param string $element
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, __get);
/**
 * @param string $element
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, __isset);
/**
 * @param string $element
 * @param mixed  $value
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, __set);
/**
 * @param string $element
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, __unset);
/**
 * Clears the internal collection.
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, clear);
/**
 * Returns the values from a single property/method extracted from every
 * item in the collection, keyed by the original collection key.
 *
 * @param string $propertyOrMethod
 *
 * @return array<int|string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, column);
/**
 * Invokes the callback for every item in the collection.
 *
 * @phpstan-param callable(T, array-key) -> mixed $callback
 *
 * @param callable $callback
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, each);
/**
 * Returns a new collection of items for which the callback returns true.
 *
 * @phpstan-param  callable(T, array-key) -> bool $callback
 * @phpstan-return static<T>
 *
 * @param callable $callback
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, filter);
/**
 * Returns the first value in the collection or null when empty.
 *
 * @phpstan-return T|null
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, first);
/**
 * Returns an element from the collection.
 *
 * @param string      $element
 * @param mixed       $defaultValue
 * @param string|null $cast
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, get);
/**
 * Returns the keys (insensitive or not) of the collection.
 *
 * @deprecated Use {@see self::keys()} instead. Will be removed in a future major release.
 *
 * @param bool $insensitive
 *
 * @return array<int|string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, getKeys);
/**
 * Returns the configured runtime type guard, or null when not set.
 *
 * @return string|null
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, getType);
/**
 * Returns the values of the internal array.
 *
 * @deprecated Use {@see self::values()} instead. Will be removed in a future major release.
 *
 * @return array<int|string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, getValues);
/**
 * Checks whether an element exists in the collection.
 *
 * @param string $element
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, has);
/**
 * Initializes the internal array.
 *
 * @param array<int|string, mixed> $data
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, init);
/**
 * Returns true when the collection has no entries.
 *
 * @return bool
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, isEmpty);
/**
 * Returns the keys (insensitive or not) of the collection.
 *
 * @param bool $insensitive
 *
 * @return array<int|string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, keys);
/**
 * Returns the last value in the collection or null when empty.
 *
 * @phpstan-return T|null
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, last);
/**
 * Returns a new collection with the callback applied to every value.
 *
 * @phpstan-param callable(T, array-key) -> mixed $callback
 *
 * @param callable $callback
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, map);
/**
 * Reduces the collection to a single value using the callback.
 *
 * @phpstan-param callable(mixed, T, array-key) -> mixed $callback
 *
 * @param callable $callback
 * @param mixed    $initial
 *
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, reduce);
/**
 * Removes the element from the collection.
 *
 * @param string $element
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, remove);
/**
 * Replaces the collection data with a new array, clearing first.
 *
 * @param array<int|string, mixed> $data
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, replace);
/**
 * Stores an element in the collection.
 *
 * @phpstan-param T $value
 *
 * @param string $element
 * @param mixed  $value
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, set);
/**
 * Returns a new collection sorted by value, preserving keys.
 *
 * @phpstan-return static<T>
 *
 * @param callable|null $callback
 * @param int           $order
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, sort);
/**
 * Returns the collection as an array.
 *
 * @phpstan-return array<array-key, T>
 *
 * @return array<int|string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, toArray);
/**
 * Returns the collection serialized as a JSON string.
 *
 * @param int $options
 *
 * @return string
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, toJson);
/**
 * Returns the values of the internal array.
 *
 * @return array<int|string, mixed>
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, values);
/**
 * Returns a new collection containing only the items whose
 * `propertyOrMethod` strictly equals `$value`.
 *
 * @phpstan-return static<T>
 *
 * @param string $propertyOrMethod
 * @param mixed  $value
 *
 * @return static
 */
ZEPHIR_DOC_METHOD(Phalcon_Contracts_Support_Collection, where);
