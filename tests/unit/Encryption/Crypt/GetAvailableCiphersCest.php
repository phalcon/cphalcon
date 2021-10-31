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

use Phalcon\Encryption\Crypt;
use UnitTester;

use function array_values;
use function openssl_get_cipher_methods;
use function sort;

/**
 * Class GetAvailableCiphersCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class GetAvailableCiphersCest
{
    /**
     * Tests Phalcon\Encryption\Crypt :: getAvailableCiphers()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function cryptGetAvailableCiphers(UnitTester $I)
    {
        $I->wantToTest('Crypt - getAvailableCiphers()');

        $crypt = new Crypt();

        $expected = openssl_get_cipher_methods(true);
        $expected = sort($expected);
        $actual   = $crypt->getAvailableCiphers();
        $values   = array_values($actual);
        $actual   = sort($values);
        $I->assertEquals($expected, $actual);
    }
}
