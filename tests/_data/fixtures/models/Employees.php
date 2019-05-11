<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * Class Employees
 *
 * @package Phalcon\Test\Models
 *
 * @property int    $empId;
 * @property string $empNameFirst;
 * @property string $empNameLast;
 * @property string $empCreatedDate;
 * @property int    $empCreatedEmpId;
 */
class Employees extends Model
{

    public function initialize()
    {
        $this->setSource("co_employees");
    }
}
