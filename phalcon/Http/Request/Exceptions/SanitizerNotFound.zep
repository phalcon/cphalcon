
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request\Exceptions;

use Phalcon\Http\Request\Exception;

class SanitizerNotFound extends Exception
{
    public function __construct(string sanitizer)
    {
        parent::__construct(
            "Sanitizer '" . sanitizer . "' does not exist in the filter locator"
        );
    }
}
