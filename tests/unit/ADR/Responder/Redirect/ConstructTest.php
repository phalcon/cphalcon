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

namespace Phalcon\Tests\Unit\ADR\Responder\Redirect;

use Phalcon\ADR\Responder\Redirect;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ConstructTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\Redirect :: url()/status()
     */
    public function testAdrResponderRedirectConstruct(): void
    {
        $redirect = new Redirect('/home', 301);

        $this->assertSame('/home', $redirect->url());
        $this->assertSame(301, $redirect->status());

        $this->assertSame(302, (new Redirect('/x'))->status());
    }

    /**
     * Unit Tests Phalcon\ADR\Responder\Redirect :: external()
     *
     * A redirect is internal unless the flag is passed, so a request-derived
     * target cannot become an open redirect (CWE-601).
     */
    public function testAdrResponderRedirectConstructExternal(): void
    {
        $this->assertFalse((new Redirect('/home'))->external());
        $this->assertFalse((new Redirect('/home', 301))->external());
        $this->assertFalse((new Redirect('/home', 301, false))->external());

        $this->assertTrue(
            (new Redirect('https://example.com', 302, true))->external()
        );
    }
}
