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

namespace Phalcon\Tests\Support\Support\Dump;

/**
 * Fixture with a parent, a constructor and a method, used to exercise the
 * "extends", "constructor" and "already listed" branches of Dump.
 */
class SampleMethods extends ClassProperties
{
    public function __construct()
    {
    }

    public function sample(): void
    {
    }
}
