
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Class Button
 */
class Button extends AbstractHelper
{
    /**
     * Produce a `<button>` tag.
     *
     * @param string $text
     * @param array  $attributes
     * @param bool   $raw
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(
        string text,
        array attributes = [],
        bool raw = false
    ) -> string {
        return this->renderFullElement("button", text, attributes, raw);
    }
}
