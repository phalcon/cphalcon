
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

namespace Phalcon\Queue;

use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Queue\ConnectionFactory as ConnectionFactoryInterface;
use Phalcon\Contracts\Queue\QueueTypes;
use Phalcon\Factory\AbstractFactory;
use Phalcon\Queue\Adapter\Beanstalk\BeanstalkConnectionFactory;
use Phalcon\Queue\Adapter\Memory\MemoryConnectionFactory;
use Phalcon\Queue\Adapter\Redis\RedisConnectionFactory;
use Phalcon\Queue\Adapter\Stream\StreamConnectionFactory;
use Phalcon\Queue\Exceptions\Exception;

/**
 * Maps an adapter name to its ConnectionFactory. Mirrors
 * Phalcon\Storage\AdapterFactory.
 *
 * @phpstan-import-type queue_connection_options from QueueTypes
 */
class AdapterFactory extends AbstractFactory
{
    /**
     * AdapterFactory constructor.
     *
     * @phpstan-param array<string, class-string<ConnectionFactoryInterface>> $services
     */
    public function __construct(array services = [])
    {
        this->init(services);
    }

    /**
     * Creates a new ConnectionFactory for the named adapter.
     *
     * @phpstan-param queue_connection_options $options
     */
    public function newInstance(string name,  array options = []) -> <ConnectionFactoryInterface>
    {
        var definition;

        let definition = this->getService(name);

        return new {definition}(options);
    }

    /**
     * Returns the exception class for the factory
     *
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }

    /**
     * Returns the available adapters.
     *
     * @return array<string, string>
     */
    protected function getServices() -> array
    {
        return [
            "beanstalk" : BeanstalkConnectionFactory::class,
            "memory"    : MemoryConnectionFactory::class,
            "redis"     : RedisConnectionFactory::class,
            "stream"    : StreamConnectionFactory::class
        ];
    }
}
