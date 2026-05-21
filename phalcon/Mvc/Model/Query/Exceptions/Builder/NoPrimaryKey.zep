
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Query\Exceptions\Builder;

use Phalcon\Mvc\Model\Exception;

class NoPrimaryKey extends Exception
{
    public function __construct()
    {
        parent::__construct(
            "Source related to this model does not have a primary key defined"
        );
    }
}
