
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Factory;

use Exception as BaseException;
use Phalcon\Config\ConfigInterface;
use Phalcon\Contracts\Factory\FactoryTypes;

/**
 * @phpstan-import-type factory_config from FactoryTypes
 */
abstract class AbstractConfigFactory
{
    /**
     * Checks the config if it is a valid object
     *
     * @param array<string, mixed>|ConfigInterface $config
     *
     * @phpstan-param factory_config|ConfigInterface $config
     *
     * @phpstan-return factory_config
     * @throws BaseException
     */
    protected function checkConfig(var config) -> array
    {
        if typeof config === "object" && config instanceof ConfigInterface {
            /** @phpstan-var factory_config $config */
            let config = config->toArray();
        }

        if unlikely typeof config !== "array" {
            throw this->getException(
                "Config must be array or Phalcon\\Config\\Config object"
            );
        }

        return config;
    }

    /**
     * Checks if the config has "adapter"
     *
     * @param array<string, mixed> $config
     * @param string               $element
     *
     * @phpstan-param factory_config $config
     *
     * @return array<string, mixed>
     * @phpstan-return factory_config
     * @throws BaseException
     */
    protected function checkConfigElement(array config, string element) -> array
    {
        if unlikely !isset config[element] {
            throw this->getException(
                "You must provide the '" . element . "' option in the factory config parameter."
            );
        }

        return config;
    }

    /**
     * Returns the exception object for the child class
     */
    protected function getException(string message) -> <\Exception>
    {
        var exception;

        let exception = this->getExceptionClass();

        return new {exception}(message);
    }

    /**
     * @return string
     * @phpstan-return class-string<\Exception>
     */
    protected function getExceptionClass() -> string
    {
        return "Exception";
    }
}
