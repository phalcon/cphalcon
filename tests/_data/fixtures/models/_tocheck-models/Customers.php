<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * @method static Simple|Customers[] find($parameters = null)
 * @property Simple|Users $user
 */
class Customers extends Model
{
    public $id;
    public $document_id;
    public $customer_id;
    public $first_name;
    public $last_name;
    public $phone;
    public $email;
    public $instructions;
    public $status;
    public $birth_date;
    public $credit_line;
    public $created_at;

    protected $protected_field;
    private   $private_field;

    public function initialize()
    {
        $this->hasOne(
            'customer_id',
            Users::class,
            'id',
            [
                'alias'    => 'user',
                'reusable' => true,
            ]
        );
    }
}
