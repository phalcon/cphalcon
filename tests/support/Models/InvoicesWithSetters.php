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

namespace Phalcon\Tests\Support\Models;

/**
 * Model used to verify that setters are called during ORM hydration
 * (cloneResultMap / findFirst etc.).
 *
 * @see https://github.com/phalcon/cphalcon/issues/14810
 */
class InvoicesWithSetters extends Invoices
{
    public function setInvTitle(?string $title): void
    {
        $this->inv_title = 'SET:' . $title;
    }

    public function setInvTotal(?float $total): void
    {
        $this->inv_total = $total !== null ? $total * 2 : null;
    }
}