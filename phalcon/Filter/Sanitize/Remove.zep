
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Sanitize;

use Phalcon\Contracts\Filter\Sanitizer;

/**
 * Phalcon\Filter\Sanitize\Remove
 *
 * Sanitizes a value removing parts of a string
 */
class Remove implements Sanitizer
{
    /**
     * @param mixed $input
     * @param mixed $replace
     *
     * @return string|string[]
     */
    public function __invoke(var input, var replace)
    {
        return str_replace(replace, "", input);
    }
}
