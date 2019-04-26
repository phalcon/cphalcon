/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Interfaces;

/**
* Phalcon\Html\Interfaces\AttributesInterface
*
* Interface Phalcon\Html\Interfaces\AttributesInterface
*/
interface AttributesInterface {

    public function getAttribute(string name);

    public function getAttributes() -> array;

    public function hasAttribute(string name) -> boolean;

    public function renderAttributes() -> string;

    public function removeAttribute(string name) -> boolean;

    public function resetAttributes() -> <AttributesInterface>;

    public function setAttribute(string name, string value) -> <AttributesInterface>;

    public function setAttributes(array attributes) -> <AttributesInterface>;
}
