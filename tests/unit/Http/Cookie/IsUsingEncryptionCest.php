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
 * Class IsUsingEncryptionCest
 */
class IsUsingEncryptionCest
{
    /**
     * Tests Phalcon\Http\Cookie :: isUsingEncryption()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function httpCookieIsUsingEncryption(UnitTester $I)
    {
        $I->wantToTest('Http\Cookie - isUsingEncryption()');
        $I->skipTest('Need implementation');
    }
}
