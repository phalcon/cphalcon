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

use Codeception\Example;
use IntegrationTester;
use Phalcon\Storage\Serializer\Msgpack;
use stdClass;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: unserialize()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageSerializerMsgpackUnserialize(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - unserialize() - ' . $example[0]);
        $serializer = new Msgpack();
        $serialized = msgpack_pack($example[1]);
        $serializer->unserialize($serialized);

        $expected = $example[1];
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: unserialize() - error
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function storageSerializerMsgpackUnserializeError(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - unserialize() - error');
        $serializer = new Msgpack();

        $serialized = '??hello?messagepack"';
        $serializer->unserialize($serialized);

        $I->assertEmpty($serializer->getData());
    }

    private function getExamples(): array
    {
        return [
            [
                'integer',
                1234,
            ],
            [
                'float',
                1.234,
            ],
            [
                'string',
                'Phalcon Framework',
            ],
            [
                'array',
                ['Phalcon Framework'],
            ],
            [
                'object',
                new stdClass(),
            ],
        ];
    }
}
