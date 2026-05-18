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

namespace Phalcon\Tests\Unit\Di;

use Phalcon\Di\Di;
use Phalcon\Html\Escaper;
use Phalcon\Tests\AbstractUnitTestCase;

final class RemoveSharedTest extends AbstractUnitTestCase
{
    /**
     * removeShared() drops the cached instance but leaves the service
     * definition intact so the next getShared() resolves a brand-new
     * instance.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13440
     */
    public function testDiRemoveSharedDropsCachedInstanceOnly(): void
    {
        $container = new Di();
        $container->setShared('escaper', Escaper::class);

        $first = $container->getShared('escaper');
        $this->assertTrue($container->hasShared('escaper'));
        $this->assertTrue($container->has('escaper'));

        $container->removeShared('escaper');

        // Cached instance is gone...
        $this->assertFalse($container->hasShared('escaper'));
        // ...but the service definition remains.
        $this->assertTrue($container->has('escaper'));

        // Next resolution yields a brand-new instance.
        $second = $container->getShared('escaper');
        $this->assertNotSame($first, $second);
        $this->assertTrue($container->hasShared('escaper'));
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13440
     */
    public function testDiRemoveSharedIsNoOpForUnknownService(): void
    {
        $container = new Di();

        // Must not throw, must not register anything.
        $container->removeShared('unknown');

        $this->assertFalse($container->has('unknown'));
        $this->assertFalse($container->hasShared('unknown'));
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13440
     */
    public function testDiRemoveSharedResolvesAlias(): void
    {
        $container = new Di();
        $container->setShared('escaper', Escaper::class);
        $container->setAlias('escaper', 'safe');
        $container->getShared('escaper');

        $this->assertTrue($container->hasShared('safe'));

        $container->removeShared('safe');

        $this->assertFalse($container->hasShared('escaper'));
        // Service definition still registered.
        $this->assertTrue($container->has('escaper'));
    }
}
