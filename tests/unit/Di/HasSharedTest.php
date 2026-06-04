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

final class HasSharedTest extends AbstractUnitTestCase
{
    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13440
     */
    public function testDiHasSharedReturnsFalseWhenServiceUnknown(): void
    {
        $container = new Di();

        $this->assertFalse($container->hasShared('unknown'));
    }

    /**
     * Registering a service does NOT populate the shared-instance cache -
     * resolution happens lazily on the first getShared() call.
     *
     * @issue https://github.com/phalcon/cphalcon/issues/13440
     */
    public function testDiHasSharedReturnsFalseUntilServiceResolved(): void
    {
        $container = new Di();
        $container->setShared('escaper', Escaper::class);

        $this->assertFalse($container->hasShared('escaper'));

        $container->getShared('escaper');

        $this->assertTrue($container->hasShared('escaper'));
    }

    /**
     * @issue https://github.com/phalcon/cphalcon/issues/13440
     */
    public function testDiHasSharedResolvesAlias(): void
    {
        $container = new Di();
        $container->setShared('escaper', Escaper::class);
        $container->setAlias('escaper', 'safe');

        $container->getShared('escaper');

        $this->assertTrue($container->hasShared('safe'));
    }
}
