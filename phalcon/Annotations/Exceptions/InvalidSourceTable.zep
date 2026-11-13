
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations\Exceptions;

use Phalcon\Annotations\Exception;

class InvalidSourceTable extends Exception
{
    public function __construct()
    {
        parent::__construct("Source table name must be a non-empty string");
    }
}
