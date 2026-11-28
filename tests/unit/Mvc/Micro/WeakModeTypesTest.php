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

namespace Phalcon\Tests\Unit\Mvc\Micro;

use Phalcon\Di\Di;
use Phalcon\Di\FactoryDefault;
use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\Collection;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use Phalcon\Tests\Support\WeakTypes\IntTarget;

/**
 * The micro application calls the route handlers with the PHP weak type
 * rules, the same as cphalcon. The test file declares strict_types=1, so the
 * mode of the caller has no effect.
 */
final class WeakModeTypesTest extends AbstractUnitTestCase
{
    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * The route parameter is a string. The handler takes an int.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testMvcMicroWeakModeHandler(): void
    {
        $micro = new Micro(new FactoryDefault());
        $micro->get(
            '/x/{id}',
            function (int $id): int {
                return $id;
            }
        );

        $this->assertSame(5, $micro->handle('/x/5'));
    }

    /**
     * The route parameter is a string. The lazy handler method takes an int.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/805
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-14
     */
    public function testMvcMicroWeakModeLazyHandler(): void
    {
        $collection = new Collection();
        $collection->setHandler(IntTarget::class, true);
        $collection->get('/x/{id}', 'showAction');

        $micro = new Micro(new FactoryDefault());
        $micro->mount($collection);

        $this->assertSame(5, $micro->handle('/x/5'));
    }
}
