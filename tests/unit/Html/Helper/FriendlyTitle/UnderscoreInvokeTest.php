<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\FriendlyTitle;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\FriendlyTitle;
use Phalcon\Html\TagFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class UnderscoreInvokeTest extends AbstractUnitTestCase
{
    /**
     * @return array<array<mixed>>
     */
    public static function getExamples(): array
    {
        return [
            [
                'hello-world',
                'Hello World',
                '-',
                true,
                null,
            ],
            [
                'Hello-World',
                'Hello World',
                '-',
                false,
                null,
            ],
            [
                'hello_world',
                'Hello World',
                '_',
                true,
                null,
            ],
            [
                'hello-and-world',
                'Hello & World',
                '-',
                true,
                null,
            ],
            [
                'hello-world',
                'Héllo Wörld',
                '-',
                true,
                null,
            ],
            [
                'hello-world',
                'Hello/World',
                '-',
                true,
                ['/'],
            ],
            [
                'hello-world',
                'Hello.World',
                '-',
                true,
                '.',
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2026-04-17
     */
    public function testHtmlHelperFriendlyTitleUnderscoreInvoke(
        string $expected,
        string $text,
        string $separator,
        bool $lowercase,
        mixed $replace
    ): void {
        $escaper = new Escaper();
        $helper  = new FriendlyTitle($escaper);

        $actual = $helper($text, $separator, $lowercase, $replace);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('friendlyTitle');
        $actual  = $locator($text, $separator, $lowercase, $replace);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $actual  = $factory->friendlyTitle($text, $separator, $lowercase, $replace);
        $this->assertSame($expected, $actual);
    }
}
