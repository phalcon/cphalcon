
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * Phalcon\Utility
 *
 * This class contains protected methods used throughout the framework
 */
class Utility
{
    /**
     * Helper method to get an array element or a default
     */
    protected function arrayGetDefault(array parameters, string name, var defaultValue) -> var
    {
        var value;

        if likely fetch value, parameters[name] {
            return value;
        }

        return defaultValue;
    }
}
