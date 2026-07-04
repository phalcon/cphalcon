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

class OrdersProductsRelations extends Model
{
    public function initialize()
    {
        $this->setSource('co_orders_x_products');

        $this->belongsTo(
            'oxp_prd_id',
            ProductsRelations::class,
            'prd_id',
            [
                'foreignKey' => true,
            ]
        );

        $this->belongsTo(
            'oxp_ord_id',
            OrdersRelations::class,
            'ord_id',
            [
                'foreignKey' => [
                    'message' => 'The order does not exist',
                ],
            ]
        );
    }
}
