<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Storage\Serializer\Json;

use Codeception\Example;
use InvalidArgumentException;
use Phalcon\Storage\Serializer\Json;
use UnitTester;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Json :: serialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerJsonSerialize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\Json - serialize() - ' . $example[0]);
        $serializer = new Json($example[1]);

        $expected = $example[2];
        $actual   = $serializer->serialize();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Storage\Serializer\Json :: serialize() - error
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerJsonSerializeError(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Json - serialize() - error');

        $I->expectThrowable(
            new InvalidArgumentException(
                'Data for JSON serializer cannot be of type object'
            ),
            function () {
                $example = new \stdClass();
                $example->one = 'two';

                $serializer = new Json($example);
                $actual     = $serializer->serialize();
            }
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
                '"Phalcon Framework"',
            ],
            [
                'array',
                ['Phalcon Framework'],
                '["Phalcon Framework"]',
            ],
        ];
    }
}
