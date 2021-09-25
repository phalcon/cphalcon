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

namespace Phalcon\Tests\Unit\Support\Version;

use Codeception\Example;
use Codeception\Util\Stub;
use Phalcon\Support\Version;
use Phalcon\Tests\Fixtures\Traits\VersionTrait;
use UnitTester;

use function is_string;

class GetIdCest
{
    use VersionTrait;

    /**
     * Tests get()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function supportVersionGetId(UnitTester $I, Example $example)
    {
        $I->wantToTest('Version - getId() - ' . $example[0]);

        $version = Stub::make(
            Version::class,
            [
                'getVersion' => $example[2],
            ]
        );

        $expected = $example[1];
        $actual   = $version->getId();
        $I->assertTrue(is_string($actual));
        $I->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    private function getExamples(): array
    {
        return [
            [
                'alpha',
                '5000011',
                [5, 0, 0, 1, 1],
            ],
            [
                'beta',
                '5000022',
                [5, 0, 0, 2, 2],
            ],
            [
                'rc',
                '5000033',
                [5, 0, 0, 3, 3],
            ],
            [
                'stable',
                '5000040',
                [5, 0, 0, 4, 0],
            ],
        ];
    }
}
