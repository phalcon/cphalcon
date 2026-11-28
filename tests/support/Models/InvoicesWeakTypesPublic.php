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
 * Model with public typed properties and no setters. The ORM writes the
 * properties directly. Used to test the weak type checks of the ORM.
 */
class InvoicesWeakTypesPublic extends Model
{
    public $inv_created_at;
    public int $inv_cst_id = 0;
    public ?int $inv_id = null;
    public ?bool $inv_status_flag = null;
    public ?string $inv_title = null;
    public ?float $inv_total = null;

    public function initialize(): void
    {
        $this->setSource('co_invoices');

        $this->belongsTo(
            'inv_cst_id',
            Customers::class,
            'cst_id',
            [
                'alias' => 'customer',
            ]
        );
    }
}
