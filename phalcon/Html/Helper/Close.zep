
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
 * Class Close
 */
class Close extends AbstractHelper
{
    /**
     * Produce a `</...>` tag.
     *
     * @param string $tag
     * @param bool   $raw
     *
     * @return string
     */
    public function __invoke(string tag, bool raw = false) -> string
    {
        return $this->close(tag, raw);
    }
}
