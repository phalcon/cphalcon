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
 * Class Objects
 */
class Objects extends Model
{
    public $obj_id;
    public $obj_name;
    public $obj_type;
}
