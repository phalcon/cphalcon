<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.md
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Html\Helper\Preload;

use Phalcon\Html\Escaper;
use Phalcon\Html\Helper\Preload;
use Phalcon\Html\TagFactory;
use Phalcon\Http\ResponseInterface;
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
                '<link rel="preload" href="/my-style.css" as="style" />',
                '/my-style.css',
                'style',
                [],
            ],
            [
                '<link rel="preload" href="/my-script.js" as="script" />',
                '/my-script.js',
                'script',
                [],
            ],
            [
                '<link rel="preload" href="/my-font.woff2" as="font" />',
                '/my-font.woff2',
                'font',
                [],
            ],
            [
                '<link rel="preload" href="/my-style.css" as="style" crossorigin="anonymous" />',
                '/my-style.css',
                'style',
                ['crossorigin' => 'anonymous'],
            ],
            [
                '<link rel="preload" href="/my-style.css" as="style" />',
                '/my-style.css',
                'style',
                ['rel' => 'stylesheet', 'href' => '/other.css', 'as' => 'font'],
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2026-04-17
     */
    public function testHtmlHelperPreloadUnderscoreInvoke(
        string $expected,
        string $href,
        string $type,
        array $attributes
    ): void {
        $escaper = new Escaper();
        $helper  = new Preload($escaper);

        $actual = $helper($href, $type, $attributes);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $locator = $factory->newInstance('preload');
        $actual  = $locator($href, $type, $attributes);
        $this->assertSame($expected, $actual);

        $factory = new TagFactory($escaper);
        $actual  = $factory->preload($href, $type, $attributes);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testHtmlHelperPreloadSetsResponseHeader(): void
    {
        $escaper  = new Escaper();
        $response = $this->createMock(ResponseInterface::class);

        $response
            ->expects($this->once())
            ->method('setRawHeader')
            ->with('Link: </my-font.woff2>; rel="preload"; as="font"')
        ;

        $helper = new Preload($escaper, $response);
        $actual = $helper('/my-font.woff2', 'font');

        $this->assertSame('<link rel="preload" href="/my-font.woff2" as="font" />', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-17
     */
    public function testHtmlHelperPreloadSetsResponseHeaderViaTagFactory(): void
    {
        $escaper  = new Escaper();
        $response = $this->createMock(ResponseInterface::class);

        $response
            ->expects($this->once())
            ->method('setRawHeader')
            ->with('Link: </my-style.css>; rel="preload"; as="style"')
        ;

        $factory = new TagFactory($escaper, [], $response);
        $actual  = $factory->preload('/my-style.css', 'style');

        $this->assertSame('<link rel="preload" href="/my-style.css" as="style" />', $actual);
    }
}
