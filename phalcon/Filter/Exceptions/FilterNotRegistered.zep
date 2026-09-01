
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter\Exceptions;

use Phalcon\Filter\Exception;

class FilterNotRegistered extends Exception
{
    public function __construct(string name)
    {
        parent::__construct("Filter " . name . " is not registered");
    }
}
