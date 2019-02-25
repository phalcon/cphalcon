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

namespace Phalcon\Test\Unit\Security;

use UnitTester;
use Phalcon\Security;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Security :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function securityConstruct(UnitTester $I)
    {
        $I->wantToTest('Security - __construct()');
        $security = new Security();

        $class = Security::class;
        $I->assertInstanceOf($class, $security);
    }

    /**
     * Tests the Security constants
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2015-12-19
     */
    public function testSecurityConstants(UnitTester $I)
    {
        $I->assertEquals(0, Security::CRYPT_DEFAULT);
        $I->assertEquals(1, Security::CRYPT_STD_DES);
        $I->assertEquals(2, Security::CRYPT_EXT_DES);
        $I->assertEquals(3, Security::CRYPT_MD5);
        $I->assertEquals(4, Security::CRYPT_BLOWFISH);
        $I->assertEquals(5, Security::CRYPT_BLOWFISH_A);
        $I->assertEquals(6, Security::CRYPT_BLOWFISH_X);
        $I->assertEquals(7, Security::CRYPT_BLOWFISH_Y);
        $I->assertEquals(8, Security::CRYPT_SHA256);
        $I->assertEquals(9, Security::CRYPT_SHA512);
    }
}
