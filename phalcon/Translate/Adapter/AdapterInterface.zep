
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\Adapter\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
interface AdapterInterface
{
    /**
     * Check whether is defined a translation key in the internal array
     *
     * @param string $index
     *
     * @return bool
     */
    public function exists(string! index) -> bool;

    /**
     * Returns the translation related to the given key
     *
     * @param string $translateKey
     * @param array  $placeholders
     *
     * @return string
     */
    public function query(string! translateKey, array placeholders = []) -> string;

    /**
     * Returns the translation string of the given key
     *
     * @param string $translateKey
     * @param array  $placeholders
     *
     * @return string
     */
    public function t(string! translateKey, array placeholders = []) -> string;
}
