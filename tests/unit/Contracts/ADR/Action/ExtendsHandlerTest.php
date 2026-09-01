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

namespace Phalcon\Tests\Unit\Contracts\ADR\Action;

use Phalcon\Contracts\ADR\Action;
use Phalcon\Contracts\ADR\Handler;
use Phalcon\Contracts\Http\AttributeRequest;
use Phalcon\Http\Response;
use Phalcon\Http\ResponseInterface;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class ExtendsHandlerTest extends AbstractUnitTestCase
{
    /**
     * Unit Tests Phalcon\Contracts\ADR\Action :: extends Handler
     */
    public function testContractsAdrActionExtendsHandler(): void
    {
        $this->assertTrue(is_subclass_of(Action::class, Handler::class));

        $action = new class implements Action {
            public function __invoke(AttributeRequest $request): ResponseInterface
            {
                return new Response();
            }
        };

        $this->assertInstanceOf(Handler::class, $action);
        $this->assertInstanceOf(Action::class, $action);
    }
}
