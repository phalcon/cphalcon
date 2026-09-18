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
 * Forces the Phalcon\Traits\Php\FileTrait::phpIsDir() wrapper to return false,
 * simulating the race where a different process makes the directory after the
 * test. The Phalcon\Traits\Php\FileTrait::phpMkdir() call that follows then
 * fails with "File exists". Used by test doubles that extend a class using
 * that trait.
 */
trait IsDirReturnsFalseTrait
{
    protected static function phpIsDir(string $filename): bool
    {
        return false;
    }
}
