<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models;

use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;

/**
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
            [
                'alias' => 'details',
            ]
        );
    }
}
