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

namespace Phalcon\Test\Unit\Storage\Serializer\Msgpack;

use Phalcon\Storage\Serializer\Msgpack;
use UnitTester;

class GetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: getData()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-03-30
     */
    public function storageSerializerMsgpackGetData(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - getData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Msgpack($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
