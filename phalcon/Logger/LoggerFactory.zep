
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use DateTimeZone;
use Phalcon\Config\ConfigInterface;
use Phalcon\Factory\AbstractConfigFactory;

/**
 * Factory creating logger objects
 */
class LoggerFactory extends AbstractConfigFactory
{
    /**
     * @var AdapterFactory
     */
    private adapterFactory;

    /**
     * @param AdapterFactory $factory
     */
    public function __construct(<AdapterFactory> factory)
    {
        let this->adapterFactory = factory;
    }

    /**
     * Factory to create an instance from a Config object
     *
     * @param array|ConfigInterface $config = [
     *     'name'     => 'messages',
     *     'adapters' => [
     *         'adapter' => 'stream',
     *         'name'    => 'file.log',
     *         'options' => [
     *             'mode'     => 'ab',
     *             'option'   => null,
     *             'facility' => null
     *         ]
     *     ]
     * ]
     */
    public function load(var config) -> <Logger>
    {
        var adapter, adapterClass, adapterFileName, adapterOptions,
            adapters, name, timezone, options;
        array data;

        let data     = [],
            config   = this->checkConfig(config),
            config   = this->checkConfigElement(config, "name"),
            name     = config["name"],
            timezone = this->getArrVal(config, "timezone"),
            options  = this->getArrVal(config, "options", []),
            adapters = this->getArrVal(options, "adapters", []);



        for adapter in adapters {
            let adapterClass    = this->getArrVal(adapter, "adapter"),
                adapterFileName = this->getArrVal(adapter, "name"),
                adapterOptions  = this->getArrVal(adapter, "options", []);

            let data[] = this->adapterFactory->newInstance(
                adapterClass,
                adapterFileName,
                adapterOptions
            );
        }

        return this->newInstance(name, data, timezone);
    }

    /**
     * Returns a Logger object
     *
     * @param string            $name
     * @param array             $adapters
     * @param DateTimeZone|null $timezone
     *
     * @return Logger
     */
    public function newInstance(
        string name,
        array adapters = [],
        <DateTimeZone> timezone = null
    ) -> <Logger> {
        return new Logger(name, adapters, timezone);
    }

    /**
     * @todo Remove this when we get traits
     */
    protected function getArrVal(
        array! collection,
        var index,
        var defaultValue = null
    ) -> var {
        var value;

        if unlikely !fetch value, collection[index] {
            return defaultValue;
        }

        return value;
    }

    /**
     * @return string
     */
    protected function getExceptionClass() -> string
    {
        return "Phalcon\\Logger\\Exception";
    }
}
