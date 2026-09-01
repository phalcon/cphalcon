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
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class RenderHtmlEscapeKeyTest extends AbstractUnitTestCase
{
    /**
     * A nested array key from a superglobal must be escaped on the exception
     * page (reflected XSS via e.g. ?x[<img onerror=...>]=1).
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-23
     */
    public function testRenderHtmlEscapesNestedRequestArrayKey(): void
    {
        $server          = $_SERVER;
        $_SERVER['xkey'] = ['<img src=x onerror=alert(1)>' => 'v'];

        $debug = new Debug();
        $debug->setShowBackTrace(true);

        $html = $debug->renderHtml(new Exception('boom', 1));

        $_SERVER = $server;

        $this->assertStringNotContainsString(
            '<img src=x onerror=alert(1)>',
            $html
        );
    }
}
