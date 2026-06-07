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

/**
 * Invokable object listener. attach() classifies it as a generic callable
 * (type 3); the dispatch loop calls it via __invoke.
 */
class InvokableListener
{
    public array $calls = [];

    public function __invoke(object $event): void
    {
        $this->calls[] = '__invoke';
    }
}
