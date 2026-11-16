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

namespace Phalcon\Tests\Unit\Cli\Router;

use Phalcon\Cli\Router;
use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault\Cli as CliFactoryDefault;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;

/**
 * The CLI router calls the converters with the PHP weak type rules, the same
 * as cphalcon. The test file declares strict_types=1, so the mode of the
 * caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testCliRouterWeakModeConvert(): void
    {
        $router = new Router(false);
        $router->setDI(new CliFactoryDefault());
        $router
            ->add(
                'x {id}',
                [
                    'task'   => 'main',
                    'action' => 'main',
                ]
            )
            ->convert('id', [IntTarget::class, 'double'])
        ;

        $router->handle('x 5');

        $this->assertSame(10, $router->getParams()['id']);
    }
}
