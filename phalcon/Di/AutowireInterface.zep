
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di;

interface AutowireInterface
{
    public function resolve(<DiInterface> container, string! className, array parameters = [], array autowireTypes = []) -> object;

    public function resolveMethod(<DiInterface> container, object obj, string method, array parameters = []) -> var;
}
