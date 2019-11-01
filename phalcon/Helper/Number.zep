
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Helper;

/**
 * Phalcon\Helper\number
 *
 * This class offers numeric functions for the framework
 */
class Number
{
    /**
     * Helper method to get an array element or a default
     */
    final public static function between(int value, int from, int to) -> bool
    {
        return value >= from && value <= to;
    }
}
