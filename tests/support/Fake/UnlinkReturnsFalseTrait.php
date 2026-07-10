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

namespace Phalcon\Tests\Support\Fake;

/**
 * Forces the Phalcon\Traits\Php\FileTrait::phpUnlink() wrapper to return false,
 * simulating a failure to delete the file. Used by test doubles that extend a
 * class using that trait.
 */
trait UnlinkReturnsFalseTrait
{
    protected static function phpUnlink(string $filename, $context = null): bool
    {
        return false;
    }
}
