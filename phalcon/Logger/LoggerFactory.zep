
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use Phalcon\Logger\Logger;

/**
 * PhalconNG\Logger\LoggerFactory
 *
 * Logger factory
 */
class LoggerFactory
{
    /**
     * Returns a Logger object
     *
     * @param string $name
     * @param array  $adapters
     *
     * @return Logger
     */
    public function newInstance(string! name, array! adapters = []) -> <Logger>
    {
        return new Logger(name, adapters);
    }
}
