
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

namespace Phalcon\Queue\Adapter\Beanstalk;

use Phalcon\Contracts\Queue\ConnectionFactory as ConnectionFactoryInterface;
use Phalcon\Contracts\Queue\Context as ContextInterface;

/**
 * Builds a BeanstalkContext.
 *
 * Options:
 *   - host:         server host (default 127.0.0.1).
 *   - port:         server port (default 11300).
 *   - persistent:   use a persistent socket (default false).
 *   - ttr:          default time-to-run in seconds for every job (default 86400).
 *   - pollInterval: milliseconds between subscription poll passes (default 200).
 */
class BeanstalkConnectionFactory implements ConnectionFactoryInterface
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
        var options, host, port, persistent, ttr, pollInterval;

        let options      = this->options,
            host         = isset options["host"] ? options["host"] : "127.0.0.1",
            port         = isset options["port"] ? (int) options["port"] : 11300,
            persistent   = isset options["persistent"] ? (bool) options["persistent"] : false,
            ttr          = isset options["ttr"] ? (int) options["ttr"] : 86400,
            pollInterval = isset options["pollInterval"] ? (int) options["pollInterval"] : 200;

        return new BeanstalkContext(host, port, persistent, ttr, pollInterval);
    }
}
