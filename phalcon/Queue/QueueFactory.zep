
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
use Phalcon\Contracts\Queue\Context as ContextInterface;
use Phalcon\Factory\AbstractConfigFactory;
use Phalcon\Queue\Exceptions\Exception;

/**
 * Builds a queue Context from the standard Phalcon config shape. Mirrors
 * Phalcon\Cache\CacheFactory.
 *
 * @phpstan-import-type queue_connection_options from QueueTypes
 */
class QueueFactory extends AbstractConfigFactory
{
    protected <AdapterFactory> adapterFactory;

    /**
     * A default AdapterFactory is created when none is supplied, so the
     * factory is usable straight from the DI container.
     */
    public function __construct(<AdapterFactory> factory = null)
    {
        if factory === null {
            let factory = new AdapterFactory();
        }

        let this->adapterFactory = factory;
    }

    /**
     * Builds a Context from a config array/object.
     *
     * @param array<string, mixed>|ConfigInterface $config = [
     *     'adapter' => 'memory',
     *     'options' => [],
     * ]
     */
    public function load(var config) -> <ContextInterface>
    {
        var name, options;

        let config = this->checkConfig(config),
            config = this->checkConfigElement(config, "adapter"),
            name   = config["adapter"];

        if !fetch options, config["options"] {
            let options = [];
        }

        return this->newInstance(name, options);
    }

    /**
     * Builds a Context for the named adapter.
     *
     * @phpstan-param queue_connection_options $options
     */
    public function newInstance( string name,  array options = []) -> <ContextInterface>
    {
        var connectionFactory;

        let connectionFactory = this->adapterFactory->newInstance(name, options);

        return connectionFactory->createContext();
    }

    /**
     * Returns the exception class for the factory
     *
     * @return class-string<\Throwable>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }
}
