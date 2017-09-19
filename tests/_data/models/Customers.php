<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset\Simple;

/**
 * \Phalcon\Test\Models\Customers
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 *
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
    private $private_field;

    public function initialize()
    {
        $this->hasOne('customer_id', Users::class, 'id', ['alias' => 'user', 'reusable' => true]);
    }
}
