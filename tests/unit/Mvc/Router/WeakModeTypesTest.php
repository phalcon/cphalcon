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

use Error;
use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Router;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;
use Throwable;
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
     * A converter that cannot be called, on both paths, for a matched part
     * (id) and a part that is not matched (action), and the cphalcon message.
     *
     * @return array<string, array{0: bool, 1: string, 2: mixed, 3: string}>
     */
    public static function getNotCallableConverters(): array
    {
        $values = [
            'string' => ['nope', 'Call to undefined function nope()'],
            'array'  => [[new stdClass(), 'missing'], 'Call to undefined method stdClass::missing()'],
            'object' => [new stdClass(), 'Call to undefined function undefined()'],
            'int'    => [5, 'Call to undefined function undefined()'],
        ];

        $examples = [];
        foreach (self::getRouterPaths() as $pathName => [$withEvents]) {
            foreach (['matched' => 'id', 'not matched' => 'action'] as $partName => $part) {
                foreach ($values as $valueName => [$converter, $message]) {
                    $examples[$pathName . ', ' . $partName . ', ' . $valueName] = [
                        $withEvents,
                        $part,
                        $converter,
                        $message,
                    ];
                }
            }
        }

        return $examples;
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
     * A converter that cannot be called throws Error with the cphalcon
     * message.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/817
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-16
     */
    #[DataProvider('getNotCallableConverters')]
    public function testMvcRouterConvertNotCallable(
        bool $withEvents,
        string $part,
        mixed $converter,
        string $expected
    ): void {
        $router = $this->getRouter($withEvents, $part, $converter);

        $actual = null;
        try {
            $router->handle('/x/5');
        } catch (Throwable $ex) {
            $actual = [$ex::class, $ex->getMessage()];
        }

        $this->assertSame([Error::class, $expected], $actual);
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

    private function getRouter(
        bool $withEvents,
        string $part = 'id',
        mixed $converter = [IntTarget::class, 'double']
    ): Router {
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
            ->convert($part, $converter)
        ;

        return $router;
    }
}
