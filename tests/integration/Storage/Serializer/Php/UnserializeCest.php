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

namespace Phalcon\Tests\Integration\Storage\Serializer\Php;

use Codeception\Example;
use IntegrationTester;
use InvalidArgumentException;
use Phalcon\Storage\Serializer\Php;
use stdClass;

use function serialize;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Unserializer\Php :: unserialize()
     *
     * @dataProvider getExamples
     *
     * @param IntegrationTester $I
     * @param Example           $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function storageSerializerPhpUnserialize(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\Unserializer\Php - unserialize() - ' . $example[0]);

        $serializer = new Php();


        $serializer->unserialize($example[2]);

        $expected = $example[1];
        $actual   = $serializer->getData();

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Php :: unserialize() - error not string
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
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
                serialize(null),
            ],
            [
                'true',
                true,
                serialize(true),
            ],
            [
                'false',
                false,
                serialize(false),
            ],
            [
                'integer',
                1234,
                serialize(1234),
            ],
            [
                'float',
                1.234,
                serialize(1.234),
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
