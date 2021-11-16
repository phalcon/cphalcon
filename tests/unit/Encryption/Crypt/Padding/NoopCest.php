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

namespace Phalcon\Tests\Unit\Crypt\Padding;

use Phalcon\Encryption\Crypt\Padding\Noop;
use UnitTester;

/**
 * Class NoopCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class NoopCest
{
    /**
     * Tests Phalcon\Encryption\Crypt\Padding\Noop :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-12
     */
    public function cryptPaddingNoop(UnitTester $I)
    {
        $I->wantToTest('Crypt\Padding\Noop - pad()/unpad()');

        $object = new Noop();

        $expected = "";
        $actual   = $object->pad(16);
        $I->assertEquals($expected, $actual);

        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $actual;
        $expected = 0;
        $actual   = $object->unpad($source, 16);
        $I->assertEquals($expected, $actual);
    }
}
