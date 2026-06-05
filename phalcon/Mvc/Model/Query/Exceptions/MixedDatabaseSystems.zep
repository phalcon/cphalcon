
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query\Exceptions;

use Phalcon\Mvc\Model\Exception;

class MixedDatabaseSystems extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Cannot use models of different database systems in the same query"
        );
    }
}
