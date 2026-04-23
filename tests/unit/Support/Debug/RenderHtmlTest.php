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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Support\Debug;
use Phalcon\Support\Exception;
use Phalcon\Support\Version;
use Phalcon\Tests\AbstractUnitTestCase;

final class RenderHtmlTest extends AbstractUnitTestCase
{
    private const ERROR_DIV = "<div class='error-info'>";

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtml(): void
    {
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $debug->setShowBackTrace(false);

        $version = new Version();
        $versionString = $version->get();
        $link = $version->getPart(Version::VERSION_MAJOR)
                . "."
                . $version->getPart(Version::VERSION_MEDIUM);


        $expected = "<!DOCTYPE html>
<html lang='en'>
<head>
    <title>Phalcon\Support\Exception:exception message</title>
    <link href='https://assets.phalcon.io/debug/5.0.x/assets/jquery-ui/themes/ui-lightness/jquery-ui.min.css'
          rel='stylesheet'
          type='text/css' />
    <link href='https://assets.phalcon.io/debug/5.0.x/assets/jquery-ui/themes/ui-lightness/theme.css'
          rel='stylesheet'
          type='text/css' />
    <link href='https://assets.phalcon.io/debug/5.0.x/themes/default/style.css'
          rel='stylesheet'
          type='text/css' />
</head>
<body>
<div class='version'>
    Phalcon Framework <a href='https://docs.phalcon.io/$link/' target='_new'>$versionString</a>
</div>
<div align='center'>
    <div class='error-main'>
        <h1>Phalcon\Support\Exception: exception message</h1>
        <span class='error-file'>" . __FILE__ . " (31)</span>
    </div>
    <script type='application/javascript'
            src='https://assets.phalcon.io/debug/5.0.x/assets/jquery/dist/jquery.min.js'></script>
    <script type='application/javascript'
            src='https://assets.phalcon.io/debug/5.0.x/assets/jquery-ui/jquery-ui.min.js'></script>
    <script type='application/javascript'
            src='https://assets.phalcon.io/debug/5.0.x/assets/jquery.scrollTo/jquery.scrollTo.min.js'></script>
    <script type='application/javascript'
            src='https://assets.phalcon.io/debug/5.0.x/prettify/prettify.js'></script>
    <script type='application/javascript'
            src='https://assets.phalcon.io/debug/5.0.x/pretty.js'></script>
        </div>
    </body>
</html>";

        $actual = $debug->renderHtml($exception);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtmlFileFragment(): void
    {
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $debug->setShowBackTrace(true);
        $debug->setShowFileFragment(true);

        $actual = $debug->renderHtml($exception);

        $this->assertStringNotContainsString(
            'linenums error-scroll',
            $actual,
        );

        $this->assertStringContainsString('linenums:', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtmlNoFiles(): void
    {
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $debug->setShowBackTrace(true);
        $debug->setShowFiles(false);

        $actual = $debug->renderHtml($exception);

        $this->assertStringNotContainsString(
            'linenums error-scroll',
            $actual,
        );

        $this->assertStringNotContainsString('linenums:', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtmlWithBacktrace(): void
    {
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $debug->setShowBackTrace(true);
        $server = $_SERVER;
        $_SERVER['DATA_DEBUG_TEST'] = 'test';

        $actual = $debug->renderHtml($exception);

        $_SERVER = $server;

        $this->assertStringContainsString(self::ERROR_DIV, $actual);
        $this->assertStringContainsString(
            "<li><a href='#backtrace'>Backtrace</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#request'>Request</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#server'>Server</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#files'>Included Files</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#memory'>Memory</a></li>",
            $actual,
        );

        $this->assertStringContainsString('DATA_DEBUG_TEST', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtmlWithBacktraceAndBlacklist(): void
    {
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $server = $_SERVER;
        $_SERVER['DATA_DEBUG_TEST'] = 'test';

        $debug->setShowBackTrace(true);
        $debug->setBlacklist(
            [
                'server' => ['DATA_DEBUG_TEST'],
            ],
        );

        $actual = $debug->renderHtml($exception);
        $_SERVER = $server;

        $this->assertStringContainsString(self::ERROR_DIV, $actual);
        $this->assertStringContainsString(
            "<li><a href='#backtrace'>Backtrace</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#request'>Request</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#server'>Server</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#files'>Included Files</a></li>",
            $actual,
        );
        $this->assertStringContainsString(
            "<li><a href='#memory'>Memory</a></li>",
            $actual,
        );

        $this->assertStringNotContainsString('DATA_DEBUG_TEST', $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugRenderHtmlWithRequestBlacklist(): void
    {
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $request = $_REQUEST;
        $_REQUEST['DATA_REQUEST_TEST'] = 'test';

        $debug->setShowBackTrace(true);
        $debug->setBlacklist(
            [
                'request' => ['DATA_REQUEST_TEST'],
            ],
        );

        $actual = $debug->renderHtml($exception);
        $_REQUEST = $request;

        $this->assertStringContainsString(self::ERROR_DIV, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugRenderHtmlWithDebugVar(): void
    {
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $debug->setShowBackTrace(true);
        $debug->debugVar('my debug variable');

        $actual = $debug->renderHtml($exception);

        $this->assertStringContainsString("id='variables'", $actual);
    }
}
