<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;

/**
 * \Phalcon\Test\Models\Packages
 *
 * @copyright (c) 2011-2017 Phalcon Team
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
 * @method static Packages[] find($parameters = null)
 * @method Resultset|PackageDetails getDetails($parameters = null)
 * @property Resultset|PackageDetails details
 */
class Packages extends Model
{
    public $reference_type_id;
    public $reference_id;
    public $title;
    public $created;
    public $updated;
    public $deleted;

    public function initialize()
    {
        $this->hasMany(
            ['reference_id', 'reference_type_id'],
            PackageDetails::class,
            ['reference_id', 'reference_type_id'],
            ['alias' => 'details']
        );
    }
}
