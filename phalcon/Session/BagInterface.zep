/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

/**
 * Phalcon\Session\BagInterface
 *
 * Interface for Phalcon\Session\Bag
 */
interface BagInterface
{
    public function __get(string element) -> var;

    public function __isset(string element) -> bool;

    public function __set(string element, value) -> void;

    public function __unset(string element) -> void;

    public function init(array data = []) -> void;

    public function get(string element, var defaultValue = null, string! cast = null) -> var;

    public function set(string element, var value) -> void;

    public function has(string element) -> bool;

    public function remove(string element) -> void;

    public function clear() -> void;
}
