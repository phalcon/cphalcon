
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Micro;

use Phalcon\Mvc\Micro;

/**
 * Allows to implement Phalcon\Mvc\Micro middleware in classes
 */
interface MiddlewareInterface
{
    /**
     * Calls the middleware
     */
    public function call(<Micro> application);
}
