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

namespace Phalcon\Test\Unit\Utility;

use Phalcon\Utility;
use UnitTester;

/**
 * Class ArrayGetDefaultCest
 */
class ArrayGetDefaultCest
{
    /**
     * Tests Phalcon\Utility :: arrayGetDefault()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function utilityArrayGetDefault(UnitTester $I)
    {
        $I->wantToTest('Utility - arrayGetDefault()');
        $data = [
            'name' => 'Phalcon',
            'born' => 2012,
        ];

        $expected = 'Phalcon';
        $actual   = Utility::arrayGetDefault('name', $data);
        $I->assertEquals($expected, $actual);

        $expected = 2012;
        $actual   = Utility::arrayGetDefault('born', $data);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Utility :: arrayGetDefault() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-07
     */
    public function utilityArrayGetDefaultDefault(UnitTester $I)
    {
        $I->wantToTest('Utility - arrayGetDefault() - default');
        $data = [];

        $expected = 'Phalcon';
        $actual   = Utility::arrayGetDefault('name', $data, 'Phalcon');
        $I->assertEquals($expected, $actual);

        $expected = 2012;
        $actual   = Utility::arrayGetDefault('born', $data, 2012);
        $I->assertEquals($expected, $actual);
    }
}
