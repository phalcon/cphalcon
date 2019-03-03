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
use Phalcon\Helper\Exception;
use UnitTester;

/**
 * Class GetCest
 */
class GetCest
{
    /**
     * Tests Phalcon\Helper\Arr :: get() - numeric
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-17
     */
    public function helperArrGetNumeric(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - get() - numeric');

        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Phalcon';
        $actual   = Arr::get($collection, 1, 'Error');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: get() - string
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-17
     */
    public function helperArrGetString(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - get() - string');

        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Framework';
        $actual   = Arr::get($collection, 'suffix', 'Error');
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Helper\Arr :: get() - default
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-17
     */
    public function helperArrGetDefault(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - get() - default');

        $collection = [
            1        => 'Phalcon',
            'suffix' => 'Framework',
        ];

        $expected = 'Error';
        $actual   = Arr::get($collection, 'unknown', 'Error');
        $I->assertEquals($expected, $actual);
    }
}
