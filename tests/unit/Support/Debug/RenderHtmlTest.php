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
use PHPUnit\Framework\Attributes\BackupGlobals;

#[BackupGlobals(true)]
final class RenderHtmlTest extends AbstractUnitTestCase
{
    private const TABS = "<div class='tabs' role='tablist'>";

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtml(): void
    {
        $exception = new Exception('exception message', 1234);
        $file      = $exception->getFile();
        $line      = (string)$exception->getLine();

        $debug = new Debug();
        $debug->setShowBackTrace(false);

        $version       = new Version();
        $versionString = $version->get();
        $link          = "https://docs.phalcon.io/"
            . $version->getPart(Version::VERSION_MAJOR) . "."
            . $version->getPart(Version::VERSION_MEDIUM) . "/";
        $uri           = "https://assets.phalcon.io/debug/5.0.x/";
        $php           = PHP_VERSION;
        $logo          = "https://assets.phalcon.io/phalcon/images/svg/logo--tablet.svg";

        $expected = "<!DOCTYPE html>
<html lang='en' data-theme='light'>
<head>
    <meta charset='utf-8'>
    <meta name='viewport' content='width=device-width, initial-scale=1'>
    <title>Phalcon\Support\Exception:exception message</title>
    <link href='{$uri}debug.css'
          rel='stylesheet'
          type='text/css' />
</head>
<body>
<div class='wrap'>
    <div class='masthead'>
        <div class='brand'><img class='logo' src='{$logo}' alt='Phalcon' /><span>Phalcon Debug</span></div>
        <div class='actions-top'>
            <button class='btn' data-action='copy-trace'>Copy trace</button>
            <button class='btn' data-action='toggle-theme' title='Toggle theme'>Theme</button>
            <a class='version-badge' href='{$link}' target='_new'><b>v{$versionString}</b></a>
        </div>
    </div>
    <div class='error-card'>
        <span class='error-type'>Phalcon\Support\Exception</span>
        <h1 class='error-message'>exception message</h1>
        <div class='meta'>
            <span class='item'><code>{$file}</code> : <code>{$line}</code></span>
            <span class='sep'>|</span><span class='item'>PHP <code>{$php}</code></span>
        </div>
    </div>
</div>
    <script src='{$uri}debug.js'></script>
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

        $this->assertStringContainsString("<div class='code'>", $actual);
        $this->assertStringContainsString("<tr class='hl'>", $actual);
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

        $this->assertStringNotContainsString("<div class='code'>", $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtmlWithBacktrace(): void
    {
        $key = uniqid('var-');
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $debug->setShowBackTrace(true);
        $server = $_SERVER;
        $_SERVER[$key] = uniqid('val-');

        $actual = $debug->renderHtml($exception);

        $_SERVER = $server;

        $this->assertStringContainsString(self::TABS, $actual);
        $this->assertStringContainsString("data-tab='backtrace'", $actual);
        $this->assertStringContainsString("data-tab='request'", $actual);
        $this->assertStringContainsString("data-tab='server'", $actual);
        $this->assertStringContainsString("data-tab='files'", $actual);
        $this->assertStringContainsString("data-tab='memory'", $actual);

        $this->assertStringContainsString($key, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportDebugRenderHtmlWithBacktraceAndBlacklist(): void
    {
        $key = uniqid('var-');
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $server = $_SERVER;
        $_SERVER[$key] = uniqid('val-');

        $debug->setShowBackTrace(true);
        $debug->setBlacklist(
            [
                'server' => [$key],
            ],
        );

        $actual = $debug->renderHtml($exception);
        $_SERVER = $server;

        $this->assertStringContainsString(self::TABS, $actual);
        $this->assertStringContainsString("data-tab='server'", $actual);
        $this->assertStringNotContainsString($key, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugRenderHtmlWithRequestBlacklist(): void
    {
        $key = uniqid('var-');
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $request = $_REQUEST;
        $_REQUEST[$key] = uniqid('val-');

        $debug->setShowBackTrace(true);
        $debug->setBlacklist(
            [
                'request' => [$key],
            ],
        );

        $actual = $debug->renderHtml($exception);
        $_REQUEST = $request;

        $this->assertStringContainsString(self::TABS, $actual);
        $this->assertStringNotContainsString($key, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-11
     */
    public function testSupportDebugRenderHtmlWithDebugVar(): void
    {
        $value = uniqid('var-');
        $exception = new Exception('exception message', 1234);
        $debug = new Debug();
        $debug->setShowBackTrace(true);
        $debug->debugVar($value);

        $actual = $debug->renderHtml($exception);

        $this->assertStringContainsString("id='variables'", $actual);
        $this->assertStringContainsString($value, $actual);
    }
}
