
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Exceptions;

use Phalcon\Db\Exception;

class NestedTransactionChangeBlocked extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Nested transaction with savepoints behavior cannot be changed while a transaction is open"
        );
    }
}
