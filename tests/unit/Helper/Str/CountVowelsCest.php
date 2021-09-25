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

class CountVowelsCest
{
    /**
     * Tests Phalcon\Helper\Str :: countVowels()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-06
     */
    public function helperStrCountVowels(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - countVowels()');

        $source   = 'Luke, I am your father!';
        $expected = 8;
        $actual   = Str::countVowels($source);
        $I->assertEquals($expected, $actual);

        $source   = '';
        $expected = 0;
        $actual   = Str::countVowels($source);
        $I->assertEquals($expected, $actual);
    }
}
