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

namespace Phalcon\Tests\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use stdClass;
use UnitTester;

class ToObjectCest
{
    /**
     * Unit Tests Phalcon\Helper\Arr :: toObject()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function helperArrArrayToObject(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - toObject()');

        $source = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $actual = Arr::toObject($source);

        $expected        = new stdClass();
        $expected->one   = 'two';
        $expected->three = 'four';

        $I->assertEquals($expected, $actual);
    }
}
