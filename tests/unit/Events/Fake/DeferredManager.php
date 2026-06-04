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

namespace Phalcon\Tests\Unit\Events\Fake;

use Phalcon\Events\Manager;

/**
 * Manager subclass used to exercise the beforeFire()/afterFire() seams.
 */
class DeferredManager extends Manager
{
    public array $afterCalls    = [];
    public array $beforeCalls   = [];
    public bool $defer         = false;
    public bool $rewriteResult = false;

    protected function afterFire(
        mixed $status,
        string $eventType,
        mixed $source,
        mixed $data = null,
        bool $cancelable = true
    ): mixed {
        $this->afterCalls[] = [$status, $eventType, $source, $data, $cancelable];

        if ($this->rewriteResult) {
            return 'rewritten';
        }

        return $status;
    }

    protected function beforeFire(
        string $eventType,
        mixed $source,
        mixed $data = null,
        bool $cancelable = true
    ): bool {
        $this->beforeCalls[] = [$eventType, $source, $data, $cancelable];

        return !$this->defer;
    }
}
