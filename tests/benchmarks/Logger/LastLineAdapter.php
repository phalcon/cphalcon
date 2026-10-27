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

namespace Phalcon\Tests\Benchmarks\Logger;

use Phalcon\Logger\Adapter\AbstractAdapter;
use Phalcon\Logger\Item;

/**
 * A logger adapter with no I/O. It keeps the last formatted line, so the
 * subjects can check it.
 */
final class LastLineAdapter extends AbstractAdapter
{
    public string $last = '';

    public function close(): bool
    {
        return true;
    }

    public function process(Item $item): void
    {
        $this->last = $this->getFormattedItem($item);
    }
}
