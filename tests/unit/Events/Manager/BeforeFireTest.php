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

use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Unit\Events\Fake\DeferredManager;
use ReflectionMethod;
use stdClass;

final class BeforeFireTest extends AbstractUnitTestCase
{
    public function testBeforeFireFalseAbortsDispatch(): void
    {
        $manager        = new DeferredManager();
        $manager->defer = true;
        $invoked        = false;

        $manager->attach(
            'test:event',
            function () use (&$invoked) {
                $invoked = true;

                return 'handled';
            }
        );

        $result = $manager->fire('test:event', new stdClass());

        $this->assertFalse($invoked);
        $this->assertNull($result);
        $this->assertCount(1, $manager->beforeCalls);
    }
    public function testBeforeFireReceivesArguments(): void
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

        $manager->fire('test:event', $source, $data);

        $expected = [['test:event', $source, $data, true]];
        $this->assertSame($expected, $manager->beforeCalls);
    }

    public function testBeforeFireRunsWithoutListeners(): void
    {
        $manager = new DeferredManager();

        $manager->fire('test:event', new stdClass());

        $this->assertCount(1, $manager->beforeCalls);
    }

    public function testFireIsNotFinal(): void
    {
        $method = new ReflectionMethod(Manager::class, 'fire');

        $this->assertFalse($method->isFinal());
    }
}
