
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
use Exception as BaseException;
use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Logger\LoggerTypes;
use Phalcon\Factory\AbstractConfigFactory;
use Phalcon\Traits\Support\Helper\Arr\GetTrait;

/**
 * Factory creating logger objects
 *
 * @phpstan-import-type logger_adapter_config from LoggerTypes
 * @phpstan-import-type logger_adapters from LoggerTypes
 * @phpstan-import-type logger_factory_config from LoggerTypes
 */
class LoggerFactory extends AbstractConfigFactory
{
    use GetTrait;

    private <AdapterFactory> adapterFactory;

    /**
     * Constructor
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
     *         'adapter-name' => [
     *              'adapter' => 'stream',
     *              'name'    => 'file.log',
     *              'options' => [
     *                  'mode'     => 'ab',
     *                  'option'   => null,
     *                  'facility' => null
     *              ],
     *         ],
     *     ]
     * ]
     *
     * @phpstan-param ConfigInterface|logger_factory_config $config
     */
    public function load(var config) -> <Logger>
    {
        var adapter, adapterClass, adapterFileName, adapterName, adapterOptions,
            adapters, name, timezone, options;
        array data = [];

        let config   = this->checkConfig(config),
            config   = this->checkConfigElement(config, "name"),
            name     = config["name"],
            timezone = this->getArrVal(config, "timezone"),
            options  = this->getArrVal(config, "options", []),
            adapters = this->getArrVal(options, "adapters", []);



        for adapterName, adapter in adapters {
            let adapterClass    = this->getArrVal(adapter, "adapter"),
                adapterFileName = this->getArrVal(adapter, "name"),
                adapterOptions  = this->getArrVal(adapter, "options", []);

            let data[adapterName] = this->adapterFactory->newInstance(
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
     * @phpstan-param logger_adapters $adapters
     */
    public function newInstance(
        string name,
        array adapters = [],
        <DateTimeZone> timezone = null
    ) -> <Logger> {
        return new Logger(name, adapters, timezone);
    }

    /**
     * @return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return Exception::class;
    }
}
