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

use Phalcon\Mvc\Model;

/**
 * Model used to test serialization and toArray() with PHP typed properties.
 *
 * The inv_id column is NOT NULL in the database schema. When a query (e.g. a
 * LEFT JOIN with no matching row) returns NULL for it, cloneResultMap() skips
 * the assignment, leaving the typed property uninitialized. This model
 * exposes that edge-case via the getInvId() getter.
 *
 * @see https://github.com/phalcon/cphalcon/issues/15711
 */
class InvoicesTypedProperties extends Model
{
    public const STATUS_INACTIVE = 2;
    public const STATUS_PAID     = 1;
    public const STATUS_UNPAID   = 0;

    public int $inv_id;

    public ?int $inv_cst_id = null;

    public ?int $inv_status_flag = null;

    public ?string $inv_title = null;

    public ?float $inv_total = null;

    public ?string $inv_created_at = null;

    public function initialize(): void
    {
        $this->setSource('co_invoices');
    }

    public function getInvId(): int
    {
        return $this->inv_id;
    }

    public function getInvTitle(): ?string
    {
        return $this->inv_title;
    }

    public function setInvTitle(?string $title): void
    {
        $this->inv_title = $title;
    }
}