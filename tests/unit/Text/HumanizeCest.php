<?php

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

class HumanizeCest
{
    /**
     * Tests Phalcon\Text :: humanize()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function textHumanize(UnitTester $I)
    {
        $I->wantToTest('Text - humanize()');
        $expected = 'start a horse';
        $actual   = Text::humanize('start_a_horse');
        $I->assertEquals($expected, $actual);

        $expected = 'five cats';
        $actual   = Text::humanize('five-cats');
        $I->assertEquals($expected, $actual);

        $expected = 'kittens are cats';
        $actual   = Text::humanize('kittens-are_cats');
        $I->assertEquals($expected, $actual);

        $expected = 'Awesome Phalcon';
        $actual   = Text::humanize(" \t Awesome-Phalcon \t ");
        $I->assertEquals($expected, $actual);
    }
}
