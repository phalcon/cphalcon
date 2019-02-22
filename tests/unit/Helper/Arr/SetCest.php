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

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

/**
 * Class SetCest
 */
class SetCest
{
    /**
     * Tests Phalcon\Helper\Arr :: set() - numeric
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function helperArrSetNumeric(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - numeric');
        $collection = [];
        $expected   = [
            1 => 'Phalcon',
        ];
        $actual     = Arr::set($collection, 'Phalcon', 1);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: set() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function helperArrSetString(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - string');
        $collection = [];
        $expected   = [
            'suffix' => 'Framework',
        ];
        $actual     = Arr::set($collection, 'Framework', 'suffix');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: set() - no index
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function helperArrSetNoIndex(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - no index');
        $collection = [];
        $expected   = [
            0 => 'Phalcon',
        ];
        $actual     = Arr::set($collection, 'Phalcon');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: set() - overwrite
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function helperArrSetOverwride(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - set() - overwrite');
        $collection = [
            1 => 'Phalcon'
        ];
        $expected   = [
            1 => 'Framework',
        ];
        $actual     = Arr::set($collection, 'Framework', 1);
        $I->assertEquals($expected, $actual);
    }
}
