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

namespace Phalcon\Test\Unit\Crypt;

use Phalcon\Crypt;
use UnitTester;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Crypt :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cryptConstruct(UnitTester $I)
    {
        $I->wantToTest('Crypt - __construct()');
        $actual = new Crypt();
        $class  = Crypt::class;
        $I->assertInstanceOf($class, $actual);

        $actual = new Crypt("aes-256-cfb", true);
        $class  = Crypt::class;
        $I->assertInstanceOf($class, $actual);
    }

    /**
     * Tests the Crypt constants
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2015-12-20
     */
    public function testCryptConstants(UnitTester $I)
    {
        $I->wantToTest('Crypt - Constants');

        $I->assertEquals(0, Crypt::PADDING_DEFAULT);
        $I->assertEquals(1, Crypt::PADDING_ANSI_X_923);
        $I->assertEquals(2, Crypt::PADDING_PKCS7);
        $I->assertEquals(3, Crypt::PADDING_ISO_10126);
        $I->assertEquals(4, Crypt::PADDING_ISO_IEC_7816_4);
        $I->assertEquals(5, Crypt::PADDING_ZERO);
        $I->assertEquals(6, Crypt::PADDING_SPACE);
    }
}
