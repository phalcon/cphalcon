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

namespace Phalcon\Tests\Integration\Storage\Serializer\None;

use Codeception\Example;
use Phalcon\Storage\Serializer\None;
use IntegrationTester;

class SerializeCest
{
    /**
     * Tests Phalcon\Storage\Serializer\None :: serialize()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-03-30
     */
    public function storageSerializerNoneSerialize(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Storage\Serializer\None - serialize()');
        $serializer = new None($example[1]);

        $expected = $example[2];
        $actual   = $serializer->serialize();
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
                'Phalcon Framework',
            ],
            [
                'array',
                ['Phalcon Framework'],
                ["Phalcon Framework"],
            ],
        ];
    }
}
