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

namespace Phalcon\Tests\Unit\Storage\Fake;

/**
 * Canary for deserialization tests. `__wakeup()` records that the object was
 * instantiated by unserialize(), so a test can prove a sink refuses to build it.
 */
final class WakeupCanary
{
    public static bool $fired = false;

    public function __wakeup(): void
    {
        self::$fired = true;
    }
}
