<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Support\Debug\Renderer;

use Phalcon\Support\Debug\Renderer\HtmlRenderer;
use Phalcon\Support\Debug\Report\BacktraceItem;
use Phalcon\Support\Debug\Report\ExceptionReport;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class HtmlRendererEscapeTest extends AbstractUnitTestCase
{
    private const URI = 'https://assets.phalcon.io/debug/6.0.x/';

    /**
     * The class name and the file paths must be escaped, quotes included.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17731
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testRenderEscapesClassNameAndFiles(): void
    {
        $report = new ExceptionReport('Ex<b>', 'boom', "/app/it's.php", 1, true, self::URI);
        $report->setBacktrace(
            [
                new BacktraceItem(
                    'methodA',
                    null,
                    null,
                    null,
                    null,
                    false,
                    [],
                    "/app/frame's.php",
                    7,
                    null
                ),
            ]
        );

        $actual = (new HtmlRenderer())->render($report);

        $this->assertStringNotContainsString('Ex<b>', $actual);
        $this->assertStringNotContainsString("it's.php", $actual);
        $this->assertStringNotContainsString("frame's.php", $actual);
        $this->assertStringContainsString('<title>Ex&lt;b&gt;:boom</title>', $actual);
        $this->assertStringContainsString("<span class='error-type'>Ex&lt;b&gt;</span>", $actual);
        $this->assertStringContainsString('<code>/app/it&#039;s.php</code>', $actual);
        $this->assertStringContainsString("data-file='/app/frame&#039;s.php'", $actual);
        $this->assertStringContainsString('<b>/app/frame&#039;s.php</b>', $actual);
    }

    /**
     * The source lines must escape quotes and keep the text with invalid UTF-8.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17731
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testRenderEscapesFragmentLines(): void
    {
        $report = new ExceptionReport('Ex', 'boom', '/app/x.php', 2, true, self::URI);
        $report->setBacktrace(
            [
                new BacktraceItem(
                    'methodA',
                    null,
                    null,
                    null,
                    null,
                    false,
                    [],
                    '/app/x.php',
                    2,
                    [
                        'firstLine' => 1,
                        'line'      => 2,
                        'lastLine'  => 2,
                        'lines'     => ["\$a = 'x';", "bad \xE9 byte"],
                    ]
                ),
            ]
        );

        $actual = (new HtmlRenderer())->render($report);

        $this->assertStringContainsString(
            "<td class='src'>\$a = &#039;x&#039;;</td>",
            $actual
        );
        $this->assertStringContainsString(
            "<td class='src'>bad \u{FFFD} byte</td>",
            $actual
        );
    }

    /**
     * A message with invalid UTF-8 must not become an empty string.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17731
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testRenderKeepsInvalidUtf8Message(): void
    {
        $report = new ExceptionReport('Ex', "bad \xE9 byte", '/app/x.php', 1, false, self::URI);

        $actual = (new HtmlRenderer())->render($report);

        $this->assertStringContainsString("<title>Ex:bad \u{FFFD} byte</title>", $actual);
        $this->assertStringContainsString(
            "<h1 class='error-message'>bad \u{FFFD} byte</h1>",
            $actual
        );
    }

    /**
     * The class name of a dumped object must be escaped. The name of an
     * anonymous class from eval()'d code contains a quote.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17731
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-06
     */
    public function testVarDumpAndArrayDumpEscapeClassName(): void
    {
        $renderer = new class () extends HtmlRenderer {
            public function dumpArr(array $arguments): string | null
            {
                return $this->getArrayDump($arguments);
            }

            public function dumpVar(mixed $value): string
            {
                return $this->getVarDump($value);
            }
        };

        $object = eval('return new class () {};');

        $actualVar = $renderer->dumpVar($object);
        $actualArr = (string) $renderer->dumpArr([$object]);

        $this->assertStringNotContainsString("eval()'d code", $actualVar);
        $this->assertStringContainsString('eval()&#039;d code', $actualVar);
        $this->assertStringNotContainsString("eval()'d code", $actualArr);
        $this->assertStringContainsString('eval()&#039;d code', $actualArr);
    }
}
