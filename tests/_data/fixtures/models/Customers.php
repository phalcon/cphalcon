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
 * Class Customers
 *
 * @property int    $cst_id
 * @property int    $cst_status_flag
 * @property string $cst_name_last
 * @property string $cst_name_first
 * @property array  $cst_data;
 */
class Customers extends Model
{
    public $cst_id;
    public $cst_status_flag;
    public $cst_name_last;
    public $cst_name_first;

    /** Not in schema */
    public $cst_data;

    public function initialize()
    {
        $this->setSource('co_customers');

        $this->hasMany(
            'cst_id',
            Invoices::class,
            'inv_cst_id',
            [
                'alias'      => 'invoices',
                'reusable'   => true,
                'foreignKey' => [
                    'action' => Model\Relation::NO_ACTION
                ]
            ]
        );

        $this->hasMany(
            'cst_id',
            Invoices::class,
            'inv_cst_id',
            [
                'alias'      => 'camelCaseInvoices',
                'reusable'   => false,
                'foreignKey' => [
                    'action' => Model\Relation::NO_ACTION
                ]
            ]
        );

        $this->hasMany(
            'cst_id',
            Invoices::class,
            'inv_cst_id',
            [
                'alias'      => 'paidInvoices',
                'reusable'   => true,
                'foreignKey' => [
                    'action' => Model\Relation::ACTION_CASCADE
                ],
                'params'     => [
                    'inv_status_flag = :paid:',
                    'bind' => [
                        'paid' => Invoices::STATUS_PAID
                    ]
                ]
            ]
        );

        $this->hasMany(
            'cst_id',
            Invoices::class,
            'inv_cst_id',
            [
                'alias'      => 'unpaidInvoices',
                'reusable'   => true,
                'foreignKey' => [
                    'action' => Model\Relation::NO_ACTION
                ],
                'params'     => function () {
                    return [
                        'inv_status_flag = :unpaid:',
                        'bind' => [
                            'unpaid' => Invoices::STATUS_UNPAID
                        ]
                    ];
                }
            ]
        );

        $this->hasMany(
            'cst_id',
            Invoices::class,
            'inv_cst_id',
            [
                'alias'      => 'inactiveInvoices',
                'reusable'   => true,
                'foreignKey' => [
                    'action' => Model\Relation::ACTION_RESTRICT
                ],
                'params'     => function () {
                    return [
                        'inv_status_flag = :inactive:',
                        'bind' => [
                            'inactive' => Invoices::STATUS_INACTIVE
                        ]
                    ];
                }
            ]
        );
    }

    /**
     * @return int
     */
    public function getId()
    {
        return $this->cst_id;
    }

    /**
     * @param int $id
     */
    public function setId(int $id)
    {
        $this->cst_id = $id;
    }

    /**
     * @return array
     */
    public function getData(): array
    {
        return $this->cst_data;
    }

    /**
     * @param array $data
     */
    public function setData(array $data)
    {
        $this->cst_data = $data;
    }

    /**
     * @return string
     */
    public function getFirstName(): string
    {
        return $this->cst_name_first;
    }

    /**
     * @param string $firstName
     */
    public function setFirstName(string $firstName)
    {
        $this->cst_name_first = $firstName;
    }
}
