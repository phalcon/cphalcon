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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class DecapitalizeCest
{
    /**
     * Tests Phalcon\Helper\Str :: decapitalize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrDecapitalize(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - decapitalize()');

        $source   = 'BeetleJuice';
        $expected = 'beetleJuice';
        $actual   = Str::decapitalize($source);
        $I->assertEquals($expected, $actual);

        $source   = 'BeetleJuice';
        $expected = 'bEETLEJUICE';
        $actual   = Str::decapitalize($source, true);
        $I->assertEquals($expected, $actual);
    }
}
