
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

class UnknownModelOrAlias extends Exception
{
    public function __construct(string model, string tag, string phql)
    {
        parent::__construct(
            "Unknown model or alias '"
            . model
            . "' ("
            . tag
            . "), when preparing: "
            . phql
        );
    }
}
