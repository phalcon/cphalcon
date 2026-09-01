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
 * Model for testing RawValue bind params in PHQL INSERT/UPDATE.
 *
 * Uses typed properties so that PHP 8 coercion behavior is exercised,
 * and a nullable PK so that a fresh instance has no uninitialized typed int.
 *
 * @see https://github.com/phalcon/cphalcon/issues/15064
 */
class InvoicesRawValue extends Model
{
    public ?int $inv_id = null;

    public ?int $inv_cst_id = null;

    public ?int $inv_status_flag = null;

    public ?string $inv_title = null;

    public ?float $inv_total = null;

    public ?string $inv_created_at = null;

    public function initialize(): void
    {
        $this->setSource('co_invoices');
    }
}
