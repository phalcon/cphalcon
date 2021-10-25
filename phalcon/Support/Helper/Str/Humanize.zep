
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str;

/**
 * Class Humanize
 *
 * @package Phalcon\Support\Str
 */
class Humanize
{
    /**
     * Makes an underscored or dashed phrase human-readable
     *
     * @param string $text
     *
     * @return string
     */
    public function __invoke(string text) -> string
    {
        var result;

        let result = preg_replace("#[_-]+#", " ", trim(text));

        return (null === result) ? "" : result;
    }
}
