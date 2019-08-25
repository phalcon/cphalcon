
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
 * Phalcon\Filter\Sanitize\Url
 *
 * Sanitizes a value url
 */
class Url
{
    /**
     * @var mixed input The text to sanitize
     */
    public function __invoke(var input)
    {
        return filter_var(input, FILTER_SANITIZE_URL);
    }
}
