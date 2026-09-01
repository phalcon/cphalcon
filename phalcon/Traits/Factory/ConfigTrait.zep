
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Factory;

use Phalcon\Config\ConfigInterface;

trait ConfigTrait
{
    /**
     * @param array<string, mixed>|ConfigInterface $config
     *
     * @return array<string, mixed>
     */
    protected function checkConfig(var config) -> array
    {
        var exceptionClass;

        if (typeof config === "object" && config instanceof ConfigInterface) {
            return config->toArray();
        }

        if (typeof config !== "array") {
            let exceptionClass = this->{"getExceptionClass"}();
            throw new {exceptionClass}(
                "Config must be array or Phalcon\\Config\\Config object"
            );
        }

        return config;
    }

    /**
     * Checks if the config has a specific element
     *
     * @param array  $config
     * @param string $element
     *
     * @return array
     */
    protected function checkConfigElement(array config, string element) -> array
    {
        var exceptionClass;

        if (!isset(config[element])) {
            let exceptionClass = this->{"getExceptionClass"}();
            throw new {exceptionClass}(
                "You must provide the '" . element . "' option in the factory config parameter."
            );
        }

        return config;
    }
}
