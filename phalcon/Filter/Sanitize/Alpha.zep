
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
 * Phalcon\Filter\Sanitize\Alpha
 *
 * Sanitizes a value to an alpha value
 */
class Alpha
{
    /**
     * @param mixed $input The text to sanitize
     *
     * @return string|string[]|null
     */
    public function __invoke(var input)
    {
        return preg_replace("/[^A-Za-z]/", "", input);
    }
}
