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

namespace Phalcon\Test\Unit\Helper\Str;

use Phalcon\Helper\Str;
use UnitTester;

/**
 * Class UnderscoreCest
 */
class UnderscoreCest
{
    /**
     * Tests Phalcon\Helper\Str :: underscore()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textUnderscore(UnitTester $I)
    {
        $I->wantToTest('Text - underscore()');
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
