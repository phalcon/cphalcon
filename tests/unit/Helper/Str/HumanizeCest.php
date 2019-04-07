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
 * Class HumanizeCest
 */
class HumanizeCest
{
    /**
     * Tests Phalcon\Helper\Str :: humanize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-06
     */
    public function textHumanize(UnitTester $I)
    {
        $I->wantToTest('Text - humanize()');
        $expected = 'start a horse';
        $actual   = Str::humanize('start_a_horse');
        $I->assertEquals($expected, $actual);

        $expected = 'five cats';
        $actual   = Str::humanize('five-cats');
        $I->assertEquals($expected, $actual);

        $expected = 'kittens are cats';
        $actual   = Str::humanize('kittens-are_cats');
        $I->assertEquals($expected, $actual);

        $expected = 'Awesome Phalcon';
        $actual   = Str::humanize(" \t Awesome-Phalcon \t ");
        $I->assertEquals($expected, $actual);
    }
}
