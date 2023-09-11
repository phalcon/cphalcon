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

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model;

/**
 * Class OrdersMultiple
 *
 * @property int    $ord_id;
 * @property string $ord_name;
 * @property int $ord_status_flag;
 */
class OrdersMultiple extends Model
{
    public function initialize()
    {
        $this->setSource('co_orders');

        /**
         * Compound Primary key intermediate relations
         */
        $this->hasManyToMany(
            ['ord_id', 'ord_status_flag'],
            OrdersProductsFieldsMultComp::class,
            ['oxp_ord_id', 'oxp_ord_status_flag'],
            ['oxp_prd_id', 'oxp_prd_status_flag'],
            Products::class,
            ['prd_id', 'prd_status_flag'],
            [
                'alias' => 'productsFieldsMultComp'
            ]
        );

        $this->hasOneThrough(
            ['ord_id', 'ord_status_flag'],
            OrdersProductsFieldsMultComp::class,
            ['oxp_ord_id', 'oxp_ord_status_flag'],
            ['oxp_prd_id', 'oxp_prd_status_flag'],
            Products::class,
            ['prd_id', 'prd_status_flag'],
            [
                'alias' => 'singleProductFieldsMultComp'
            ]
        );

        $this->hasManyToMany(
            'ord_id',
            OrdersProductsFieldsOneComp::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'productsFieldsOneComp'
            ]
        );

        $this->hasOneThrough(
            'ord_id',
            OrdersProductsFieldsOneComp::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'singleProductFieldsOneComp'
            ]
        );

        /**
         * Single primary key intermediate relation
         */
         $this->hasManyToMany(
            ['ord_id', 'ord_status_flag'],
            OrdersProductsFieldsMult::class,
            ['oxp_ord_id', 'oxp_ord_status_flag'],
            ['oxp_prd_id', 'oxp_prd_status_flag'],
            Products::class,
            ['prd_id', 'prd_status_flag'],
            [
                'alias' => 'productsFieldsMult'
            ]
        );

        $this->hasOneThrough(
            ['ord_id', 'ord_status_flag'],
            OrdersProductsFieldsMult::class,
            ['oxp_ord_id', 'oxp_ord_status_flag'],
            ['oxp_prd_id', 'oxp_prd_status_flag'],
            Products::class,
            ['prd_id', 'prd_status_flag'],
            [
                'alias' => 'singleProductFieldsMult'
            ]
        );

        $this->hasManyToMany(
            'ord_id',
            OrdersProductsFieldsOne::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'productsFieldsOne'
            ]
        );

        $this->hasOneThrough(
            'ord_id',
            OrdersProductsFieldsOne::class,
            'oxp_ord_id',
            'oxp_prd_id',
            Products::class,
            'prd_id',
            [
                'alias' => 'singleProductFieldsOne'
            ]
        );
    }
}
