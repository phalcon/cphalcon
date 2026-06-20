
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

namespace Phalcon\Queue\Adapter\Stream;

use Phalcon\Contracts\Queue\ConnectionFactory as ConnectionFactoryInterface;
use Phalcon\Contracts\Queue\Context as ContextInterface;

/**
 * Builds a StreamContext.
 *
 * Options:
 *   - storageDir:   directory holding the queue files (default: system temp).
 *   - pollInterval: milliseconds between consumer poll attempts (default 200).
 */
class StreamConnectionFactory implements ConnectionFactoryInterface
{
    /**
     * @var array
     */
    protected options = [];

    public function __construct(array options = [])
    {
        let this->options = options;
    }

    public function createContext() -> <ContextInterface>
    {
        var storageDir, pollInterval;

        let storageDir = sys_get_temp_dir();

        if isset this->options["storageDir"] {
            let storageDir = this->options["storageDir"];
        }

        let pollInterval = 200;

        if isset this->options["pollInterval"] {
            let pollInterval = (int) this->options["pollInterval"];
        }

        return new StreamContext(storageDir, pollInterval);
    }
}
