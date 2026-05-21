
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

class RelationRequiresObjectOrArray extends Exception
{
    public function __construct(string className, string relationName)
    {
        parent::__construct(
            "Only objects/arrays can be stored as part of has-many/has-one/has-one-through/has-many-to-many relations on model " . className . " on Relation " . relationName
        );
    }
}
