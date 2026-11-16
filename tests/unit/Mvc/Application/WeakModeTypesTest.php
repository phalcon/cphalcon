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

namespace Phalcon\Tests\Unit\Mvc\Application;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Application;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

/**
 * The application calls the match callback of a route with the PHP weak
 * type rules, the same as cphalcon. The test file declares strict_types=1,
 * so the mode of the caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * The route parameter has a string key, so it goes to the callback as a
     * named argument.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testMvcApplicationWeakModeMatch(): void
    {
        $result    = null;
        $container = new FactoryDefault();
        $container
            ->getShared('router')
            ->add('/x/{id}')
            ->match(
                function (int $id) use (&$result) {
                    $result = $id;

                    return 'ok';
                }
            )
        ;

        (new Application($container))->handle('/x/5');

        $this->assertSame(5, $result);
    }
}
