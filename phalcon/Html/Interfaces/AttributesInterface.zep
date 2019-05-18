/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Interfaces;

use Phalcon\Html\Attributes;

/**
* Phalcon\Html\Interfaces\AttributesInterface
*
* Interface Phalcon\Html\Interfaces\AttributesInterface
*/
interface AttributesInterface {
    /**
    * Get Attributes
    */
    public function getAttributes() -> <Attributes>;

    /**
    * Set Attributes
    */
    public function setAttributes(<Attributes> attributes) -> <AttributesInterface>;
}
