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

namespace Phalcon\Tests\Unit\Support\Fake;

use Phalcon\Support\Collection;

final class FakeCollectionPhpJsonEncode extends Collection
{
    protected function phpJsonEncode(
        mixed $value,
        int $flags = 0,
        int $depth = 512,
    ): false | string {
        return false;
    }
}
