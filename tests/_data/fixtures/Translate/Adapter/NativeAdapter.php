<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Translate\Adapter;

use Phalcon\Translate\Adapter\NativeArray;

class NativeAdapter extends NativeArray
{
    public function notFound(string $index): string
    {
        return '';
    }
}
