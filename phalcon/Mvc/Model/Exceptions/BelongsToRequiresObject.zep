
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model\Exceptions;

use Phalcon\Mvc\Model\Exception;

class BelongsToRequiresObject extends Exception
{
    public function __construct(string className, string relationName)
    {
        parent::__construct(
            "Only objects can be stored as part of belongs-to relations in '" . className . "' Relation " . relationName
        );
    }
}
