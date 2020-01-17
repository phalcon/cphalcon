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

namespace Phalcon\Test\Integration\Storage\Serializer\Json;

use Phalcon\Collection;
use Phalcon\Storage\Serializer\Json;
use Codeception\Example;
use InvalidArgumentException;
use UnitTester;

use function json_encode;

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
     * Tests Phalcon\Storage\Serializer\Json :: serialize() - object
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-11-11
     */
    public function storageSerializerJsonSerializeObject(UnitTester $I)
    {
        $I->wantToTest('Storage\Serializer\Json - serialize() - object');

        $collection1 = new Collection();
        $collection1->set('one', 'two');
        $collection2 = new Collection();
        $collection2->set('three', 'four');
        $collection2->set('object', $collection1);

        $serializer = new Json($collection2);

        $data     = [
            'three'  => 'four',
            'object' => [
                'one' => 'two',
            ],
        ];
        $expected = json_encode($data);
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
                "Data for the JSON serializer cannot be of type 'object' " .
                "without implementing 'JsonSerializable'"
            ),
            function () {
                $example      = new \stdClass();
                $example->one = 'two';

                $serializer = new Json($example);
                $actual     = $serializer->serialize();
            }
        );
    }

    /**
     * @return array
     */
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
