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

use Phalcon\Encryption\Crypt\Padding\Iso10126;
use UnitTester;

/**
 * Class Iso10126Cest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class Iso10126Cest
{
    /**
     * Tests Phalcon\Encryption\Crypt\Padding\Iso10126 :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-12
     */
    public function cryptPaddingIso10126(UnitTester $I)
    {
        $I->wantToTest('Crypt\Padding\Iso10126 - pad()/unpad()');

        $object = new Iso10126();

        $padding  = $object->pad(16);
        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $padding;
        $expected = 16;
        $actual   = $object->unpad($source, 16);
        $I->assertEquals($expected, $actual);
    }
}
