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

namespace Phalcon\Test\Unit\Storage\Unserializer\Php;

use Codeception\Example;
use Phalcon\Storage\Serializer\Php;
use stdClass;
use UnitTester;

class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Unserializer\Php :: unserialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-03-30
     */
    public function storageSerializerPhpUnserialize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Unserializer\Php - unserialize() - ' . $example[0]);
        $serializer = new Php();

        $expected = $example[1];
        $serializer->unserialize($example[2]);
        $actual = $serializer->getData();
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
