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

namespace Phalcon\Tests\Support\Filter;

use Phalcon\Filter\Filter;

/**
 * Gives access to the protected init() method
 */
final class InitFilter extends Filter
{
    /**
     * @param array<array-key, mixed> $mapper
     */
    public function reinit(array $mapper): void
    {
        $this->init($mapper);
    }
}
