
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
 * Phalcon\Filter\Sanitize\FloatVal
 *
 * Sanitizes a value to float
 */
class FloatVal
{
    /**
     * @param mixed $input The text to sanitize
     *
     * @return float
     */
    public function __invoke(var input)
    {
        return (double) filter_var(
            input,
            FILTER_SANITIZE_NUMBER_FLOAT,
            ["flags": FILTER_FLAG_ALLOW_FRACTION]
        );
    }
}
