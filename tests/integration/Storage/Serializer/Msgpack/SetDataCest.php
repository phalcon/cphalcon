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

namespace Phalcon\Tests\Integration\Storage\Serializer\Msgpack;

use IntegrationTester;
use Phalcon\Storage\Serializer\Msgpack;

class SetDataCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: getData()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerMsgpackSetData(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - setData()');
        $data       = ['Phalcon Framework'];
        $serializer = new Msgpack();

        $actual = $serializer->getData();
        $I->assertNull($actual);

        $serializer->setData($data);

        $expected = $data;
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }
}
