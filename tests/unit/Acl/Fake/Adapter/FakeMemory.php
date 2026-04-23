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

namespace Phalcon\Tests\Unit\Acl\Fake\Adapter;

use Phalcon\Acl\Adapter\Memory;

final class FakeMemory extends Memory
{
    /**
     * Overrides fireManagerEvent to always return false, used for testing
     * when an event manager vetoes an action.
     *
     * @param string $eventName
     * @param mixed  $data
     * @param bool   $cancellable
     *
     * @return bool|mixed|null
     */
    protected function fireManagerEvent(
        string $eventName,
        mixed $data = null,
        bool $cancellable = true
    ): mixed {
        return false;
    }
}
