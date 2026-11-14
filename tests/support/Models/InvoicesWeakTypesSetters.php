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

namespace Phalcon\Tests\Support\Models;

use Phalcon\Mvc\Model;

/**
 * Model with protected typed properties and typed setters. The ORM calls the
 * setters. Used to test the weak type checks of the ORM.
 */
class InvoicesWeakTypesSetters extends Model
{
    public $inv_created_at;
    protected int $inv_cst_id = 0;
    protected ?int $inv_id = null;
    protected ?bool $inv_status_flag = null;
    protected ?string $inv_title = null;
    protected ?float $inv_total = null;

    public function initialize(): void
    {
        $this->setSource('co_invoices');
    }

    public function setInvCstId(int $value): static
    {
        $this->inv_cst_id = $value;

        return $this;
    }

    public function setInvId(?int $value): static
    {
        $this->inv_id = $value;

        return $this;
    }

    public function setInvStatusFlag(?bool $value): static
    {
        $this->inv_status_flag = $value;

        return $this;
    }

    public function setInvTitle(?string $value): static
    {
        $this->inv_title = $value;

        return $this;
    }

    public function setInvTotal(?float $value): static
    {
        $this->inv_total = $value;

        return $this;
    }
}
