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
 * Class Objects
 */
class ObjectsWithColumnMap extends Objects
{
    public function initialize()
    {
        $this->setSource('objects');
        $this->keepSnapshots(true);
    }

    public function columnMap()
    {
        return [
            'obj_id'    => 'theId',
            'obj_name'  => 'theName',
            'obj_type'  => 'theType'
        ];
    }
}
