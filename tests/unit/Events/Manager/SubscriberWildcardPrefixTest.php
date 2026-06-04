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
use Phalcon\Tests\Unit\Events\Manager\Fake\PrefixSubscriber;

final class SubscriberWildcardPrefixTest extends AbstractUnitTestCase
{
    /**
     * Subscribing to the bare prefix ("db") must catch every "db:*" fire
     * because Manager::fire dispatches both the prefix queue and the
     * full-name queue. This is Phalcon's wildcard mechanism - no new syntax
     * is needed in the Subscriber contract.
     */
    public function testPrefixKeyCatchesEveryNamespacedEvent(): void
    {
        $manager          = new Manager();
        $prefixSubscriber = new PrefixSubscriber();

        $manager->addSubscriber($prefixSubscriber);

        $manager->fire('db:beforeQuery', $this);
        $manager->fire('db:afterQuery', $this);
        $manager->fire('db:afterFetch', $this);

        $this->assertSame(
            ['beforeQuery', 'afterQuery', 'afterFetch'],
            $prefixSubscriber->events
        );
    }

    public function testPrefixKeyIgnoresUnrelatedEvents(): void
    {
        $manager          = new Manager();
        $prefixSubscriber = new PrefixSubscriber();

        $manager->addSubscriber($prefixSubscriber);

        $manager->fire('view:beforeRender', $this);

        $this->assertSame([], $prefixSubscriber->events);
    }
}
