
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Http\Request\Exceptions;

use UnexpectedValueException;

class InvalidHost extends UnexpectedValueException
{
    public function __construct(string host)
    {
        parent::__construct("Invalid host " . host);
    }
}
