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

namespace Phalcon\Test\Unit\Storage\Serializer\Php;

use Codeception\Example;
use Phalcon\Storage\Serializer\Php;
use stdClass;
use UnitTester;

/**
 * Class UnserializeCest
 */
class UnserializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\Php :: unserialize()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2019-03-30
     */
    public function storageSerializerPhpUnserialize(UnitTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\Php - unserialize() - ' . $example[0]);
        $serializer = new Php();
        $serialized = serialize($example[1]);
        $serializer->unserialize($serialized);

        $expected = $example[1];
        $actual   = $serializer->getData();
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return array
     */
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
