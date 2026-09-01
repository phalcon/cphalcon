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

namespace Phalcon\Tests\Unit\ADR\Responder\RedirectResponder;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Responder\Redirect;
use Phalcon\ADR\Responder\RedirectResponder;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * An explicit external redirect opts out of the gate.
     */
    public function testAdrResponderRedirectResponderAllowsExplicitExternal(): void
    {
        $responder = new RedirectResponder();
        $payload   = (new Payload())->withResult(
            new Redirect('https://payments.example.com', 303, true)
        );

        $result = $responder(new Request(), new Response(), $payload);

        $this->assertSame(
            'https://payments.example.com',
            $result->getHeaders()->get('Location')
        );
    }

    /**
     * An internal redirect must refuse a protocol-relative or absolute target
     * so a request-derived value cannot become an open redirect (CWE-601).
     */
    public function testAdrResponderRedirectResponderBlocksOpenRedirect(): void
    {
        $responder = new RedirectResponder();

        foreach (['//evil.tld', 'http://evil.tld/x', 'javascript:alert(1)'] as $target) {
            $payload = (new Payload())->withResult(new Redirect($target));
            $result  = $responder(new Request(), new Response(), $payload);

            $this->assertSame('/', $result->getHeaders()->get('Location'));
        }
    }
    /**
     * Unit Tests Phalcon\ADR\Responder\RedirectResponder :: __invoke()
     */
    public function testAdrResponderRedirectResponderInvoke(): void
    {
        $responder = new RedirectResponder();
        $payload   = (new Payload())->withResult(new Redirect('/login', 303));

        $result = $responder(new Request(), new Response(), $payload);

        $this->assertSame(303, $result->getStatusCode());
        $this->assertSame('/login', $result->getHeaders()->get('Location'));
    }
}
