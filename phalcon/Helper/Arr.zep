
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Helper;

use Phalcon\Helper\Exception;

/**
 * Phalcon\Helper\Arr
 *
 * This class offers quick array functions throught the framework
 */
class Arr
{
    /**
     * Chunks an array into smaller arrays of a specified size.
     *
     * @param array $collection
     * @param int   $size
     * @param bool  $preserveKeys
     */
    final public static function chunk(array! collection, int size, bool preserveKeys = false) -> array
    {
        return array_chunk(collection, size, preserveKeys);
    }

    /**
     * Returns the head of a list.
     *
     * @param array $items
     */
    final public static function first(array! collection)
    {
        return reset(collection);
    }

    /**
     * Flattens an array up to the one level depth, unless `$deep` is set to `true`
     *
     * @param array $collection
     * @param bool  $deep
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
                    let data = array_merge(data, self::flatten(item, true));
                } else {
                    let data = array_merge(data, array_values(item));
                }
            }
        }

        return data;
    }

    /**
     * Helper method to get an array element or a default
     */
    final public static function get(array! collection, var index, var defaultValue) -> var
    {
        var value;

        if likely fetch value, collection[index] {
            return value;
        }

        return defaultValue;
    }

    /**
     * Helper method to get an array element or a default
     */
    final public static function has(array! collection, var index) -> bool
    {
        return isset collection[index];
    }

    /**
     * Checks a flat list for duplicate values. Returns true if duplicate
     * values exist and false if values are all unique.
     *
     * @param array $items
     *
     * @return bool
     */
    final public static function isUnique(array! collection) -> bool
    {
        return count(collection) === count(array_unique(collection));
    }

    /**
     * Returns the last element in an array.
     *
     * @param array $items
     */
    final public static function last(array! collection)
    {
        return end(collection);
    }

    /**
     * Sorts a collection of arrays or objects by key
     *
     * @param array $items
     * @param [type] $attr
     * @param [type] $order
     *
     * @return array
     */
    final public static function order(array! collection, var attribute, string order = "asc") -> array
    {
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
     * Helper method to set an array element
     */
    final public static function set(array! collection, var value, var index = null) -> array
    {
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
     */
    final public static function sliceRight(array! collection, int elements = 1) -> array
    {
        return array_slice(collection, elements);
    }

    /**
     * Returns all elements in an array except for the first one.
     *
     * @param array $collection
     */
    final public static function tail(array! collection) -> array
    {
        return count(collection) > 1 ? array_slice(collection, 1) : collection;
    }
}
