<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Mvc\Router;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Router;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;
use PHPUnit\Framework\Attributes\DataProvider;
use TypeError;

/**
 * The router calls the converters with the PHP weak type rules, the same as
 * cphalcon. The test file declares strict_types=1, so the mode of the caller
 * has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * Without an events manager, the router uses the combined regex. With an
     * events manager, it checks each route.
     *
     * @return array<string, array{0: bool}>
     */
    public static function getRouterPaths(): array
    {
        return [
            'combined'  => [false],
            'per route' => [true],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[DataProvider('getRouterPaths')]
    public function testMvcRouterWeakModeConvert(bool $withEvents): void
    {
        $router = $this->getRouter($withEvents);
        $router->handle('/x/5');

        $this->assertSame(10, $router->getParams()['id']);
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    #[DataProvider('getRouterPaths')]
    public function testMvcRouterWeakModeConvertRefused(bool $withEvents): void
    {
        $this->expectException(TypeError::class);

        $this->getRouter($withEvents)->handle('/x/abc');
    }

    private function getRouter(bool $withEvents): Router
    {
        $router = new Router(false);
        $router->setDI(new FactoryDefault());

        if ($withEvents) {
            $router->setEventsManager(new Manager());
        }

        $router
            ->add(
                '/x/{id}',
                [
                    'controller' => 'c',
                    'action'     => 'a',
                ]
            )
            ->convert('id', [IntTarget::class, 'double'])
        ;

        return $router;
    }
}
