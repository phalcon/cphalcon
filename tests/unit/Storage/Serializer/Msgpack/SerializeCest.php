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

use Codeception\Example;
use function msgpack_pack;
use Phalcon\Storage\Serializer\Msgpack;
use stdClass;
use UnitTester;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: serialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-03-30
     */
    public function storageSerializerMsgpackSerialize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - serialize() - ' . $example[0]);
        $serializer = new Msgpack($example[1]);

        $expected = $example[2];
        $actual   = $serializer->serialize();
        $I->assertEquals($expected, $actual);
    }

    private function getExamples(): array
    {
        return [
            [
                'null',
                null,
                null,
            ],
            [
                'true',
                true,
                true,
            ],
            [
                'false',
                false,
                false,
            ],
            [
                'integer',
                1234,
                1234,
            ],
            [
                'float',
                1.234,
                1.234,
            ],
            [
                'string',
                'Phalcon Framework',
                msgpack_pack('Phalcon Framework'),
            ],
            [
                'array',
                ['Phalcon Framework'],
                msgpack_pack(['Phalcon Framework']),
            ],
            [
                'object',
                new stdClass(),
                msgpack_pack(new stdClass()),
            ],
        ];
    }
}
