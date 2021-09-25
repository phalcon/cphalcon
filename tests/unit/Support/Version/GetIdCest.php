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
use Phalcon\Tests\Fixtures\Support\Version\VersionAlphaFixture;
use Phalcon\Tests\Fixtures\Support\Version\VersionBetaFixture;
use Phalcon\Tests\Fixtures\Support\Version\VersionRcFixture;
use Phalcon\Tests\Fixtures\Support\Version\VersionStableFixture;
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

        $version = new $example[1]();

        $expected = $example[2];
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
                VersionAlphaFixture::class,
                '5000011',
            ],
            [
                'beta',
                VersionBetaFixture::class,
                '5000022',
            ],
            [
                'rc',
                VersionRcFixture::class,
                '5000033',
            ],
            [
                'stable',
                VersionStableFixture::class,
                '5000000',
            ],
        ];
    }
}
