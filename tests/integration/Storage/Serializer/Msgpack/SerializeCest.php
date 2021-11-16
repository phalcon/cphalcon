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
use stdClass;

use function msgpack_pack;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: serialize()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerMsgpackSerialize(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - serialize()');

        // null
        $source     = null;
        $serializer = new Msgpack($source);
        $expected   = null;
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);

        // true
        $source     = true;
        $serializer = new Msgpack($source);
        $expected   = true;
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);

        // false
        $source     = false;
        $serializer = new Msgpack($source);
        $expected   = false;
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);

        // integer
        $source     = 1234;
        $serializer = new Msgpack($source);
        $expected   = 1234;
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);

        // float
        $source     = 1.234;
        $serializer = new Msgpack($source);
        $expected   = 1.234;
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);

        // string
        $source     = 'Phalcon Framework';
        $serializer = new Msgpack($source);
        $expected   = msgpack_pack('Phalcon Framework');
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);

        // array',
        $source     = ['Phalcon Framework'];
        $serializer = new Msgpack($source);
        $expected   = msgpack_pack(['Phalcon Framework']);
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);

        // object
        $source     = new stdClass();
        $serializer = new Msgpack($source);
        $expected   = msgpack_pack(new stdClass());
        $actual     = $serializer->serialize();
        $I->assertEquals($expected, $actual);
    }
}
