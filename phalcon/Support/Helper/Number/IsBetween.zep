
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Number;

/**
 * Checks if a number is within a range
 */
class IsBetween
{
    /**
     * @param int $value
     * @param int $start
     * @param int $end
     *
     * @return bool
     */
    public function __invoke(int value, int start, int end) -> bool
    {
        return value >= start && value <= end;
    }
}
