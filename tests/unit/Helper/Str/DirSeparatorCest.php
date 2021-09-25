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

class DirSeparatorCest
{
    /**
     * Tests Phalcon\Helper\Str :: dirSeparator()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function helperStrFolderSeparator(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - dirSeparator()');

        $expected = '/home/phalcon/';
        $actual   = Str::dirSeparator('/home/phalcon');
        $I->assertEquals($expected, $actual);

        $expected = '/home/phalcon/';
        $actual   = Str::dirSeparator('/home/phalcon//');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Str :: dirSeparator() - empty string
     */
    public function helperStrFolderSeparatorEmptyString(UnitTester $I)
    {
        $I->wantToTest('Helper\Str - dirSeparator() - empty string');
        $fileName = '';

        $expected = '/';
        $actual   = Str::dirSeparator($fileName);
        $I->assertEquals($expected, $actual);
    }
}
