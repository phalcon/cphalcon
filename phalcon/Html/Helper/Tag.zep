
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
 * Generic open-tag escape hatch. Renders just `<name attr="...">` for any
 * tag name without a dedicated helper. For an open + content + close tag
 * use `Element` instead. For self-closing void tags (img, br, hr, etc.)
 * use `VoidTag`.
 */
class Tag extends AbstractHelper
{
    /**
     * @param string $name
     * @param array  $attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(string name, array attributes = []) -> string
    {
        return this->renderTag(name, attributes);
    }
}
