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

class OrdersRelations extends Model
{
    public function initialize()
    {
        $this->setSource('co_orders');

        $this->hasMany(
            'ord_id',
            OrdersProductsRelations::class,
            'oxp_ord_id',
            [
                'foreignKey' => true,
            ]
        );

        $this->hasManyToMany(
            'ord_id',
            OrdersProductsRelations::class,
            'oxp_ord_id',
            'oxp_prd_id',
            ProductsRelations::class,
            'prd_id'
        );
    }
}
