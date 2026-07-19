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

namespace Phalcon\Tests\Unit\ADR\Responder\ChainResponder;

use Phalcon\ADR\Payload\Payload;
use Phalcon\ADR\Payload\Status;
use Phalcon\ADR\Responder\ChainResponder;
use Phalcon\ADR\Responder\StatusResponder;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\Responder\ChainResponder :: __invoke()
     */
    public function testAdrResponderChainResponderInvoke(): void
    {
        $chain   = new ChainResponder([new StatusResponder()]);
        $payload = (new Payload())->withStatus(Status::CREATED);

        $result = $chain(new Request(), new Response(), $payload);

        $this->assertSame(201, $result->getStatusCode());
    }
}
