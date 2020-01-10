
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

/**
 * Class Ul
 */
class Ul extends Ol
{
    /**
     * @return string
     */
    protected function getTag() -> string
    {
        return "ul";
    }
}
