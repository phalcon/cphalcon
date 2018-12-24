<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Cookie;

use UnitTester;

/**
 * Class UseEncryptionCest
 */
class UseEncryptionCest
{
    /**
     * Tests Phalcon\Http\Cookie :: useEncryption()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpCookieUseEncryption(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - useEncryption()');
        $I->skipTest('Need implementation');
    }
}
