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

class InvalidSubscriber implements Subscriber
{
    public static function getSubscribedEvents(): array
    {
        return [
            // Not a string and not an array.
            'test:broken' => 42,
        ];
    }
}
