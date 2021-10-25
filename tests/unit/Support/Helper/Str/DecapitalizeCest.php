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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\Decapitalize;
use UnitTester;

/**
 * Class DecapitalizeCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Str
 */
class DecapitalizeCest
{
    /**
     * Tests Phalcon\Support\Helper\Str :: decapitalize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperStrDecapitalize(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Str - decapitalize()');

        $object   = new Decapitalize();
        $source   = 'BeetleJuice';
        $expected = 'beetleJuice';
        $actual   = $object($source);
        $I->assertEquals($expected, $actual);

        $source   = 'BeetleJuice';
        $expected = 'bEETLEJUICE';
        $actual   = $object($source, true);
        $I->assertEquals($expected, $actual);
    }
}
