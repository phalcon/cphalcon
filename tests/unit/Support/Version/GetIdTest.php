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

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Support\Fake\VersionTrait;
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionAlpha;
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionBeta;
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionRc;
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionStable;

use function is_string;

final class GetIdTest extends AbstractUnitTestCase
{
    use VersionTrait;

    /**
     * @return string[][]
     */
    public static function getExamples(): array
    {
        return [
            [
                FakeVersionAlpha::class,
                '5000011',
            ],
            [
                FakeVersionBeta::class,
                '5000022',
            ],
            [
                FakeVersionRc::class,
                '5000033',
            ],
            [
                FakeVersionStable::class,
                '5000000',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testSupportVersionGetId(
        string $class,
        string $expected,
    ): void {
        $version = new $class();

        $actual = $version->getId();
        $this->assertTrue(is_string($actual));
        $this->assertSame($expected, $actual);
    }
}
