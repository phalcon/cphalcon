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
use Phalcon\Storage\Serializer\Msgpack;
use stdClass;
use IntegrationTester;

use function msgpack_pack;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Msgpack :: serialize()
     *
     * @note         dataProvider is not used here, it messes up console output
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerMsgpackSerialize(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Msgpack - serialize()');

        foreach ($this->getExamples() as $example) {
            $serializer = new Msgpack($example[1]);

            $expected = $example[2];

            $I->assertEquals(
                $expected,
                $serializer->serialize()
            );
        }
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
