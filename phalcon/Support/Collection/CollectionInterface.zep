
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Collection;

/**
 * Phalcon\Support\Collection\CollectionInterface
 *
 * Interface for Phalcon\Support\Collection class
 */
interface CollectionInterface
{
    public function __get(string element) -> var;

    public function __isset(string element) -> bool;

    public function __set(string element, value) -> void;

    public function __unset(string element) -> void;

    public function clear() -> void;

    public function get(string element, var defaultValue = null, string! cast = null) -> var;

    public function getKeys(bool insensitive = true) -> array;

    public function getValues() -> array;

    public function has(string element) -> bool;

    public function init(array data = []) -> void;

    public function remove(string element) -> void;

    public function set(string element, var value) -> void;

    public function toArray() -> array;

    public function toJson(int options = 79) -> string;
}
