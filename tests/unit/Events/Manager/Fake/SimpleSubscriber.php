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

class SimpleSubscriber implements Subscriber
{
    public array $calls = [];

    public static function getSubscribedEvents(): array
    {
        return [
            'test:hello' => 'onHello',
        ];
    }

    public function onHello($event, $source, $data): void
    {
        $this->calls[] = 'hello';
    }
}
