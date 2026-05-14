
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Support\Collection\Exceptions;

use Phalcon\Support\Collection\Exception;

class ReadOnlyViolation extends Exception
{
    public function __construct()
    {
        parent::__construct("The object is read only");
    }
}
