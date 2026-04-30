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
 * Model used to verify that a TypeError from a strictly-typed setter during
 * ORM hydration does not propagate — the ORM must fall back to direct property
 * assignment instead.
 *
 * @see https://github.com/phalcon/cphalcon/issues/16956
 */
class InvoicesWithTypedSetters extends Invoices
{
    /**
     * Setter intentionally typed as ?array so that a raw string value coming
     * from the database triggers a TypeError, which the ORM must catch and
     * handle gracefully by falling back to direct property assignment.
     */
    public function setInvTitle(?array $data): void
    {
        $this->inv_title = implode(',', $data ?? []);
    }
}
