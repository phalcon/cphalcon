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

class NoModelForAlias extends Exception
{
    public function __construct(string model, string phql)
    {
        parent::__construct(
            "There is no model related to model or alias '"
            . model
            . "', when executing: "
            . phql
        );
    }
}
