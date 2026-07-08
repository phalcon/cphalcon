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

namespace Phalcon\Tests\Unit\Assets\Fake;

use Phalcon\Assets\Collection;

class FakeCollectionFileExists extends Collection
{
    /**
     * @param string $filename
     *
     * @return bool
     *
     * @link https://php.net/manual/en/function.file-exists.php
     */
    protected static function phpFileExists(string $filename): bool
    {
        return false;
    }
}
