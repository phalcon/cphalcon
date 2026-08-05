
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

use Phalcon\Di\Traits\InjectionAwareTrait;
use stdClass;

/**
 * This abstract class offers common access to the DI in a class
 */
abstract class AbstractInjectionAware extends stdClass implements InjectionAwareInterface
{
    use InjectionAwareTrait;
}
