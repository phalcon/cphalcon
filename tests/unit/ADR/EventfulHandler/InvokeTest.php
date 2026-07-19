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

namespace Phalcon\Tests\Unit\ADR\EventfulHandler;

use Phalcon\ADR\EventfulHandler;
use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Events\Manager;
use Phalcon\Http\Request;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class InvokeTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\ADR\EventfulHandler :: __invoke() fires the adr events
     */
    public function testAdrEventfulHandlerInvokeFiresEvents(): void
    {
        $action = new class implements Action {
            public function __invoke(AttributeRequest $request): ResponseInterface
            {
                return new Response();
            }
        };

        $manager = new Manager();
        $count   = 0;
        $manager->attach(
            'adr',
            function () use (&$count) {
                $count++;
            }
        );

        (new EventfulHandler($action, $manager))(new Request());

        $this->assertSame(2, $count);
    }
}
