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
use Phalcon\Tests\Unit\Events\Manager\Fake\MultiListenerSubscriber;
use Phalcon\Tests\Unit\Events\Manager\Fake\SimpleSubscriber;

final class ClearSubscribersTest extends AbstractUnitTestCase
{
    public function testClearSubscribersDetachesAllAndEmptiesList(): void
    {
        $manager          = new Manager();
        $simpleSubscriber = new SimpleSubscriber();
        $multiSubscriber  = new MultiListenerSubscriber();

        $manager->addSubscriber($simpleSubscriber);
        $manager->addSubscriber($multiSubscriber);

        $this->assertCount(1, $manager->getListeners('test:hello'));
        $this->assertCount(3, $manager->getListeners('test:multi'));
        $this->assertCount(2, $manager->getSubscribers());

        $manager->clearSubscribers();

        $this->assertSame([], $manager->getSubscribers());
        $this->assertCount(0, $manager->getListeners('test:hello'));
        $this->assertCount(0, $manager->getListeners('test:multi'));
    }

    public function testClearSubscribersDoesNotTouchAttachListeners(): void
    {
        $manager      = new Manager();
        $closureHit   = false;
        $plainClosure = function () use (&$closureHit) {
            $closureHit = true;
        };

        $manager->attach('plain:event', $plainClosure);
        $manager->addSubscriber(new SimpleSubscriber());

        $manager->clearSubscribers();

        $manager->fire('plain:event', $this);

        $this->assertTrue(
            $closureHit,
            'clearSubscribers must not detach listeners attached via attach()'
        );
    }
}
