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

namespace Phalcon\Tests\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

class UnderscoreCest
{
    /**
     * Tests Phalcon\Helper\Str :: underscore()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrUnderscore(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - underscore()');
        $expected = 'start_a_horse';
        $actual   = Str::underscore('start a horse');
        $I->assertEquals($expected, $actual);

        $expected = 'five_cats';
        $actual   = Str::underscore("five\tcats");
        $I->assertEquals($expected, $actual);

        $expected = 'look_behind';
        $actual   = Str::underscore(' look behind ');
        $I->assertEquals($expected, $actual);

        $expected = 'Awesome_Phalcon';
        $actual   = Str::underscore(" \t Awesome \t  \t Phalcon ");
        $I->assertEquals($expected, $actual);
    }
}
