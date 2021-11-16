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

class Robots2 extends Model
{
    protected $myname;

    public function initialize()
    {
        $this->setSource('robots');
    }

    public function getName()
    {
        return $this->myname;
    }

    public function columnMap()
    {
        return [
            'id'       => 'id',
            'name'     => 'myname',
            'type'     => 'type',
            'year'     => 'year',
            'datetime' => 'datetime',
            'deleted'  => 'deleted',
            'text'     => 'text',
        ];
    }
}
