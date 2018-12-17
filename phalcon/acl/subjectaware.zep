
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

/**
 * Phalcon\Acl\SubjectAware
 *
 * Interface for classes which could be used in allow method as RESOURCE
 */
interface SubjectAware
{
    /**
     * Returns resource name
    */
    public function getSubjectName() -> string;
}
