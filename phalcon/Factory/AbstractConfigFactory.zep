
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Factory;

use Phalcon\Config\ConfigInterface;

abstract class AbstractConfigFactory
{
    /**
     * Checks the config if it is a valid object
     */
    protected function checkConfig(var config) -> array
    {
        if typeof config == "object" && config instanceof ConfigInterface {
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
     */
    protected function checkConfigElement(array config, string element) -> array
    {
        if unlikely !isset config[element] {
            throw this->getException(
                "You must provide '" . element . "' option in factory config parameter."
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
     */
    protected function getExceptionClass() -> string
    {
        return "Exception";
    }
}
