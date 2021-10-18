<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Crypt;

use Codeception\Stub;
use Phalcon\Crypt\Crypt;
use Phalcon\Crypt\Exception\Exception;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Crypt\Crypt :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function cryptConstruct(UnitTester $I)
    {
        $I->wantToTest('Crypt - __construct()');

        $crypt = new Crypt();
        $I->assertInstanceOf(Crypt::class, $crypt);

        $crypt = new Crypt('aes-256-cfb', true);
        $I->assertInstanceOf(Crypt::class, $crypt);
    }

    /**
     * Tests the Crypt constants
     *
     * @author Phalcon Team <team@phalcon.io>
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
