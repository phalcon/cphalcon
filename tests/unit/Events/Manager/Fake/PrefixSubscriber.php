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

namespace Phalcon\Tests\Unit\Events\Manager\Fake;

use Phalcon\Contracts\Events\Subscriber;

/**
 * Subscribes to the bare prefix "db" to catch every "db:*" fire - exercises
 * the manager's existing two-level dispatch (prefix queue + full-name queue).
 */
class PrefixSubscriber implements Subscriber
{
    public array $events = [];

    public static function getSubscribedEvents(): array
    {
        return [
            'db' => 'onAnyDbEvent',
        ];
    }

    public function onAnyDbEvent($event, $source, $data): void
    {
        $this->events[] = $event->getType();
    }
}
