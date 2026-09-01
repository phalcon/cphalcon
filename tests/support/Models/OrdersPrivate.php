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
 * Class OrdersPrivate
 *
 * Uses the private schema intermediate model for cross-schema relation tests.
 *
 * @property int    $ord_id;
 * @property string $ord_name;
 */
class OrdersPrivate extends Model
{
    public $ord_id;
    public $ord_name;

    public function initialize()
    {
        $this->setSource('co_orders');

        $this->hasManyToMany(
            'ord_id',
            OrdersProductsPrivate::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'products'
            ]
        );

        $this->hasOneThrough(
            'ord_id',
            OrdersProductsPrivate::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'singleProduct'
            ]
        );
    }
}