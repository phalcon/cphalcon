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

namespace Phalcon\Tests\Support\Mvc\View;

/**
 * A Volt extension with an event method that the compiler cannot call.
 */
class VoltPrivateExtension
{
    private function compileFunction(): string
    {
        return 'private';
    }
}
