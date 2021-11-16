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

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Codeception\Stub;
use Phalcon\Encryption\Crypt;
use Phalcon\Encryption\Crypt\Exception\Exception;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Encryption\Crypt :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
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
     * @since  2021-10-18
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

    /**
     * Tests Phalcon\Encryption\Crypt :: __construct() - no openssl exception
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptConstructNoOpensslException(UnitTester $I)
    {
        $I->wantToTest('Crypt - __construct() - no openssl exception');

        $I->expectThrowable(
            new Exception('This class requires the openssl extension for PHP'),
            function () {
                $crypt = Stub::construct(
                    Crypt::class,
                    [],
                    [
                        'phpFunctionExists' => false,
                    ]
                );
            }
        );
    }
}
