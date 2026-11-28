<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Di;

/**
 * A service with methods that the `calls` of a definition cannot call.
 */
class CallsComponent
{
    /**
     * @var array<int, string>
     */
    public array $log = [];

    public function first(): void
    {
        $this->log[] = 'first';
    }

    protected function guarded(): void
    {
        $this->log[] = 'guarded';
    }

    private function hidden(): void
    {
        $this->log[] = 'hidden';
    }
}
