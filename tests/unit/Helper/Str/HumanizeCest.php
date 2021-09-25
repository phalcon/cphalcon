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

class HumanizeCest
{
    /**
     * Tests Phalcon\Helper\Str :: humanize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrHumanize(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - humanize()');
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
