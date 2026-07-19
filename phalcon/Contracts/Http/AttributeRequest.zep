
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Contracts\Http;

use Phalcon\Http\Request\Bag\AttributeBag;
use Phalcon\Http\RequestInterface;

/**
 * Extends the request contract with the native attribute bag.
 *
 * `getAttributes()` already exists on the concrete `Phalcon\Http\Request`; this
 * interface exposes it as a contract without touching `RequestInterface`
 * (adding a method there would break userland implementers). It lets consumers
 * type against the attribute-bearing request without depending on the concrete.
 */
interface AttributeRequest extends RequestInterface
{
    /**
     * Returns the request attribute bag.
     */
    public function getAttributes() -> <AttributeBag>;
}
