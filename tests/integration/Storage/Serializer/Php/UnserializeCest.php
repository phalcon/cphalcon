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

namespace Phalcon\Test\Integration\Storage\Serializer\Php;

use Codeception\Example;
use InvalidArgumentException;
use Phalcon\Storage\Serializer\Php;
use stdClass;
use IntegrationTester;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Unserializer\Php :: unserialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerPhpUnserialize(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\Unserializer\Php - unserialize() - ' . $example[0]);

        $serializer = new Php();

        $expected = $example[1];

        $serializer->unserialize($example[2]);

        $I->assertEquals(
            $expected,
            $serializer->getData()
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Php :: unserialize() - error not string
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-11-21
     */
    public function storageSerializerPhpUnserializeErrorNotString(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - unserialize() - error not string');
        $I->expectThrowable(
            new InvalidArgumentException(
                'Data for the unserializer must of type string'
            ),
            function () {
                $serializer = new Php();

                $serialized = new stdClass();
                $serializer->unserialize($serialized);
            }
        );
    }

    /**
     * Tests Phalcon\Storage\Serializer\Php :: unserialize() - error
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-11-21
     */
    public function storageSerializerPhpUnserializeError(IntegrationTester $I)
    {
        $I->wantToTest('Storage\Serializer\Php - unserialize() - error');
        $serializer = new Php();

        $serialized = '{??hello?unserialize"';
        $serializer->unserialize($serialized);

        $I->assertEmpty($serializer->getData());
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
