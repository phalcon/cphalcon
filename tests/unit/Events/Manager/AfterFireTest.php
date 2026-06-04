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

namespace Phalcon\Tests\Unit\Events\Manager;

use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Events\Fake\DeferredManager;
use stdClass;

final class AfterFireTest extends AbstractUnitTestCase
{
    public function testAfterFireCalledAfterDispatch(): void
    {
        $manager = new DeferredManager();
        $source  = new stdClass();
        $data    = ['key' => 'value'];

        $manager->attach(
            'test:event',
            function () {
                return 'handled';
            }
        );

        $result = $manager->fire('test:event', $source, $data);

        $expected = [['handled', 'test:event', $source, $data, true]];
        $this->assertSame($expected, $manager->afterCalls);
        $this->assertSame('handled', $result);
    }

    public function testAfterFireCanTransformResult(): void
    {
        $manager                = new DeferredManager();
        $manager->rewriteResult = true;

        $manager->attach(
            'test:event',
            function () {
                return 'handled';
            }
        );

        $result = $manager->fire('test:event', new stdClass());

        $this->assertSame('rewritten', $result);
    }

    public function testAfterFireNotCalledWhenHalted(): void
    {
        $manager = new DeferredManager();

        $manager->attach(
            'test:event',
            function () {
                return 'handled';
            }
        );

        $manager->halt();
        $manager->fire('test:event', new stdClass());

        $this->assertCount(0, $manager->afterCalls);
    }

    public function testAfterFireNotCalledWithoutListeners(): void
    {
        $manager = new DeferredManager();

        $manager->fire('test:event', new stdClass());

        $this->assertCount(0, $manager->afterCalls);
    }
}
