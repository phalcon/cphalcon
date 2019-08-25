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

class PackageDetails extends Model
{
    public $reference_type_id;
    public $reference_id;
    public $type;
    public $value;
    public $created;
    public $updated;
    public $deleted;
}
