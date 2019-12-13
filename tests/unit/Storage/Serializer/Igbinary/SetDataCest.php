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

namespace Phalcon\Test\Unit\Storage\Serializer\Igbinary;

use Phalcon\Storage\Serializer\Igbinary;
use UnitTester;

class SetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: getData()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-03-30
     */
    public function storageSerializerIgbinarySetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - setData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Igbinary();

        $actual = $serializer->getData();
        $I->assertNull($actual);

        $serializer->setData($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
