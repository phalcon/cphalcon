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
 * Forces the Phalcon\Traits\Php\FileTrait::phpFileGetContents() wrapper to
 * return false, simulating a filesystem read failure. Used by test doubles
 * that extend a class using that trait.
 */
trait FileGetContentsReturnsFalseTrait
{
    protected static function phpFileGetContents(
        string $filename,
        bool $useIncludePath = false,
        $context = null,
        int $offset = 0,
        ?int $length = null
    ): false|string {
        return false;
    }
}
