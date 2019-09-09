
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

/**
 * Phalcon\Html\Helper\Close
 *
 * Creates a closing tag
 */
class Close extends AbstractHelper
{
    /**
     * @param string $tag The tag
     *
     * @return string
     */
    public function __invoke(string! tag) -> string
    {
        return "</" . tag . ">";
    }
}
