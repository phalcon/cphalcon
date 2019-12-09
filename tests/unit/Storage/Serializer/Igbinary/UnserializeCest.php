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

namespace Phalcon\Test\Unit\Storage\Serializer\Igbinary;

use Codeception\Example;
use Phalcon\Storage\Serializer\Igbinary;
use stdClass;
use UnitTester;

use function igbinary_serialize;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Igbinary :: unserialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerIgbinaryUnserialize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\Igbinary - unserialize() - ' . $example[0]);
        $serializer = new Igbinary();
        $serialized = igbinary_serialize($example[1]);
        $serializer->unserialize($serialized);

        $expected = $example[1];
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
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
