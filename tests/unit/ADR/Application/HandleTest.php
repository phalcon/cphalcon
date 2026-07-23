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

namespace Phalcon\Tests\Unit\ADR\Application;

use Phalcon\ADR\Application;
use Phalcon\ADR\Container\AdrProvider;
use Phalcon\Container\ContainerFactory;
use Phalcon\Http\Request;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class HandleTest extends AbstractUnitTestCase
{
    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() dispatches the matched action with its attributes
     */
    public function testAdrApplicationHandleDispatchesMatchedAction(): void
    {
        $_SERVER['REQUEST_URI']    = '/hello/world';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = $this->application()
                    ->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action');

        $response = $app->handle(new Request());

        $this->assertSame('hello world', $response->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() routes a missing route through the error responder
     */
    public function testAdrApplicationHandleRoutesRouteNotFound(): void
    {
        $_SERVER['REQUEST_URI']    = '/nope';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = $this->application()
                    ->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action');

        $response = $app->handle(new Request());

        $this->assertSame(404, $response->getStatusCode());
    }

    private function application(): Application
    {
        $container = (new ContainerFactory())
            ->addProvider(new AdrProvider())
            ->newContainer();

        return new Application($container);
    }
}
