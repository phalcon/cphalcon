
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Helper;

use stdClass;

/**
 * This class offers quick array functions throughout the framework
 */
class Arr
{
    /**
     * Chunks an array into smaller arrays of a specified size.
     *
     * @param array $collection
     * @param int   $size
     * @param bool  $preserveKeys
     *
     * @return array
     */
    final public static function chunk(
        array! collection,
        int size,
        bool preserveKeys = false
    ) -> array {
        return array_chunk(collection, size, preserveKeys);
    }

    /**
     * Helper method to filter the collection
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return array
     */
    final public static function filter(array collection, var method = null) -> array
    {
        if null === method || !is_callable(method)  {
            return collection;
        }

        return array_filter(collection, method);
    }

    /**
     * Returns the first element of the collection. If a callable is passed, the
     * element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return mixed
     */
    final public static function first(array! collection, var method = null) -> var
    {
        var filtered;

        let filtered = self::filter(collection, method);

        return reset(filtered);
    }

    /**
     * Returns the key of the first element of the collection. If a callable
     * is passed, the element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return mixed
     */
    final public static function firstKey(array! collection, var method = null) -> var
    {
        var filtered;

        let filtered = self::filter(collection, method);

        reset(filtered);

        return key(filtered);
    }

    /**
     * Flattens an array up to the one level depth, unless `$deep` is set to `true`
     *
     * @param array $collection
     * @param bool  $deep
     *
     * @return array
     */
    final public static function flatten(array! collection, bool deep = false) -> array
    {
        var data, item;

        let data = [];

        for item in collection {
            if typeof item !== "array" {
                let data[] = item;
            } else {
                if deep {
                    let data = array_merge(
                        data,
                        self::flatten(item, true)
                    );
                } else {
                    let data = array_merge(
                        data,
                        array_values(item)
                    );
                }
            }
        }

        return data;
    }

    /**
     * Helper method to get an array element or a default
     */
    final public static function get(
        array! collection,
        var index,
        var defaultValue = null,
        string! cast = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        if unlikely cast {
            settype(value, cast);
        }

        return value;
    }

    /**
     * Groups the elements of an array based on the passed callable
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return array
     */
    final public static function group(array! collection, var method) -> array
    {
        var element, key;
        array filtered;

        let filtered = [];

        for element in collection {
            if (typeof method !== "string" && is_callable(method)) || function_exists(method) {
                let key             = call_user_func(method, element),
                    filtered[key][] = element;
            } elseif typeof element === "object" {
                let key             = element->{method},
                    filtered[key][] = element;
            } elseif isset element[method] {
                let key             = element[method],
                    filtered[key][] = element;
            }
        }

        return filtered;
    }

    /**
     * Helper method to get an array element or a default
     *
     * @param array $collection
     * @param mixed $index
     *
     * return bool
     */
    final public static function has(array! collection, var index) -> bool
    {
        return isset collection[index];
    }

    /**
     * Checks a flat list for duplicate values. Returns true if duplicate
     * values exist and false if values are all unique.
     *
     * @param array $collection
     *
     * @return bool
     */
    final public static function isUnique(array! collection) -> bool
    {
        return count(collection) === count(array_unique(collection));
    }

    /**
     * Returns the last element of the collection. If a callable is passed, the
     * element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * return mixed
     */
    final public static function last(array! collection, var method = null) -> var
    {
        var filtered;

        let filtered = self::filter(collection, method);

        return end(filtered);
    }

    /**
     * Returns the key of the last element of the collection. If a callable is
     * passed, the element returned is the first that validates true
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return mixed
     */
    final public static function lastKey(array! collection, var method = null) -> var
    {
        var filtered;

        let filtered = self::filter(collection, method);

        end(filtered);

        return key(filtered);
    }

    /**
     * Sorts a collection of arrays or objects by key
     *
     * @param array  $collection
     * @param mixed  $attribute
     * @param string $order
     *
     * @return array
     */
    final public static function order(
        array! collection,
        var attribute,
        string order = "asc"
    ) -> array {
        var item, key;
        array sorted;

        let sorted = [];

        for item in collection {
            if typeof item === "object" {
                let key = item->{attribute};
            } else {
                let key = item[attribute];
            }

            let sorted[key] = item;
        }

        if order === "asc" {
            ksort(sorted);
        } else {
            krsort(sorted);
        }

        return array_values(sorted);
    }

    /**
     * Retrieves all of the values for a given key:
     *
     * @param array  $collection
     * @param string $element
     *
     * @return array
     */
    final public static function pluck(array! collection, string element) -> array
    {
        var item;
        array filtered;

        let filtered = [];

        for item in collection {
            if typeof item === "object" && isset item->{element} {
                let filtered[] = item->{element};
            } elseif typeof item === "array" && isset item[element] {
                let filtered[] = item[element];
            }
        }

        return filtered;
    }

    /**
     * Helper method to set an array element
     *
     * @param array $collection
     * @param mixed $value
     * @param mixed $index
     *
     * @return array
     */
    final public static function set(
        array! collection,
        var value,
        var index = null
    ) -> array {
        if null === index {
            let collection[] = value;
        } else {
            let collection[index] = value;
        }

        return collection;
    }

    /**
     * Returns a new array with n elements removed from the right.
     *
     * @param array $collection
     * @param int   $elements
     *
     * @return array
     */
    final public static function sliceLeft(array! collection, int elements = 1) -> array
    {
        return array_slice(collection, 0, elements);
    }

    /**
     * Returns a new array with the X elements from the right
     *
     * @param array $collection
     * @param int   $elements
     *
     * @return array
     */
    final public static function sliceRight(array! collection, int elements = 1) -> array
    {
        return array_slice(collection, elements);
    }

    /**
     * Returns a new array with keys of the passed array as one element and
     * values as another
     *
     * @param array $collection
     *
     * @return array
     */
    final public static function split(array! collection) -> array
    {
        return [
            array_keys(collection),
            array_values(collection)
        ];
    }

    /**
     * Returns the passed array as an object
     */
    final public static function toObject(array! collection)
    {
        return (object) collection;
    }

    /**
     * Returns true if the provided function returns true for all elements of
     * the collection, false otherwise.
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return bool
     */
    final public static function validateAll(array! collection, var method = null) -> bool
    {
        return count(self::filter(collection, method)) === count(collection);
    }

    /**
     * Returns true if the provided function returns true for at least one
     * element fo the collection, false otherwise.
     *
     * @param array    $collection
     * @param callable $method
     *
     * @return bool
     */
    final public static function validateAny(array! collection, var method = null) -> bool
    {
        return count(self::filter(collection, method)) > 0;
    }

    /**
     * White list filter by key: obtain elements of an array filtering
     * by the keys obtained from the elements of a whitelist
     *
     * @param array $collection
     * @param array $whiteList
     *
     * @return array
     */
    final public static function whiteList(array! collection, array! whiteList) -> array
    {
        /**
         * Clean whitelist, just strings and integers
         */
        let whiteList = array_filter(
            whiteList,
            function (element)
            {
                return is_int(element) || is_string(element);
            }
        );

        return array_intersect_key(
            collection,
            array_flip(whiteList)
        );
    }
}
