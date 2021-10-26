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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\ToObject;
use stdClass;
use UnitTester;

/**
 * Class ToObjectCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class ToObjectCest
{
    /**
     * Unit Tests Phalcon\Support\Helper\Arr :: toObject()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrArrayToObject(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - toObject()');

        $object = new ToObject();
        $source = [
            'one'   => 'two',
            'three' => 'four',
        ];


        $expected        = new stdClass();
        $expected->one   = 'two';
        $expected->three = 'four';

        $actual = $object($source);
        $I->assertEquals($expected, $actual);
    }
}
