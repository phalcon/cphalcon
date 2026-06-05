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

class MultiListenerSubscriber implements Subscriber
{
    public array $calls = [];

    public static function getSubscribedEvents(): array
    {
        return [
            'test:multi' => [
                ['first'],
                ['second', 250],
                ['third', 50],
            ],
        ];
    }

    public function first($event, $source, $data): void
    {
        $this->calls[] = 'first';
    }

    public function second($event, $source, $data): void
    {
        $this->calls[] = 'second';
    }

    public function third($event, $source, $data): void
    {
        $this->calls[] = 'third';
    }
}
