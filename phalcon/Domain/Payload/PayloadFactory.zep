
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by phalcon-api and AuraPHP
 * @link    https://github.com/phalcon/phalcon-api
 * @license https://github.com/phalcon/phalcon-api/blob/master/LICENSE
 * @link    https://github.com/auraphp/Aura.Payload
 * @license https://github.com/auraphp/Aura.Payload/blob/3.x/LICENSE
 *
 * @see Original inspiration for the https://github.com/phalcon/phalcon-api
 */

namespace Phalcon\Http\Payload;

use Phalcon\Http\Payload\Payload;
use Phalcon\Http\Payload\PayloadInterface;

/**
 * Phalcon\Http\Payload\PayloadFactory
 *
 * Factory to create payload objects
 */
class PayloadFactory
{
    /**
     * Instantiate a new object
     */
    public function newInstance() -> <PayloadInterface>
    {
        return new Payload();
    }
}
