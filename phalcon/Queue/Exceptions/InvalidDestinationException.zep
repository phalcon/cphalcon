
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */

namespace Phalcon\Queue\Exceptions;

/**
 * Thrown when a destination is not valid for the operation, for example a
 * Topic passed where a Queue is required. The action verb ("send to",
 * "consume from") tailors the message to the failing operation.
 */
class InvalidDestinationException extends Exception
{
    public function __construct(string action)
    {
        parent::__construct(
            "This transport can only " . action . " a Queue destination"
        );
    }
}
