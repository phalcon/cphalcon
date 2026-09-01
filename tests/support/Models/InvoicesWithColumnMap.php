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
 * Class InvoicesWithColumnMap
 *
 * Maps co_invoices columns with different property names to test column map functionality.
 *
 * @property int    $inv_id
 * @property int    $inv_cst_id
 * @property int    $inv_status_flag
 * @property string $inv_title
 * @property float  $inv_total
 * @property string $inv_created_at
 */
class InvoicesWithColumnMap extends Model
{
    public int $inv_id;
    public int $inv_cst_id;
    public int $inv_status_flag;
    public string $inv_title;
    public float $inv_total;
    public ?string $inv_created_at = null;

    public function initialize(): void
    {
        $this->setSource('co_invoices');
    }

    public function columnMap(): array
    {
        return [
            'inv_id'          => 'id',
            'inv_cst_id'      => 'customerId',
            'inv_status_flag' => 'status',
            'inv_title'       => 'title',
            'inv_total'       => 'total',
            'inv_created_at'  => 'createdAt',
        ];
    }
}

