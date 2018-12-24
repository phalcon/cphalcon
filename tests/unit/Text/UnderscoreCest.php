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

namespace Phalcon\Test\Unit\Text;

use Phalcon\Text;
use UnitTester;

/**
 * Class UnderscoreCest
 */
class UnderscoreCest
{
    /**
     * Tests Phalcon\Text :: underscore()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textUnderscore(UnitTester $I)
    {
        $I->wantToTest('Text - underscore()');
        $expected = 'start_a_horse';
        $actual   = Text::underscore('start a horse');
        $I->assertEquals($expected, $actual);

        $expected = 'five_cats';
        $actual   = Text::underscore("five\tcats");
        $I->assertEquals($expected, $actual);

        $expected = 'look_behind';
        $actual   = Text::underscore(' look behind ');
        $I->assertEquals($expected, $actual);

        $expected = 'Awesome_Phalcon';
        $actual   = Text::underscore(" \t Awesome \t  \t Phalcon ");
        $I->assertEquals($expected, $actual);
    }
}
