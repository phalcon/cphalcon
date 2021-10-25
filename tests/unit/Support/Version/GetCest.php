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
use Phalcon\Tests\Fixtures\Version\VersionAlphaFixture;
use Phalcon\Tests\Fixtures\Version\VersionBetaFixture;
use Phalcon\Tests\Fixtures\Version\VersionRcFixture;
use Phalcon\Tests\Fixtures\Version\VersionStableFixture;
use UnitTester;

use function is_string;

class GetCest
{
    /**
     * Tests get()
     *
     * @dataProvider getExamples
     *
     * @param UnitTester $I
     * @param Example    $example
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function supportVersionGet(UnitTester $I, Example $example)
    {
        $I->wantToTest('Version - get() - ' . $example[0]);

        $version = new $example[1]();

        $expected = $example[2];
        $actual   = $version->get();
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
                '5.0.0alpha1',
            ],
            [
                'beta',
                VersionBetaFixture::class,
                '5.0.0beta2',
            ],
            [
                'rc',
                VersionRcFixture::class,
                '5.0.0RC3',
            ],
            [
                'stable',
                VersionStableFixture::class,
                '5.0.0',
            ],
        ];
    }
}
