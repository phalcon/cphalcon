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
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionAlpha;
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionBeta;
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionRc;
use Phalcon\Tests\Unit\Support\Version\Fake\FakeVersionStable;

use function is_string;

final class GetTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getExamples(): array
    {
        return [
            [
                FakeVersionAlpha::class,
                '5.0.0alpha1',
            ],
            [
                FakeVersionBeta::class,
                '5.0.0beta2',
            ],
            [
                FakeVersionRc::class,
                '5.0.0RC3',
            ],
            [
                FakeVersionStable::class,
                '5.0.0',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-09-09
     */
    public function testSupportVersionGet(
        string $class,
        string $expected,
    ): void {
        $version = new $class();

        $actual = $version->get();
        $this->assertTrue(is_string($actual));
        $this->assertSame($expected, $actual);
    }
}
