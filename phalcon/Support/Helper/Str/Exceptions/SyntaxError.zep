
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Helper\Str\Exceptions;

use RuntimeException;

class SyntaxError extends RuntimeException
{
    public function __construct(string text)
    {
        parent::__construct("Syntax error in string '" . text . "'");
    }
}
