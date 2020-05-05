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

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Class Invoices
 *
 * @property int    $inv_id
 * @property int    $inv_cst_id
 * @property int    $inv_status_flag
 * @property string $inv_title
 * @property float  $inv_total
 * @property string $inv_created_at
 *
 * @method static Invoices findFirst($parameters = null)
 * @method static Model\Resultset\Simple|Invoices[] find($parameters = null)
 */
class Invoices extends Model
{
    public $inv_id;
    public $inv_cst_id;
    public $inv_status_flag;
    public $inv_title;
    public $inv_total;
    public $inv_created_at;

    private $secretValue;
    private $superSecret;

    public function initialize()
    {
        $this->setSource('co_invoices');

        $this->hasOne(
            'inv_cst_id',
            Customers::class,
            'cst_id',
            [
                'alias'    => 'customer',
                'reusable' => true,
            ]
        );
    }

    public function setSecretValue($value)
    {
        $this->secretValue = $value;
    }

    public function getSecretValue()
    {
        return $this->secretValue;
    }
}
