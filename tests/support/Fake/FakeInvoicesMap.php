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

use Phalcon\Tests\Support\Models\InvoicesMap;

/**
 * InvoicesMap that returns an invalid column map, so the metadata strategy
 * raises its exception.
 */
final class FakeInvoicesMap extends InvoicesMap
{
    public function columnMap()
    {
        return false;
    }
}
