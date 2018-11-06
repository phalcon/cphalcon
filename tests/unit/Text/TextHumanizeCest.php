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

class TextHumanizeCest
{
    /**
     * Tests the humanize function
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2015-11-09
     */
    public function testUnderscore(UnitTester $I)
    {
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
