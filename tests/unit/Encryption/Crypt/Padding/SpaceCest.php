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

namespace Phalcon\Tests\Unit\Encryption\Crypt\Padding;

use Phalcon\Encryption\Crypt\Padding\Space;
use UnitTester;

use function str_repeat;

/**
 * Class SpaceCest
 *
 * @package Phalcon\Tests\Unit\Crypt
 */
class SpaceCest
{
    /**
     * Tests Phalcon\Encryption\Crypt\Padding\Space :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-12
     */
    public function cryptPaddingSpace(UnitTester $I)
    {
        $I->wantToTest('Crypt\Padding\Space - pad()/unpad()');

        $object = new Space();

        $padding  = str_repeat(" ", 16);
        $expected = $padding;
        $actual   = $object->pad(16);
        $I->assertEquals($expected, $actual);

        $source   = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" . $padding;
        $expected = 16;
        $actual   = $object->unpad($source, 16);
        $I->assertEquals($expected, $actual);
    }
}
