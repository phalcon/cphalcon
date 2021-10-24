
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

/**
 * Phalcon\Filter\Sanitize\SpecialFull
 *
 * Sanitizes a value special characters (htmlspecialchars() and ENT_QUOTES)
 */
class SpecialFull
{
    /**
     * @param mixed $input The text to sanitize
     *
     * @return mixed
     */
    public function __invoke(var input)
    {
        return filter_var(input, FILTER_SANITIZE_FULL_SPECIAL_CHARS);
    }
}
