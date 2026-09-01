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
    private const DIRECTORY = PATH_SUPPORT . 'ADR/Action';

    protected function tearDown(): void
    {
        unset($_SERVER['REQUEST_URI'], $_SERVER['REQUEST_METHOD']);

        parent::tearDown();
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() validates and casts declared parameters
     */
    public function testAdrApplicationHandleCastsDeclaredParameters(): void
    {
        $_SERVER['REQUEST_URI']    = '/user/42';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = $this->application()
                    ->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action')
                    ->setActionDirectory(self::DIRECTORY);

        $response = $app->handle(new Request());

        $this->assertSame('integer:42', $response->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() clears the attributes of a reused request
     */
    public function testAdrApplicationHandleClearsAttributesOfReusedRequest(): void
    {
        $_SERVER['REQUEST_URI']    = '/user/42';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = $this->application()
                    ->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action')
                    ->setActionDirectory(self::DIRECTORY);

        $request = new Request();

        $app->handle($request);
        $this->assertSame(['id' => 42], $request->getAttributes()->all());

        $_SERVER['REQUEST_URI'] = '/hello/world';

        $app->handle($request);
        $this->assertSame([0 => 'world'], $request->getAttributes()->all());
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() dispatches the matched action with its attributes
     */
    public function testAdrApplicationHandleDispatchesMatchedAction(): void
    {
        $_SERVER['REQUEST_URI']    = '/hello/world';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = $this->application()
                    ->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action')
                    ->setActionDirectory(self::DIRECTORY);

        $response = $app->handle(new Request());

        $this->assertSame('hello world', $response->getContent());
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() 404s when a parameter fails its regex
     */
    public function testAdrApplicationHandleRejectsInvalidParameter(): void
    {
        $_SERVER['REQUEST_URI']    = '/user/abc';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = $this->application()
                    ->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action')
                    ->setActionDirectory(self::DIRECTORY);

        $response = $app->handle(new Request());

        $this->assertSame(404, $response->getStatusCode());
    }

    /**
     * Unit Tests Phalcon\ADR\Application :: handle() routes a missing route through the error responder
     */
    public function testAdrApplicationHandleRoutesRouteNotFound(): void
    {
        $_SERVER['REQUEST_URI']    = '/nope';
        $_SERVER['REQUEST_METHOD'] = 'GET';

        $app = $this->application()
                    ->setBaseNamespace('Phalcon\\Tests\\Support\\ADR\\Action')
                    ->setActionDirectory(self::DIRECTORY);

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
