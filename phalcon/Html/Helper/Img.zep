
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Class Img
 */
class Img extends AbstractHelper
{
    /**
     * Produce a <img> tag.
     *
     * @param string $src
     * @param array  $attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(string src, array attributes = []) -> string
    {
        return this->selfClose(
            "img",
            this->injectAttribute("src", src, attributes)
        );
    }
}
