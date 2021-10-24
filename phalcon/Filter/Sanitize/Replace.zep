
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
 * Phalcon\Filter\Sanitize\Replace
 *
 * Sanitizes a value replacing parts of a string
 */
class Replace
{
    /**
     * @param mixed $input
     * @param mixed $source
     * @param mixed $target
     *
     * @return string|string[]
     */
    public function __invoke(var input, var from, var to)
    {
        return str_replace(from, to, input);
    }
}
