
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
use Phalcon\Traits\Php\MbCaseTrait;

/**
 * Sanitizes a value to uppercase the first character of each word
 */
class UpperWords implements Sanitizer
{
    use MbCaseTrait;

    /**
     * @param string $input The text to sanitize
     *
     * @return false|string|string[]
     */
    public function __invoke(string input)
    {
        return this->phpMbConvertCase(input, MB_CASE_TITLE);
    }
}
