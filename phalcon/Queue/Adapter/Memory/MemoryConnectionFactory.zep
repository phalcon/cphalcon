
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

namespace Phalcon\Queue\Adapter\Memory;

use Phalcon\Contracts\Queue\ConnectionFactory as ConnectionFactoryInterface;
use Phalcon\Contracts\Queue\Context as ContextInterface;

/**
 * Builds a MemoryContext. The Memory transport takes no options.
 */
class MemoryConnectionFactory implements ConnectionFactoryInterface
{
    /**
     * @var array
     */
    protected options = [];

    /**
     * MemoryConnectionFactory constructor.
     */
    public function __construct(array options = [])
    {
        let this->options = options;
    }

    /**
     * Creates a new in-process context.
     */
    public function createContext() -> <ContextInterface>
    {
        return new MemoryContext();
    }
}
