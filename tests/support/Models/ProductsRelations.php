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

class ProductsRelations extends Model
{
    public function initialize()
    {
        $this->setSource('co_products');

        $this->hasMany(
            'prd_id',
            OrdersProductsRelations::class,
            'oxp_prd_id',
            [
                'foreignKey' => [
                    'message' => 'Products cannot be deleted because it is referenced by an Order',
                ],
            ]
        );

        $this->hasOneThrough(
            'prd_id',
            OrdersProductsRelations::class,
            'oxp_prd_id',
            'oxp_ord_id',
            OrdersRelations::class,
            'ord_id',
            [
                'alias' => 'oneOrder',
            ]
        );
    }
}
