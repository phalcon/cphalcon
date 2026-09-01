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

use Phalcon\Contracts\Events\Stoppable;

class StoppableEvent implements Stoppable
{
    private bool $stopped = false;

    public function isPropagationStopped(): bool
    {
        return $this->stopped;
    }

    public function stop(): void
    {
        $this->stopped = true;
    }
}
