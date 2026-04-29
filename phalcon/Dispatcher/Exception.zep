
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Dispatcher;

/**
 * Exceptions thrown in Phalcon\Dispatcher/* will use this class
 */
class Exception extends \Exception
{
    /**
     * @var int
     */
    const EXCEPTION_ACTION_NOT_FOUND  = 5;
    /**
     * @var int
     */
    const EXCEPTION_CYCLIC_ROUTING    = 1;
    /**
     * @var int
     */
    const EXCEPTION_HANDLER_NOT_FOUND = 2;
    /**
     * @var int
     */
    const EXCEPTION_INVALID_HANDLER   = 3;
    /**
     * @var int
     */
    const EXCEPTION_INVALID_PARAMS    = 4;
    /**
     * @var int
     */
    const EXCEPTION_NO_DI             = 0;
}
