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

namespace Phalcon\Test\Unit\Storage\Serializer\Php;

use Codeception\Example;
use Phalcon\Storage\Serializer\Php;
use stdClass;
use UnitTester;

use function serialize;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Php :: serialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerPhpSerialize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\Php - serialize() - ' . $example[0]);

        $serializer = new Php($example[1]);

        $expected = $example[2];

        $I->assertEquals(
            $expected,
            $serializer->serialize()
        );
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
                serialize('Phalcon Framework'),
            ],
            [
                'array',
                ['Phalcon Framework'],
                serialize(['Phalcon Framework']),
            ],
            [
                'object',
                new stdClass(),
                serialize(new stdClass()),
            ],
        ];
    }
}
