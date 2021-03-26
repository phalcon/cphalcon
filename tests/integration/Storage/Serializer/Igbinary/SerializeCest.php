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

namespace Phalcon\Test\Integration\Storage\Serializer\Igbinary;

use Codeception\Example;
use Phalcon\Storage\Serializer\Igbinary;
use stdClass;
use IntegrationTester;

use function igbinary_serialize;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: serialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerIgbinarySerialize(IntegrationTester $I, Example $example)
    {
        $I->wantToTest(
            'Storage\Serializer\Igbinary - serialize() - ' . $example['label']
        );

        $serializer = new Igbinary($example['value']);

        $expected = $example['expected'];

        $I->assertEquals(
            $expected,
            $serializer->serialize()
        );
    }

    private function getExamples(): array
    {
        return [
            [
                'label'    => 'null',
                'value'    => null,
                'expected' => null,
            ],
            [
                'label'    => 'true',
                'value'    => true,
                'expected' => true,
            ],
            [
                'label'    => 'false',
                'value'    => false,
                'expected' => false,
            ],
            [
                'label'    => 'integer',
                'value'    => 1234,
                'expected' => igbinary_serialize(1234),
            ],
            [
                'label'    => 'float',
                'value'    => 1.234,
                'expected' => igbinary_serialize(1.234),
            ],
            [
                'label'    => 'string',
                'value'    => 'Phalcon Framework',
                'expected' => igbinary_serialize('Phalcon Framework'),
            ],
            [
                'label'    => 'array',
                'value'    => ['Phalcon Framework'],
                'expected' => igbinary_serialize(['Phalcon Framework']),
            ],
            [
                'label'    => 'object',
                'value'    => new stdClass(),
                'expected' => igbinary_serialize(new stdClass()),
            ],
        ];
    }
}
