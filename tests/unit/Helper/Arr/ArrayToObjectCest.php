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
use stdClass;
use UnitTester;

class ArrayToObjectCest
{
    /**
     * Unit Tests Phalcon\Helper\Arr :: arrayToObject()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function helperArrArrayToObject(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - arrayToObject()');

        $source = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $actual = Arr::arrayToObject($source);

        $expected        = new stdClass();
        $expected->one   = 'two';
        $expected->three = 'four';

        $I->assertEquals($expected, $actual);
    }
}
