
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

int phalcon_db_checktype(zval *return_value, zval *placeholder) {

    if (Z_TYPE_P(placeholder) != IS_STRING) {

    }

    return 0;
}
