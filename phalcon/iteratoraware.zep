
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Sergii Svyrydenko <sergey.v.sviridenko@gmail.com>             |
 +------------------------------------------------------------------------+
 */

namespace Phalcon;

use \Traversable;
use Phalcon\Exception;

/**
 * Utility class for manipulation of iterators.
 *
 * @package Phalcon
 */
class IteratorAware
{
    /**
     * Convert an iterator to an array.
     *
     * Converts an iterator to an array. The $recursive flag, on by default,
     * hints whether or not you want to do so recursively.
     *
     * @param  array | Traversable  iterator The array or Traversable object to convert
     * @throws Exception if iterator is not an array or a Traversable object
     */
    public function iteratorToArray(iterator, bool recursive = true) -> array
    {
    	var arrayResult, key, value;

        if typeof iterator != "array" && !(iterator instanceof Traversable) {
            throw new Exception("IteratorAware::iteratorToArray() must be either an array or iterator");
        }

        if unlikely recursive === false {
            if typeof iterator == "array" {
                return iterator;
            }

            return iterator_to_array(iterator);
        }

        if method_exists(iterator, "toArray") {
            return iterator->toArray();
        }

        let arrayResult = [];

        if typeof iterator == "object" {
			let iterator = iterator_to_array(iterator);
		}

        for key, value in iterator {
            if is_scalar(value) {
                let arrayResult[key] = value;
                continue;
            }
            if value instanceof Traversable {
                let arrayResult[key] = this->iteratorToArray(value, recursive);
                continue;
            }
            if typeof value == "array" {
                let arrayResult[key] = this->iteratorToArray(value, recursive);
                continue;
            }

            let arrayResult[key] = value;
        }

        return arrayResult;
    }
}
