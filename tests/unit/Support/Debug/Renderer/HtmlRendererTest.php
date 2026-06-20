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

namespace Phalcon\Tests\Unit\Support\Debug\Renderer;

use Phalcon\Support\Debug\Renderer\HtmlRenderer;
use Phalcon\Support\Debug\Report\BacktraceItem;
use Phalcon\Support\Debug\Report\ExceptionReport;
use Phalcon\Support\Debug\ReportBuilder;
use Phalcon\Support\Exception;
use Phalcon\Support\Version;
use Phalcon\Tests\AbstractUnitTestCase;

final class HtmlRendererTest extends AbstractUnitTestCase
{
    private const URI = 'https://assets.phalcon.io/debug/6.0.x/';

    public function testGetCssSources(): void
    {
        $uri      = self::URI;
        $expected = "
    <link href='{$uri}debug.css'
          rel='stylesheet'
          type='text/css' />";

        $this->assertSame($expected, (new HtmlRenderer())->getCssSources($uri));
    }

    public function testGetJsSources(): void
    {
        $uri      = self::URI;
        $expected = "
    <script src='{$uri}debug.js'></script>";

        $this->assertSame($expected, (new HtmlRenderer())->getJsSources($uri));
    }

    public function testSetTemplateOverridesDefault(): void
    {
        $renderer = new HtmlRenderer();
        $renderer->setTemplate('version', 'OVERRIDDEN');

        $this->assertSame('OVERRIDDEN', $renderer->getTemplate('version'));
    }

    public function testRenderNoBacktraceDocument(): void
    {
        $exception = new Exception('exception message', 1234);
        $report    = (new ReportBuilder())->build(
            $exception,
            ['request' => [], 'server' => []],
            false,
            true,
            false,
            self::URI,
            []
        );

        $version = new Version();
        $link    = $version->getPart(Version::VERSION_MAJOR)
            . '.'
            . $version->getPart(Version::VERSION_MEDIUM);

        $actual = (new HtmlRenderer())->render($report);

        $this->assertStringContainsString(
            "<title>Phalcon\\Support\\Exception:exception message</title>",
            $actual
        );
        $this->assertStringContainsString(
            "<a class='version-badge' href='https://docs.phalcon.io/{$link}/' target='_new'>",
            $actual
        );
        $this->assertStringContainsString(
            "<span class='error-type'>Phalcon\\Support\\Exception</span>",
            $actual
        );
        $this->assertStringContainsString(
            "<h1 class='error-message'>exception message</h1>",
            $actual
        );
        $this->assertStringNotContainsString('data-tab=', $actual);
        $this->assertStringEndsWith('</html>', $actual);
    }

    public function testRenderWithBacktraceContainsTabs(): void
    {
        $exception = new Exception('exception message', 1234);
        $report    = (new ReportBuilder())->build(
            $exception,
            ['request' => [], 'server' => []],
            true,
            false,
            false,
            self::URI,
            []
        );

        $actual = (new HtmlRenderer())->render($report);

        $this->assertStringContainsString("<div class='tabs' role='tablist'>", $actual);
        $this->assertStringContainsString("data-tab='backtrace'", $actual);
        $this->assertStringContainsString("data-tab='memory'", $actual);
        $this->assertStringContainsString("id='backtrace'", $actual);
        $this->assertStringContainsString("<details class='frame", $actual);
    }

    public function testVarDumpAndArrayDumpBranches(): void
    {
        $renderer = new class extends HtmlRenderer {
            public function dumpVar(mixed $value): string
            {
                return $this->getVarDump($value);
            }

            public function dumpArr(array $arguments, int $number = 0): string | null
            {
                return $this->getArrayDump($arguments, $number);
            }
        };

        $object = new class {
            public function dump(): array
            {
                return ['k' => 'v'];
            }
        };

        $resource = fopen('php://memory', 'r');

        $this->assertSame('true', $renderer->dumpVar(true));
        $this->assertSame('false', $renderer->dumpVar(false));
        $this->assertSame('42', $renderer->dumpVar(42));
        $this->assertSame('null', $renderer->dumpVar(null));
        $this->assertSame('resource', $renderer->dumpVar($resource));
        $this->assertSame('Object(stdClass)', $renderer->dumpVar(new \stdClass()));
        $this->assertStringContainsString('a&lt;b', $renderer->dumpVar('a<b'));
        $this->assertStringContainsString('Array(', $renderer->dumpVar([1, 2]));
        $this->assertStringContainsString('=&gt;', $renderer->dumpVar($object));

        $this->assertNull($renderer->dumpArr([]));
        $this->assertSame('12', $renderer->dumpArr(range(1, 12)));

        $dump = $renderer->dumpArr(['', 5, [1], new \stdClass(), null, $resource]);
        $this->assertStringContainsString('(empty string)', $dump);
        $this->assertStringContainsString('Array(', $dump);
        $this->assertStringContainsString('Object(stdClass)', $dump);
        $this->assertStringContainsString('null', $dump);
        $this->assertStringContainsString('Resource', $dump);

        $this->assertStringContainsString('Array(', (string)$renderer->dumpVar([[[['deep']]]]));

        fclose($resource);
    }

    public function testRenderSignatureLinksAndArgs(): void
    {
        $arg    = uniqid('var-');
        $report = new ExceptionReport('My\\Ex', 'boom', '/app/x.php', 5, true, self::URI);
        $report->setBacktrace(
            [
                new BacktraceItem(
                    'methodA',
                    '->',
                    'My\\Service',
                    'https://docs.example/My_Service',
                    null,
                    true,
                    [$arg],
                    '/app/x.php',
                    5,
                    null
                ),
                new BacktraceItem(
                    'array_map',
                    null,
                    null,
                    null,
                    'https://secure.php.net/manual/en/function.array-map.php',
                    false,
                    [],
                    null,
                    null,
                    null
                ),
            ]
        );

        $actual = (new HtmlRenderer())->render($report);

        $this->assertStringContainsString("href='https://docs.example/My_Service'", $actual);
        $this->assertStringContainsString(
            "href='https://secure.php.net/manual/en/function.array-map.php'",
            $actual
        );
        $this->assertStringContainsString($arg, $actual);
    }
}
