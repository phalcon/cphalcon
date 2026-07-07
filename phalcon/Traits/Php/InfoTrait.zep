
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Traits\Php;

/**
 * Information method wrappers
 */
trait InfoTrait
{
    /**
     * Find out whether an extension is loaded
     *
     * @param string $name
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.extension-loaded.php
     */
    protected function phpExtensionLoaded(string name) -> bool
    {
        return extension_loaded(name);
    }

    /**
     * Return true if the given function has been defined
     *
     * @param string $functionName
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.function-exists.php
     */
    protected function phpFunctionExists(string functionName) -> bool
    {
        return function_exists(functionName);
    }
}
