
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Translate\Adapter;

/**
 * Phalcon\Translate\AdapterInterface
 *
 * Interface for Phalcon\Translate adapters
 */
interface AdapterInterface
{
    /**
     * Check whether is defined a translation key in the internal array
     */
    public function exists(string! index) -> bool;

    /**
     * Returns the translation related to the given key
     *
     * @param array placeholders
     */
    public function query(string! index, placeholders = null) -> string;

    /**
     * Returns the translation string of the given key
     *
     * @param array placeholders
     */
    public function t(string! translateKey, placeholders = null) -> string;
}
