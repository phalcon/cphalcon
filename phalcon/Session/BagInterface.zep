/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

use Phalcon\Contracts\Session\SessionTypes;

/**
 * Interface for Phalcon\Session\Bag
 *
 * @phpstan-import-type session_bag_data from SessionTypes
 */
interface BagInterface
{
    public function __get(string element) -> var;

    public function __isset(string element) -> bool;

    public function __set(string element, value) -> void;

    public function __unset(string element) -> void;

    public function clear() -> void;

    public function get(string element, var defaultValue = null,  string cast = null) -> var;

    public function has(string element) -> bool;

    /**
     * @phpstan-param session_bag_data $data
     */
    public function init(array data = []) -> void;

    public function remove(string element) -> void;

    public function set(string element, var value) -> void;
}
