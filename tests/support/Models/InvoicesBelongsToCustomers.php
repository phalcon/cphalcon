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
 * Model used to verify that setting a belongsTo relation to null after calling
 * the getter correctly clears the cached related record, so that save() does
 * not overwrite the FK back to its previous value.
 *
 * @see https://github.com/phalcon/cphalcon/issues/16611
 *
 * @property int|null $inv_id
 * @property int|null $inv_cst_id
 * @property int|null $inv_status_flag
 * @property string   $inv_title
 * @property float    $inv_total
 * @property string   $inv_created_at
 *
 * @method static static findFirst($parameters = null)
 */
class InvoicesBelongsToCustomers extends Model
{
    public ?int $inv_id           = null;
    public ?int $inv_cst_id       = null;
    public ?int $inv_status_flag  = null;
    public string $inv_title      = '';
    public float $inv_total       = 0.0;
    public string $inv_created_at = '';

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

    public function setCustomer(?Customers $customer): void
    {
        $this->customer = $customer;

        if ($customer === null) {
            $this->inv_cst_id = null;
        }
    }
}
